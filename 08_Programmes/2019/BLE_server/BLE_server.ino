#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <HardwareSerial.h>

#define SERVICE_UUID        "b9d4de40-44be-11e9-b210-d663bd873d93" //Unique, à changer pour chaque serveur. UUID de service
#define CHARACTERISTIC_UUID "b9d4e282-44be-11e9-b210-d663bd873d93" //Unique, à changer pour chaque serveur. UUID de commande
#define CHARACTERISTIC_BCK_UUID "861c92c2-4ef6-11e9-8647-d663bd873d93" //Unique, à changer pour chaque serveur. UUID de feedback
byte fallbackProperties[2] = {0};

BLECharacteristic *pCharacteristic; // Pointer to the controller input characteristic
BLECharacteristic *pCharacteristicBack; // Pointer to the feedback data characteristic
BLEServer *pServer; // Pointer to the server instance
uint8_t defaultInValues[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t defaultOutValues[2] = {0, 0};
uint8_t ctrlInput[9] = {0};
HardwareSerial outSer(0);
bool serBackChanged = false;
bool ctrlConnected = false;

class MyCallbacks : public BLEServerCallbacks {
  /*
   * 
   * @func onConnect Triggers on device connection. Changes connection interval to the shortest possible according to GATT standards.
   * @param BLEServer* target BLE server
   * @param esp_ble_gatts_cb_param_t* newly connected device
   * @return void
   * 
   */
    void onConnect(BLEServer* pServer, esp_ble_gatts_cb_param_t *param) {
      //Serial.println("Device connected");
      pServer->updateConnParams(param->connect.remote_bda,0x06, 0x07, 0, 10);
      ctrlConnected = true;
      //Serial.println("Successfully updated params");
    }

    /*
     * 
     * @func onDisconnect Triggered on device disconnection. Does nothing.
     * @param BLEServer* target BLE server
     * @return void
     * 
     */

    void onDisconnect(BLEServer* pServer) {
      //Serial.println("Device disconnected");
      ctrlConnected = false;
    }
};

class MyCtrlCharCallbacks : public BLECharacteristicCallbacks {

  /*
   * 
   * @func onWrite Triggered when a remote client writes into a characteristic hosted by the server. 
   * Outputs the received data to the writable buffer that gets transmitted upon request.
   * @param BLECharacteristic* target BLE GATT characteristic
   * @return void
   * 
   */
   
    void onWrite(BLECharacteristic* pChar) {
      //uint8_t ctrlInput[8] = {0};
      uint8_t* pCharData;
      //Serial.println(millis());
      pCharData = pChar->getData();
      //Serial.println(millis());
      for (int i = 0; i < 8; i++) {
        ctrlInput[i] = pCharData[i];
        //Serial.print(ctrlInput[i], BIN);
        //Serial.print("   ");
      }
     if (ctrlConnected) {
      ctrlInput[8] = 255;
     }
     else {
      ctrlInput[8] = 0;
     }
      //outSer.write(ctrlInput, 8);
      //Serial.println("");
      
    }
};

/*
 * 
 * @func setup Default arduino setup function. Sets up the serial towards controllable obect (SPI). Initializes the BLE server.
 * @param null
 * @return void
 * 
 */

void setup() {
  // put your setup code here, to run once:
  outSer.begin(115200, SERIAL_8N1);
  //outSer.setRxBufferSize(2);
  //Serial.begin(115200);
  //Serial.println("Starting BLE work!");

  BLEDevice::init("ESP1");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE
                    );
  pCharacteristic->setCallbacks(new MyCtrlCharCallbacks);
  pCharacteristic->setValue(defaultInValues, 8);
  pCharacteristicBack = pService->createCharacteristic(
                          CHARACTERISTIC_BCK_UUID,
                          BLECharacteristic::PROPERTY_READ |
                          BLECharacteristic::PROPERTY_WRITE
                        );

  pCharacteristicBack->setValue(defaultOutValues, 2);
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // set minimum connection interval to 6x1.25ms
  pAdvertising->setMaxPreferred(0x12); // set maximum connection interval to 10x1.25ms
  BLEDevice::startAdvertising();
  //Serial.println("Characteristic defined! Now you can read it in your phone!");
}

/*
 * 
 * @func loop Default arduino loop function. Takes care of checking the serial buffer for a data request in the form
 * of feedback data and sends the response over. Then transmits the feedback data to the remote client.
 * @param null
 * @return void
 * 
 */
 
void loop() {
  //Serial.println(millis());
  //Serial.println("loop");
  //while (outSer.available() < 2) {}
  //insert code for follow-up feedback
  if (outSer.available()>=2){
  outSer.readBytes(fallbackProperties, 2);
  outSer.write(ctrlInput,9);
  serBackChanged = true;
  }
  /*for (int i = 0; i < 2; i++) {
    //Serial.println(fallbackProperties[i]);
  }//*/
  if (serBackChanged) {
  pCharacteristicBack->setValue(fallbackProperties, 2);
  pCharacteristicBack->notify(0);
  }
}

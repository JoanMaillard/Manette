#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <HardwareSerial.h>

#define SERVICE_UUID        "b9d4de40-44be-11e9-b210-d663bd873d93"              //Unique, à changer pour chaque serveur. UUID de service A CHANGER
#define CHARACTERISTIC1_UUID "b9d4e282-44be-11e9-b210-d663bd873d93" //Unique, à changer pour chaque serveur. UUID de commande A CHANGER
#define CHARACTERISTIC2_UUID "861c92c2-4ef6-11e9-8647-d663bd873d93"   //Unique, à changer pour chaque serveur. UUID de feedback A CHANGER

BLECharacteristic *pCharacteristic1; // Pointer to the controller input characteristic
BLECharacteristic *pCharacteristic2;
BLEServer *pServer; // Pointer to the server instance
uint8_t defaultInValues[2] = {0, 0};
uint8_t ctrlInput[4] = {0};
HardwareSerial outSer(0);
bool serBackChanged = false;

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
    }
};

class MyCtrlCharCallbacksCtrl1 : public BLECharacteristicCallbacks {

  /*
   * 
   * @func onWrite Triggered when a remote client writes into a characteristic hosted by the server. 
   * Outputs the received data to the writable buffer that gets transmitted upon request.
   * @param BLECharacteristic* target BLE GATT characteristic
   * @return void
   * 
   */
   
    void onWrite(BLECharacteristic* pChar) {
      uint8_t* pCharData;
      pCharData = pChar->getData();
      for (byte i = 0; i < 2; i++) {
        ctrlInput[i] = pCharData[i];
      }
      
    }
};

class MyCtrlCharCallbacksCtrl2 : public BLECharacteristicCallbacks {

  /*
   * 
   * @func onWrite Triggered when a remote client writes into a characteristic hosted by the server. 
   * Outputs the received data to the writable buffer that gets transmitted upon request.
   * @param BLECharacteristic* target BLE GATT characteristic
   * @return void
   * 
   */
   
    void onWrite(BLECharacteristic* pChar) {
      uint8_t* pCharData;
      pCharData = pChar->getData();
      for (byte i = 0; i < 2; i++) {
        ctrlInput[i+2] = pCharData[i];
      }
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

  BLEDevice::init("ESP1");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyCallbacks());
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic1 = pService->createCharacteristic(
                      CHARACTERISTIC1_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE
                    );
  pCharacteristic1->setCallbacks(new MyCtrlCharCallbacksCtrl1);
  pCharacteristic1->setValue(defaultInValues, 2);
  pCharacteristic2 = pService->createCharacteristic(
                          CHARACTERISTIC2_UUID,
                          BLECharacteristic::PROPERTY_READ |
                          BLECharacteristic::PROPERTY_WRITE
                        );
  
  pCharacteristic2->setCallbacks(new MyCtrlCharCallbacksCtrl2);
  pCharacteristic2->setValue(defaultInValues, 2);
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
 * @func loop Default arduino loop function. Transmits controller data to Arduino Leonardo via serial.
 * @param null
 * @return void
 * 
 */
 
void loop() {
  if (outSer.read()==255) {
  outSer.write(ctrlInput,4);
  }
}

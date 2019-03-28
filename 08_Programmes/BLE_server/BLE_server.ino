#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <HardwareSerial.h>

#define SERVICE_UUID        "b9d4de40-44be-11e9-b210-d663bd873d93"
#define CHARACTERISTIC_UUID "b9d4e282-44be-11e9-b210-d663bd873d93"
#define CHARACTERISTIC_BCK_UUID "861c92c2-4ef6-11e9-8647-d663bd873d93"

BLECharacteristic *pCharacteristic;
BLECharacteristic *pCharacteristicBack;
uint8_t defaultInValues[8] = {0,0,0,0,0,0,0,0};
uint8_t defaultOutValues[2] = {0,0};
HardwareSerial outSer(2);

class MyCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer){
       Serial.println("Device connected");
  }

  void onDisconnect(BLEServer* pServer){
      Serial.println("Device disconnected");
  }
};

class MyCtrlCharCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic* pChar){
    uint8_t ctrlInput[8] = {0};
    uint8_t* pCharData;
    pCharData = pChar->getData();
    for (int i = 0; i<8; i++) {
      ctrlInput[i] = pCharData[i];
      Serial.print(ctrlInput[i], BIN);
      Serial.print("   ");
    }
    outSer.write(ctrlInput, 8);
    Serial.println("");
  }
};

void setup() { 
  // put your setup code here, to run once:
  outSer.begin(115200, SERIAL_8N1);
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("ESP1");
  BLEServer *pServer = BLEDevice::createServer();
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
  pAdvertising->setMinPreferred(0x12); // set maximum connection interval to 10x1.25ms
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  //byte fallbackProperties[2] = {0,0};
  //if (outSer.available() > 2) {
    //insert code for follow-up feedback
    //outSer.readBytes(fallbackProperties, 2);
  //}
  //pCharacteristicBack->setValue(fallbackProperties,2);
}

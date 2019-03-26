#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "b9d4de40-44be-11e9-b210-d663bd873d93"
#define CHARACTERISTIC_UUID "b9d4e282-44be-11e9-b210-d663bd873d93"
#define CHARACTERISTIC_BCK_UUID "861c92c2-4ef6-11e9-8647-d663bd873d93"

BLECharacteristic *pCharacteristic;
BLECharacteristic *pCharacteristicBack;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("Long name works now");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("Hello World says Neil");
  pCharacteristicBack = pService->createCharacteristic(
                                         CHARACTERISTIC_BCK_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristicBack->setValue("Yolo");
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinInterval(0x06);  // set minimum connection interval to 6x1.25ms
  pAdvertising->setMaxInterval(0x0A); // set maximum connection interval to 10x1.25ms
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(millis());
  Serial.println(pCharacteristic->getValue().c_str());
  //Serial.println(pCharacteristicBack->getValue().c_str());
}

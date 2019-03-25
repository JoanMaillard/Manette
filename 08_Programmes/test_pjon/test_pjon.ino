#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#define SERVICE_UUID        "b9d4de40-44be-11e9-b210-d663bd873d93"
#define CHARACTERISTIC_CTRL_UUID "b9d4e282-44be-11e9-b210-d663bd873d93"
#define CHARACTERISTIC_BCK_UUID "861c92c2-4ef6-11e9-8647-d663bd873d93"

bool doOnce = false;
bool deviceConnected = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void loop() {
  if (!doOnce) {
    BLEDevice::init("ESP1");

    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    BLEService *pService = pServer->createService(SERVICE_UUID);

    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                           CHARACTERISTIC_CTRL_UUID,
                                           BLECharacteristic::PROPERTY_READ |
                                           BLECharacteristic::PROPERTY_WRITE
                                         );
    BLECharacteristic *pCharacteristicBack = pService->createCharacteristic(
          CHARACTERISTIC_BCK_UUID,
          BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE
        );
    pCharacteristic->setValue("Hello World says Neil");
    pCharacteristicBack->setValue("Second characteristic");
    pService->start();

    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising ->addServiceUUID(SERVICE_UUID);
    pAdvertising ->start();
    Serial.println("Characteristics defined! Now you can read them in your phone!");
    doOnce = true;
  }
  std::string banana = pCharacteristic->readLocalValue();
  pCharacteristicBack->setValue("banana");
  Serial.println(banana.c_str());
}

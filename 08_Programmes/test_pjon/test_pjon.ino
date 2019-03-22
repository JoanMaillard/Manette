#include <PJON.h>
#include <PJONMaster.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BluetoothSerial.h>
#define PJON_MAX_DEVICES 10
#define PJON_MAX_PACKETS 1
#define PJON_PACKET_MAX_LENGTH 20
BluetoothSerial BTSerial;
uint8_t bus_id[] = {0,0,0,1};
PJONMaster<ThroughSerial> bus(bus_id);
#define SERVICE_UUID        "b9d4de40-44be-11e9-b210-d663bd873d93"
#define CHARACTERISTIC_UUID "b9d4e282-44be-11e9-b210-d663bd873d93"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BLEDevice::init("ESP1");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("Hello World says Neil");
  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
  bus.begin();
  bus.set_error(error_function);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void error_function(unsigned char code,  short unsigned int data, void *banana) {
  if (code == PJON_CONNECTION_LOST) {
    Serial.print("La connection a été perdue: CONNECTION LOST");
    Serial.println((uint8_t)bus.packets[data].content[0], DEC);
  }
  if (code == PJON_ID_ACQUISITION_FAIL) {
    Serial.print("La connection a été perdue: ID ACQUISITION FAIL");
    Serial.println(data,DEC);
  }
  if (code == PJON_DEVICES_BUFFER_FULL) {
    Serial.print("Master device's buffer is full with a length of ");
    Serial.println(data);
  }
}

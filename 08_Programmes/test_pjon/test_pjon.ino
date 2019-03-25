/*#include <PJON.h>
#include <PJONMaster.h>*/
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
/*#include <BluetoothSerial.h>
#define PJON_MAX_DEVICES 10
#define PJON_MAX_PACKETS 1
#define PJON_PACKET_MAX_LENGTH 20
BluetoothSerial BTSerial;
uint8_t bus_id[] = {0,0,0,1};
PJONMaster<ThroughSerial> bus(bus_id);*/
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
  /*BTSerial.register_callback(callback);
  BTSerial.begin("Net1");
  Serial.println("BTSerial enabled");
  bus.strategy.set_serial(&BTSerial);
  bus.set_communication_mode(PJON_HALF_DUPLEX);
  bus.begin();
    Serial.println("bus enabled");
  bus.set_error(error_function);
    Serial.println("error function set");*/
  }

/*void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
  if(event == ESP_SPP_SRV_OPEN_EVT){
    Serial.println("Client Connected");
  }
 
  if(event == ESP_SPP_CLOSE_EVT ){
    Serial.println("Client disconnected");
  }
}*/

void loop() {
  for (int i = 0; i < 10000; i++) {
    pCharacteristic->setValue(i);
  }
}

/*void error_function(unsigned char code,  short unsigned int data, void *banana) {
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
}*/

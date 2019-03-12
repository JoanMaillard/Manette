#include <PJON.h>
#include <PJONSlave.h>
#include <BLEDevice.h>
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
uint8_t bus_id[] = {0,0,0,1};
// The remote service we wish to connect to.
static BLEUUID serviceUUID("b9d4de40-44be-11e9-b210-d663bd873d93");
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("b9d4e282-44be-11e9-b210-d663bd873d93");
PJONSlave<ThroughSerial> bus(bus_id, PJON_NOT_ASSIGNED);

static BLEAddress *pServerAddress;
static boolean doConnect = false;
static boolean connected = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;

static void notifyCallback(
  BLERemoteCharacteristic* pBLERemoteCharacteristic,
  uint8_t* pData,
  size_t length,
  bool isNotify) {
    Serial.print("Notify callback for characteristic ");
    Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
    Serial.print(" of data length ");
    Serial.println(length);
}

bool connectToServer(BLEAddress pAddress) {
    Serial.print("Forming a connection to ");
    Serial.println(pAddress.toString().c_str());
    
    BLEClient*  pClient  = BLEDevice::createClient();
    Serial.println(" - Created client");

    // Connect to the remove BLE Server.
    pClient->connect(pAddress);
    Serial.println(" - Connected to server");

    // Obtain a reference to the service we are after in the remote BLE server.
    BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
    if (pRemoteService == nullptr) {
      Serial.print("Failed to find our service UUID: ");
      Serial.println(serviceUUID.toString().c_str());
      return false;
    }
    Serial.println(" - Found our service");


    // Obtain a reference to the characteristic in the service of the remote BLE server.
    pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
    if (pRemoteCharacteristic == nullptr) {
      Serial.print("Failed to find our characteristic UUID: ");
      Serial.println(charUUID.toString().c_str());
      return false;
    }
    Serial.println(" - Found our characteristic");

    // Read the value of the characteristic.
    std::string value = pRemoteCharacteristic->readValue();
    Serial.print("The characteristic value was: ");
    Serial.println(value.c_str());

    pRemoteCharacteristic->registerForNotify(notifyCallback);
    return true;
}

/**
 * Scan for BLE servers and find the first one that advertises the service we are looking for.
 */
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
 /**
   * Called for each advertising BLE server.
   */
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    Serial.print("BLE Advertised Device found: ");
    Serial.println(advertisedDevice.toString().c_str());

    // We have found a device, let us now see if it contains the service we are looking for.
    if (advertisedDevice.haveServiceUUID() && advertisedDevice.getServiceUUID().equals(serviceUUID)) {

      // 
      Serial.print("Found our device!  address: "); 
      advertisedDevice.getScan()->stop();

      pServerAddress = new BLEAddress(advertisedDevice.getAddress());
      doConnect = true;

    } // Found our server
  } // onResult
}; // MyAdvertisedDeviceCallbacks

void setup() {
  // put your setup code here, to run once:
  Serial.println("Starting Arduino BLE Client application...");
  BLEDevice::init("");

  // Retrieve a Scanner and set the callback we want to use to be informed when we
  // have detected a new device.  Specify that we want active scanning and start the
  // scan to run for 30 seconds.
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true);
  pBLEScan->start(30);
  
  Serial.begin(115200);
}

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_SRV_OPEN_EVT) {
    Serial.println("Client connected");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server with which we wish to connect.  Now we connect to it.  Once we are 
  // connected we set the connected flag to be true.
  // Also initializes the PJON link.
  if (doConnect == true) {
    if (connectToServer(*pServerAddress)) {
      Serial.println("We are now connected to the BLE Server.");
      connected = true;
      SerialBT.register_callback(callback);

      if (!SerialBT.begin("ESP32")) {
        Serial.println("An error occurred initializing BT link");
      }
      else {
        Serial.println("BT link initialized");
      }
      bus.acquire_id_master_slave();
      bus.set_error(error_handler);
      } else {
        Serial.println("We have failed to connect to the server; there is nothin more we will do.");
      }
    doConnect = false;
  }

  
}

void error_handler(unsigned char code,  short unsigned int data, void *banana) {
  // Standard PJON error
  if(code == PJON_CONNECTION_LOST) {
    Serial.print("Connection lost with device ");
    Serial.println((uint8_t)bus.packets[data].content[0], DEC);
  }
  // PJONSlave related errors
  if(code == PJON_ID_ACQUISITION_FAIL) {
    if(data == PJON_ID_ACQUIRE)
      Serial.println("Multi-master auto addressing procedure failed.");
    if(data == PJON_ID_CONFIRM)
      Serial.println("Master-slave id confirmation procedure failed.");
    if(data == PJON_ID_NEGATE)
      Serial.println("Master-slave id release procedure failed.");
    if(data == PJON_ID_REQUEST)
      Serial.println("Master-slave id request procedure failed.");
  }
}

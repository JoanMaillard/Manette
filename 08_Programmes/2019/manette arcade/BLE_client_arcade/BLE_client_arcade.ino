#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <HardwareSerial.h>

#define BUFFER_SIZE 2
#define WRITE_CONTROL 255

byte previousState = 0;

byte dataBuffer[BUFFER_SIZE];
HardwareSerial outSer(2);

// The remote service we wish to connect to.
static BLEUUID serviceUUID("b9d4de40-44be-11e9-b210-d663bd873d93"); //A faire matcher avec les UUID du serveur correspondant. UUID de service
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("b9d4e282-44be-11e9-b210-d663bd873d93"); //A faire matcher avec les UUID du serveur correspondant. UUID de commande

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;

/*
 * 
 * @func static notifyCallback callback notifier function for event handling (unused but necessary for the BLE client class to work)
 * @param null
 * @return void
 * 
 */

static void notifyCallback(
  BLERemoteCharacteristic* pBLERemoteCharacteristic,
  uint8_t* pData,
  size_t length,
  bool isNotify) {
}

class MyClientCallback : public BLEClientCallbacks {

/*
 * 
 * @func onConnect what happens when the client connects
 * @param BLEClient* pointer to the target client instance
 * @return void
 * 
 */
  
    void onConnect(BLEClient* pclient) {
      connected = true;
    }

/*
 * 
 * @func onDisconnect what happens when the client disconnects or loses connection
 * @param BLEClient* pointer to the target client instance
 * @return void
 * 
 */

    void onDisconnect(BLEClient* pclient) {
      connected = false;
    }
};

/*
 * 
 * @func connectToServer connect the client to the server
 * @param null
 * @return bool 
 * 
 */

bool connectToServer() {

  BLEClient*  pClient  = BLEDevice::createClient();

  pClient->setClientCallbacks(new MyClientCallback());

  // Connect to the remove BLE Server.
  pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)

  // Obtain a reference to the service we are after in the remote BLE server.
  BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
  if (pRemoteService == nullptr) {
    pClient->disconnect();
    return false;
  }
  //Serial.println(" - Found our service");


  // Obtain a reference to the characteristic in the service of the remote BLE server.
  pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
  if (pRemoteCharacteristic == nullptr) {
    pClient->disconnect();
    return false;
  }

  // Read the value of the characteristic.
  if (pRemoteCharacteristic->canRead()) {
    std::string value = pRemoteCharacteristic->readValue();
  }

  if (pRemoteCharacteristic->canNotify())
    pRemoteCharacteristic->registerForNotify(notifyCallback);

  connected = true;
  return true;
}
/**
   Scan for BLE servers and find the first one that advertises the service we are looking for.
*/
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    /**
        Called for each advertising BLE server.
    */

    /*
     * 
     * @func onResult
     * @param BLEAdvertisedDevice an advertised device found
     * @return void
     * 
     */
     
    void onResult(BLEAdvertisedDevice advertisedDevice) {

      // We have found a device, let us now see if it contains the service we are looking for.
      if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(serviceUUID)) {

        BLEDevice::getScan()->stop();
        myDevice = new BLEAdvertisedDevice(advertisedDevice);
        doConnect = true;
        doScan = true;

      } // Found our server
    } // onResult
}; // MyAdvertisedDeviceCallbacks

/*
 * 
 * @func setup default setup function for arduino
 * @param null
 * @return void
 * 
 */

void setup() {
  delay(1000);
  outSer.begin(115200, SERIAL_8N1);
  BLEDevice::init("");

  // Retrieve a Scanner and set the callback we want to use to be informed when we
  // have detected a new device.  Specify that we want active scanning and start the
  // scan to run for 5 seconds.
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setInterval(1349);
  pBLEScan->setWindow(449);
  pBLEScan->setActiveScan(true);
  pBLEScan->start(5, false);
  delay(1000);
} // End of setup.

/*
 * 
 * @func loop default loop function for arduino
 * @param null
 * @return void
 * 
 */

// This is the Arduino main loop function.
void loop() {
  // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server with which we wish to connect.  Now we connect to it.  Once we are
  // connected we set the connected flag to be true.
  if (doConnect == true) {
    if (connectToServer()) {

    } else {
    }
    doConnect = false;

  }

  if (connected) {

    outSer.write(WRITE_CONTROL); //signal inputs controller that the ESP is ready to read controller data
    while (outSer.available() < 8) {} //do nothing as long as not all the serial inputs are ready to be read
    outSer.readBytes(dataBuffer, BUFFER_SIZE); //read inputs from inputs controller and store into dataBuffer
    
    // Set the characteristic's value to be the array of bytes that is actually a string.
    pRemoteCharacteristic->writeValue(dataBuffer, BUFFER_SIZE, 0); //write inputs inside of dataBuffer to BT server
    
  } else if (doScan) {
    BLEDevice::getScan()->start(5, false);  // this is just example to start scan after disconnect, most likely there is better way to do it in arduino
  }
} // End of loop

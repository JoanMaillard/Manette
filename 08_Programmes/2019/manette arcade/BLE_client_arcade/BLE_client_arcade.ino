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
static BLEUUID serviceUUID("d8ecf00e-997a-11e9-a2a3-2a2ae2dbcce4"); //A faire matcher avec les UUID du serveur correspondant. UUID de service
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("d8ecf478-997a-11e9-a2a3-2a2ae2dbcce4"); //A faire matcher avec les UUID du serveur correspondant. UUID de commande

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLEAdvertisedDevice* myDevice;
unsigned long debouncer[14] = {0};
byte pinList[12] = {18,5,15,4,27,14,13,26,25,12,18,33};

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
  BLEDevice::init("");
  for (byte i = 0; i<12; i++) {
    pinMode(pinList[i],INPUT_PULLUP);
  }
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

   byte *mainData = getButtons();
    // Set the characteristic's value to be the array of bytes that is actually a string.
    pRemoteCharacteristic->writeValue(mainData, BUFFER_SIZE, 0); //write inputs inside of dataBuffer to BT server
    
  } else if (doScan) {
    BLEDevice::getScan()->start(5, false);  // this is just example to start scan after disconnect, most likely there is better way to do it in arduino
  }
} // End of loop

/*
 * 
 * @func getButtons Concatenates the button values
 * @param null
 * @return byte *
 * 
 */

byte * getButtons() { 
  byte outBuffer[2] = {0};
  for (byte i = 0; i<12; i++) {
    if (debounce(!digitalRead(pinList[i]), i)) {
      if (i < 8) {
        bitSet(outBuffer[0], i);
      }
      else {
        bitSet(outBuffer[1], i);
      }
    }
    else {
      if (i < 8) {
        bitClear(outBuffer[0], i);
      }
      else {
        bitClear(outBuffer[1], i);
      }
    }
  }
  return outBuffer;
}

/*
 * 
 * @func debounce debounce function for buttons, to avoid double presses on the hardware sie (10ms button press persistance)
 * @param bool button status (true if pressed)
 * @param byte button ID (starts at 0)
 * @return bool processed button status
 * 
 */
bool debounce(bool buttonStatus, byte buttonID) {
    if (buttonStatus) {
      debouncer[buttonID] = millis();
      return true;
    }
    else {
      if (debouncer[buttonID] + 10 > millis()) {
        return true;
      }
      else {
        return false;
      }
    }
}

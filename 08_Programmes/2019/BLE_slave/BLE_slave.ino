/*
 * 
 *      CODE INUTILISE, VEUILLEZ UTILISER LE CODE "BLE_client" !!!
 * 
 */

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <HardwareSerial.h>

#define BUFFER_SIZE 8
#define WRITE_CONTROL 255

byte dataBuffer[BUFFER_SIZE];
HardwareSerial outSer(2);

// The remote service we wish to connect to.
static BLEUUID serviceUUID("b9d4de40-44be-11e9-b210-d663bd873d93");
// The characteristic of the remote service we are interested in.
static BLEUUID    charUUID("b9d4e282-44be-11e9-b210-d663bd873d93");
static BLEUUID    backUUID("861c92c2-4ef6-11e9-8647-d663bd873d93");

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic* pRemoteCharacteristic;
static BLERemoteCharacteristic* pRemoteCharacteristicBack;
static BLEAdvertisedDevice* myDevice;

//uint8_t val[8] = {0,0,0,0,0,0,0,0};//*/
uint8_t retVal[2] = {0, 0}; //*/


static void notifyCallback(
  BLERemoteCharacteristic* pBLERemoteCharacteristic,
  uint8_t* pData,
  size_t length,
  bool isNotify) {
  //Serial.print("Notify callback for characteristic ");
  //Serial.print(pBLERemoteCharacteristic->getUUID().toString().c_str());
  //Serial.print(" of data length ");
  //Serial.println(length);
  //Serial.print("data: ");
  //Serial.println((char*)pData);
}

class MyClientCallback : public BLEClientCallbacks {
    void onConnect(BLEClient* pclient) {
    }

    void onDisconnect(BLEClient* pclient) {
      connected = false;
      //Serial.println("onDisconnect");
    }
};

bool connectToServer() {
  //Serial.print("Forming a connection to ");
  //Serial.println(myDevice->getAddress().toString().c_str());

  BLEClient*  pClient  = BLEDevice::createClient();
  //Serial.println(" - Created client");

  pClient->setClientCallbacks(new MyClientCallback());

  // Connect to the remove BLE Server.
  pClient->connect(myDevice);  // if you pass BLEAdvertisedDevice instead of address, it will be recognized type of peer device address (public or private)
  //Serial.println(" - Connected to server");

  // Obtain a reference to the service we are after in the remote BLE server.
  BLERemoteService* pRemoteService = pClient->getService(serviceUUID);
  if (pRemoteService == nullptr) {
    //Serial.print("Failed to find our service UUID: ");
    //Serial.println(serviceUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  //Serial.println(" - Found our service");


  // Obtain a reference to the characteristic in the service of the remote BLE server.
  pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
  pRemoteCharacteristicBack = pRemoteService->getCharacteristic(backUUID);
  if (pRemoteCharacteristic == nullptr) {
    //Serial.print("Failed to find our characteristic UUID: ");
    //Serial.println(charUUID.toString().c_str());
    pClient->disconnect();
    return false;
  }
  //Serial.println(" - Found our characteristic");

  // Read the value of the characteristic.
  if (pRemoteCharacteristic->canRead()) {
    std::string value = pRemoteCharacteristic->readValue();
    //Serial.print("The characteristic value was: ");
    //Serial.println(value.c_str());
  }
  if (pRemoteCharacteristicBack->canRead()) {
    std::string value = pRemoteCharacteristicBack->readValue();
  }

  if (pRemoteCharacteristic->canNotify())
    pRemoteCharacteristic->registerForNotify(notifyCallback);

  if (pRemoteCharacteristicBack->canNotify())
    pRemoteCharacteristicBack->registerForNotify(notifyCallback);

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
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      //Serial.print("BLE Advertised Device found: ");
      //Serial.println(advertisedDevice.toString().c_str());

      // We have found a device, let us now see if it contains the service we are looking for.
      if (advertisedDevice.haveServiceUUID() && advertisedDevice.isAdvertisingService(serviceUUID)) {

        BLEDevice::getScan()->stop();
        myDevice = new BLEAdvertisedDevice(advertisedDevice);
        doConnect = true;
        doScan = true;

      } // Found our server
    } // onResult
}; // MyAdvertisedDeviceCallbacks


void setup() {
  outSer.begin(115200, SERIAL_8N1);
  Serial.begin(115200);
  //pinMode(27, INPUT_PULLUP);
  //Serial.println("Starting Arduino BLE Client application...");
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
} // End of setup.


// This is the Arduino main loop function.
void loop() {
  // If the flag "doConnect" is true then we have scanned for and found the desired
  // BLE Server with which we wish to connect.  Now we connect to it.  Once we are
  // connected we set the connected flag to be true.
  if (doConnect == true) {
    if (connectToServer()) {
      //Serial.println("We are now connected to the BLE Server.");

    } else {
      //Serial.println("We have failed to connect to the server; there is nothin more we will do.");
    }
    doConnect = false;

  }

  if (connected) {
    std::string feedbackDataServ;
    uint8_t feedbackData[2] = {0, 0};
    //Serial.println(millis());

    outSer.write(WRITE_CONTROL); //signal inputs controller that the ESP is ready to read controller data
    while (outSer.available() < 8) {} //do nothing as long as not all the serial inputs are ready to be read
    outSer.readBytes(dataBuffer, BUFFER_SIZE); //read inputs from inputs controller and store into dataBuffer

    //for (int i = 0; i < 8; i++) {
    //Serial.print(dataBuffer[i]);
    //Serial.print("   ");
    // }
    //Serial.println("");


    // Set the characteristic's value to be the array of bytes that is actually a string.


    pRemoteCharacteristic->writeValue(dataBuffer, 8, 1); //write inputs inside of dataBuffer to BT server
    feedbackDataServ = pRemoteCharacteristicBack->readValue(); //read feedback data from server
   // Serial.println("read feedback data");
    for (byte i = 0; i < 2; i++) {
      feedbackData[i] = (uint8_t)feedbackDataServ[i];
      //Serial.print(feedbackData[i]);
      //Serial.print("  ");
    }
    //Serial.println(""); 
    //TODO:  Treat feedback data (screen, buzzer and so on)

    /*Serial.println(millis());
      Serial.println("----");//*/
  } else if (doScan) {
    BLEDevice::getScan()->start(5, false);  // this is just eample to start scan after disconnect, most likely there is better way to do it in arduino
  }

} // End of loop

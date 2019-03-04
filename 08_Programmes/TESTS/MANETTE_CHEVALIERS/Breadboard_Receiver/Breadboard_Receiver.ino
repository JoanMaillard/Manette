
#include <PJON.h> // you need to download the library PJON
#include <SoftwareSerial.h>
/***************************************************************************
List of pin used
***************************************************************************/
#define RxD 2
#define TxD 3
/***************************************************************************
   Define to where is adressed the first byte of the data sent
***************************************************************************/
#define joystick 1 //Pin A0 for x and A1 for y
#define bouton1 2

// <Strategy name> bus(selected device id)
PJON<ThroughSerial> bus(44);
SoftwareSerial blueToothSerial(RxD, TxD);

/***************************************************************************
Variables where the value are stored
***************************************************************************/
static int val_X;
static int val_Y;
static bool val_bouton1;

/***************************************************************************
Temporary variables
***************************************************************************/
unsigned char x1;
unsigned char x2;
unsigned char y1;
unsigned char y2;

bool change_joy = false;
bool change_bou1 = false;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW); // Initialize LED 13 to be off
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  Serial.begin(9600);
  blueToothSerial.begin(9600);
  //setupBlueToothConnection();
  
  bus.strategy.set_serial(&blueToothSerial); // Pass the Serial object you want to use for communication
  bus.begin();
  bus.set_receiver(receiver_function);  // Create a function to read the data
}
/***************************************************************************
   Function Name: receiver_function
   Description:  function where the data sent by the other arduno are readed
   Parameters: payload is an array of char containing the data
   Return:
***************************************************************************/
void receiver_function(uint8_t *payload, uint16_t length, const PJON_Packet_Info &packet_info) {
  /* Make use of the payload before sending something, the buffer where payload points to is
     overwritten when a new message is dispatched */
  
  switch (payload[0]) {
    case 1:
      x1 = payload[1];
      x2 = payload[2];
      val_X = (x1<<8|x2);
      y1 = payload[3];
      y2 = payload[4];
      val_Y = (y1<<8|y2);
      change_joy = true;
      break;
    case 2:
      if (payload[1] == 1) {
        val_bouton1 = false;
      }
      if (payload[1] == 2) {
        val_bouton1 = true;
      }
      change_bou1 = true;
      break;
  }
}

void loop() {
  bus.receive(); // Important to receive data

  // Show the new value of the joystick
  if (change_joy) {
    change_joy = !change_joy;
    Serial.print("X: ");
    Serial.print(val_X);
    Serial.print(" Y: ");
    Serial.println(val_Y);
  }

  // Show the new value of the button 1
  if (change_bou1) {
    change_bou1 = !change_bou1;
    Serial.print("Bouton 1: ");
    Serial.println(val_bouton1);
  }
}
/***************************************************************************
   Function Name: setupBlueToothConnection
   Description:  initilizing bluetooth connction
   Parameters:
   Return:
***************************************************************************/
void setupBlueToothConnection() {

  blueToothSerial.begin(9600);

  blueToothSerial.print("AT");
  delay(400);

  blueToothSerial.print("AT+DEFAULT");             // Restore all setup value to factory setup
  delay(2000);

  blueToothSerial.print("AT+AUTH1");             // Enable authentification
  delay(400);

  blueToothSerial.print("AT+NAMEMaster");    // set the bluetooth name as "SeeedBTSlave" ,the length of bluetooth name must less than 12 characters.
  delay(400);

  blueToothSerial.print("AT+ROLEM");             // set the bluetooth work in slave mode
  delay(400);



  blueToothSerial.print("AT+RESTART");//restart module to take effect
  delay(2000);//wait for module restart

  blueToothSerial.flush();

}

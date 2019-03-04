
#include <PJON.h> // you need to download the library PJON
#include <SoftwareSerial.h>


/***************************************************************************
   Define to where is adressed the first byte of the data sent
***************************************************************************/
#define joystick 1 //Pin A0 for x and A1 for y
#define bouton1 2

/***************************************************************************
   List of pin used
***************************************************************************/
#define RxD 2
#define TxD 3
#define joystick_X A0
#define joystick_Y A1
#define pin_bouton1 4
/***************************************************************************
Variables where the value are stored
***************************************************************************/
int val_joystick[2]; //[0]=X   [1]=Y // value of the joystick
int val_joystick_base[2]; //[0]=X   [1]=Y // value of the neutral state of the joystick
bool val_bouton1;

bool change_joystick = false;
bool change_bouton1 = false;
bool change = false;
bool bouton1_previous_state = true;
/***************************************************************************
Array of char who will be sent to the other arduino
***************************************************************************/
char to_send_joystick[5]; // [0] = joystick / [1] = first byte val_joystick[0] / [2] = second byte val_joystick[0]
                          // [3] = first byte val_joystick[1] / [4] = second byte val_joystick[1]
                          
char to_send_bouton1[2]; // [0] = bouton1 / [1] = first byte val_joystick[0]

// <Strategy name> bus(selected device id)
PJON<ThroughSerial> bus(45);

SoftwareSerial blueToothSerial(RxD, TxD);

void setup() {
  pinMode(pin_bouton1, INPUT_PULLUP);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);

  Serial.begin(9600);
  blueToothSerial.begin(9600);

  //setupBlueToothConnection();

  bus.strategy.set_serial(&blueToothSerial); // Pass the Serial object you want to use for communication
  bus.include_port(true, 8001); // Include custom port, Ports from 0 to 8000 are reserved to known protocols,
                                // ports from 8001 to 65535 are free for custom use cases
  bus.begin(); // Important

  val_joystick_base[0] = analogRead(joystick_X); //neutral state X
  val_joystick_base[1] = analogRead(joystick_Y); //neutral state Y
  // Fill the array
  to_send_joystick[0] = joystick;
  to_send_joystick[1] = highByte(val_joystick_base[0]);
  to_send_joystick[2] = lowByte(val_joystick_base[0]);
  to_send_joystick[3] = highByte(val_joystick_base[1]);
  to_send_joystick[4] = lowByte(val_joystick_base[1]);
  to_send_bouton1[0] = bouton1;
  to_send_bouton1[1] = 0;
}

void loop() {
  bus.update(); //never forget to call the update() function once per loop cycle
  /* Exemple
    bus.send_packet(
      44,             // Device id
      "3",            // Content
      1,              // Length
      0b00110110,     // Header
      0,              // Packet id
      8001            // Port
    );
  */
  //Check the value of the joystick
  val_joystick[0] = analogRead(joystick_X);
  val_joystick[1] = analogRead(joystick_Y);

  //Check if the axe X
  if (val_joystick[0] != val_joystick_base[0]) {
    to_send_joystick[1] = highByte(val_joystick[0]);
    to_send_joystick[2] = lowByte(val_joystick[0]);
    change_joystick = true;
    change = true;
  }

  //Check the axe Y
  if (val_joystick[1] != val_joystick_base[1]) {
    to_send_joystick[3] = highByte(val_joystick[1]);
    to_send_joystick[4] = lowByte(val_joystick[1]);
    change_joystick = true;
    change = true;
  }

  //Check the button
  if (digitalRead(pin_bouton1) == LOW && digitalRead(pin_bouton1) != bouton1_previous_state) {
    delay(10);
    val_bouton1 = true;
    to_send_bouton1[1] = 2;
    change_bouton1 = true;
    change = true;
    bouton1_previous_state = !bouton1_previous_state;
  } if (digitalRead(pin_bouton1) == HIGH && digitalRead(pin_bouton1) != bouton1_previous_state) {
    delay(10);
    val_bouton1 = false;
    to_send_bouton1[1] = 1;
    change_bouton1 = true;
    change = true;
    bouton1_previous_state = !bouton1_previous_state;
  }

  // If there is a new value, the new value will be sent
  if (change) {
    if (change_joystick) {
      bus.send_packet(
        44,             // Device id
        to_send_joystick, // Content
        5,             // Length
        0b00110110,   // Header
        0,              // Packet id
        8001            // Port
      );
    }
    if (change_bouton1) {
      bus.send_packet(
        44,             // Device id
        to_send_bouton1, // Content
        2,             // Length
        0b00110110,   // Header
        0,              // Packet id
        8001            // Port
      );
    }
    change_bouton1 = false;
    change_joystick = false;
    change = false;
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

  blueToothSerial.print("AT+AUTH1");             //
  delay(400);

  blueToothSerial.print("AT+NAMESlave");    // set the bluetooth name as "SeeedBTSlave" ,the length of bluetooth name must less than 12 characters.
  delay(400);

  blueToothSerial.print("AT+ROLES");             // set the bluetooth work in slave mode
  delay(400);



  blueToothSerial.print("AT+RESTART");//restart module to take effect
  delay(2000);//wait for module restart

  blueToothSerial.flush();

}

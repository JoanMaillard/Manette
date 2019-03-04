#include <PJON.h> // you need to download the library PJON
#include <SoftwareSerial.h>
/***************************************************************************
  List of pin used
***************************************************************************/
#define RxD 2
#define TxD 3
#define buzzer 8
#define damage 9
/***************************************************************************
   Define to where is adressed the first byte of the data sent
***************************************************************************/
#define joystick 1 //Pin A0 for x and A1 for y
#define bouton1 2
#define bouton2 3
#define bouton3 4
#define bouton4 5
#define mode_de_jeu 6

#define TRAME 0   //defini quel type de trame le programme doit traiter
//0 = une liste avec toutes les valeurs/1 = les valeurs sont traiter indpendamment des autres

// <Strategy name> bus(selected device id)
PJON<ThroughSerial> bus(44);
SoftwareSerial blueToothSerial(RxD, TxD);

/***************************************************************************
  Variables where the value are stored
***************************************************************************/
static int val_X;
static int val_Y;
static int val_bouton1;
static int val_bouton2;
static int val_bouton3;
static int val_bouton4;
static int val_mode;

static bool val_damage;
static bool etat_damage;
static bool change_damage;
char char_damage[2] = {1, 1};

bool change_joy = false;
bool change_bou1 = false;
bool change_bou2 = false;
bool change_bou3 = false;
bool change_bou4 = false;
bool change = false;

/***************************************************************************
  Temporary variables
***************************************************************************/
unsigned char x1;
unsigned char x2;
unsigned char y1;
unsigned char y2;

void setup() {
  // put your setup code here, to run once:

  pinMode(damage, INPUT_PULLUP);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  Serial.begin(9600);
  blueToothSerial.begin(9600);
  bus.strategy.set_serial(&blueToothSerial); // Pass the Serial object you want to use for communication
  bus.include_port(true, 8001); // Include custom port, Ports from 0 to 8000 are reserved to known protocols,
  // ports from 8001 to 65535 are free for custom use cases
  bus.set_synchronous_acknowledge(false);
  bus.begin();
  bus.set_receiver(receiver_function);  // Create a function to read the data
}

/***************************************************************************
   Function Name: receiver_function
   Description:  function where the data sent by the other arduino are readed
   Parameters: payload is an array of char containing the data
   Return:
***************************************************************************/
void receiver_function(uint8_t *payload, uint16_t length, const PJON_Packet_Info &packet_info) {
  /* Make use of the payload before sending something, the buffer where payload points to is
     overwritten when a new message is dispatched */

#if TRAME
  switch (payload[0]) {
    case 1:
      x1 = payload[1];
      x2 = payload[2];
      val_X = (x1 << 8 | x2);
      y1 = payload[3];
      y2 = payload[4];
      val_Y = (y1 << 8 | y2);
      change_joy = true;
      break;
    case 2:
      val_bouton1 = payload[1];
      change_bou1 = true;
      break;
    case 3:
      val_bouton2 = payload[1];
      change_bou2 = true;
      break;
    case 4:
      val_bouton3 = payload[1];
      change_bou3 = true;
      break;
    case 5:
      val_bouton4 = payload[1];
      change_bou4 = true;
      break;
    case 6:
      val_mode = payload[1];
      break;
  }
#else
  //Serial.println(payload[7]);
  x1 = payload[0];
  x2 = payload[1];
  if (val_X != (x1 << 8 | x2)) {
    val_X = (x1 << 8 | x2);
    change_joy = true;
  }
  y1 = payload[2];
  y2 = payload[3];
  if (val_Y != (y1 << 8 | y2)) {
    val_Y = (y1 << 8 | y2);
    change_joy = true;
  }
  if (val_bouton1 != payload[4]) {
    val_bouton1 = payload[4];
    change_bou1 = true;
  }
  if (val_bouton2 != payload[5]) {
    val_bouton2 = payload[5];
    change_bou2 = true;
  }
  if (val_bouton3 != payload[6]) {
    val_bouton3 = payload[6];
    change_bou3 = true;
  }
  if (val_bouton4 != payload[7]) {
    val_bouton4 = payload[7];
    change_bou4 = true;
  }
  if (val_mode != payload[8]) {
    val_mode = payload[8];
    Serial.print("mode: ");
    Serial.println(val_mode);
  }

#endif
}


void loop() {
  // put your main code here, to run repeatedly:
  bus.receive();
#if TRAME
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
  // Show the new value of the button 2
  if (change_bou2) {
    change_bou2 = !change_bou2;
    Serial.print("Bouton 2: ");
    Serial.println(val_bouton2);
  }
  // Show the new value of the button 3
  if (change_bou3) {
    change_bou3 = !change_bou3;
    Serial.print("Bouton 3: ");
    Serial.println(val_bouton3);
  }
  // Show the new value of the button 4
  if (change_bou4) {
    change_bou4 = !change_bou4;
    Serial.print("Bouton 4: ");
    Serial.println(val_bouton4);
  }
#else
  //Serial.println("ok2");
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
  // Show the new value of the button 2
  if (change_bou2) {
    change_bou2 = !change_bou2;
    Serial.print("Bouton 2: ");
    Serial.println(val_bouton2);
  }
  // Show the new value of the button 3
  if (change_bou3) {
    change_bou3 = !change_bou3;
    Serial.print("Bouton 3: ");
    Serial.println(val_bouton3);
  }
  // Show the new value of the button 4
  if (change_bou4) {
    change_bou4 = !change_bou4;
    Serial.print("Bouton 4: ");
    Serial.println(val_bouton4);
  }
#endif
}

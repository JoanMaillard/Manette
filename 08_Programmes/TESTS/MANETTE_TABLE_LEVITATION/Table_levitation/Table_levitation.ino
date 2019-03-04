/***************************************************************************
   Include the necessarty library
***************************************************************************/
#include <PJON.h> // you need to download the library PJON
#include <SoftwareSerial.h>

/***************************************************************************
   List of pin used
***************************************************************************/
// pin for the bluetooth communication
#define RxD 11 //il s'agit du pin 2 sur le shield mais à cause du mega il faut le relier au pin 11
#define TxD 3

//pin for the controller
#define joystick_X A0
#define joystick_Y A1
#define bouton_1 22
#define bouton_2 23
#define bouton_3 24
#define bouton_4 25

/***************************************************************************
   Define to where is adressed the first byte of the data sent
***************************************************************************/
#define joystick 1 //Pin A0 for x and A1 for y
#define bouton1 2
#define bouton2 3
#define bouton3 4
#define bouton4 5
#define mode_de_jeu 6

/***************************************************************************
  Variables where the value are stored
***************************************************************************/
static int val_joystick[2]; //[0]=X   [1]=Y // value of the joystick
static int val_joystick_base[2]; //[0]=X   [1]=Y // value of the neutral state of the joystick
static bool val_bouton1;
static bool val_bouton2;
static bool val_bouton3;
static bool val_bouton4;
static int incomingByte;

static bool change_joystick = false;
static bool change_bouton1 = false;
static bool change_bouton2 = false;
static bool change_bouton3 = false;
static bool change_bouton4 = false;
bool etat_bouton_1 = false;
bool etat_bouton_2 = false;
bool etat_bouton_3 = false;
bool etat_bouton_4 = false;

static bool change;
bool etat_change = false;

/***************************************************************************
  Array of char who will be sent to the other arduino
***************************************************************************/
namespace {
// name of namespace left empty --> this is the anonymous namespace
// now the IDE will not mess with our stuff

#define TRAME 0 //defini quel type de trame le programme doit traiter
//0 = une liste avec toutes les valeurs/1 = les valeurs sont traiter indpendamment des autres

#if TRAME
char to_send_joystick[5]; // [0] = joystick / [1] = first byte val_joystick[0] / [2] = second byte val_joystick[0]
// [3] = first byte val_joystick[1] / [4] = second byte val_joystick[1]
char to_send_bouton1[2] = {bouton1, 0}; // [0] = bouton1 / [1] = the state of the button
char to_send_bouton2[2] = {bouton2, 0}; // [0] = bouton2 / [1] = the state of the button
char to_send_bouton3[2] = {bouton3, 0}; // [0] = bouton3 / [1] = the state of the button
char to_send_bouton4[2] = {bouton4, 0}; // [0] = bouton4 / [1] = the state of the button
char to_send_mode[2] = {mode_de_jeu, 0};
#else
char to_send[9] = {0, 0, 0, 0, 1, 1, 1, 1, 1};
#endif
}

// <Strategy name> bus(selected device id)
PJON<ThroughSerial> bus(45);

SoftwareSerial blueToothSerial(RxD, TxD);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  blueToothSerial.begin(9600);
  //setupBlueToothConnection();
  bus.strategy.set_serial(&blueToothSerial); // Pass the Serial object you want to use for communication
  bus.include_port(true, 8001); // Include custom port, Ports from 0 to 8000 are reserved to known protocols,
  // ports from 8001 to 65535 are free for custom use cases
  bus.set_synchronous_acknowledge(false);
  bus.begin(); // Important

  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(bouton_1, INPUT_PULLUP);
  pinMode(bouton_2, INPUT_PULLUP);
  pinMode(bouton_3, INPUT_PULLUP);
  pinMode(bouton_4, INPUT_PULLUP);
  val_joystick_base[0] = analogRead(joystick_X); //neutral state X
  val_joystick_base[1] = analogRead(joystick_Y); //neutral state Y
  // Fill the array
#if TRAME
  to_send_joystick[0] = joystick;
  to_send_joystick[1] = highByte(val_joystick_base[0]);
  to_send_joystick[2] = lowByte(val_joystick_base[0]);
  to_send_joystick[3] = highByte(val_joystick_base[1]);
  to_send_joystick[4] = lowByte(val_joystick_base[1]);
#else
  to_send[0] = highByte(val_joystick_base[0]);
  to_send[1] = lowByte(val_joystick_base[0]);
  to_send[2] = highByte(val_joystick_base[1]);
  to_send[3] = lowByte(val_joystick_base[1]);
#endif
Serial.println("setup complete");
}

/***************************************************************************
   Function Name: bouton_pressed
   Description:  verifie si des boutons sont enclecher
                 detecteur de flon montant
   Parameters:
   Return:
***************************************************************************/
void bouton_pressed() {

  incomingByte = 0;

  if (digitalRead(bouton_1) == LOW) {
    delay(1);
    if (etat_bouton_1 == false) {
      //incomingByte = 57;
      val_bouton1 = true;
#if TRAME
      to_send_bouton1[1] = 2;
#else
      to_send[4] = 2;
#endif

      change_bouton1 = true;
    }
    etat_bouton_1 = true;
  } else {
    etat_bouton_1 = false;
    val_bouton1 = false;
#if TRAME
    to_send_bouton1[1] = 1;
#else
    to_send[4] = 1;
#endif


  }
  if (digitalRead(bouton_2) == LOW) {
    delay(1);
    if (etat_bouton_2 == false) {
      //incomingByte = 56;
      val_bouton2 = true;
#if TRAME
      to_send_bouton2[1] = 2;
#else
      to_send[5] = 2;
#endif

      change_bouton2 = true;
    }
    etat_bouton_2 = true;
  } else {
    etat_bouton_2 = false;
    val_bouton2 = false;
#if TRAME
    to_send_bouton2[1] = 1;
#else
    to_send[5] = 1;
#endif
  }
  if (digitalRead(bouton_3) == LOW) {
    delay(1);
    if (etat_bouton_3 == false) {
      //incomingByte = 55;
      val_bouton3 = true;
#if TRAME
      to_send_bouton3[1] = 2;
#else
      to_send[6] = 2;
#endif

      change_bouton3 = true;
    }
    etat_bouton_3 = true;
  } else {
    etat_bouton_3 = false;
    val_bouton3 = false;
#if TRAME
    to_send_bouton3[1] = 1;
#else
    to_send[6] = 1;
#endif
  }
  if (digitalRead(bouton_4) == LOW) {
    delay(1);
    if (etat_bouton_4 == false) {
      //incomingByte = 54;
      val_bouton4 = true;
#if TRAME
      to_send_bouton4[1] = 2;
#else
      to_send[7] = 2;
#endif

      change_bouton4 = true;
    }
    etat_bouton_4 = true;
  } else {
    etat_bouton_4 = false;
    val_bouton4 = false;
#if TRAME
    to_send_bouton4[1] = 1;
#else
    to_send[7] = 1;
#endif


  }
  if (etat_bouton_4 || etat_bouton_3 || etat_bouton_2 || etat_bouton_1) {
    if (!etat_change) {
      change = true;
    }
    etat_change = true;
  }
  else {
    etat_change = false;
    incomingByte = 0;
  }
  //Serial.print("button pressed: ");
  //Serial.println(incomingByte);
}

/***************************************************************************
   Function Name: check_joystick
   Description:  check the value of the joystick and store the news values
   Parameters:
   Return:
***************************************************************************/
void check_joystick() {
  //Check the value of the joystick
  val_joystick[0] = analogRead(joystick_X);
  val_joystick[1] = analogRead(joystick_Y);

  //Check if the axe X
  if (val_joystick[0] != val_joystick_base[0]) {
#if TRAME
    to_send_joystick[1] = highByte(val_joystick[0]);
    to_send_joystick[2] = lowByte(val_joystick[0]);
#else
    to_send[0] = highByte(val_joystick[0]);
    to_send[1] = lowByte(val_joystick[0]);
#endif

    change_joystick = true;
    change = true;
  }

  //Check the axe Y
  if (val_joystick[1] != val_joystick_base[1]) {
#if TRAME
    to_send_joystick[3] = highByte(val_joystick[1]);
    to_send_joystick[4] = lowByte(val_joystick[1]);
#else
    to_send[2] = highByte(val_joystick[1]);
    to_send[3] = lowByte(val_joystick[1]);
#endif

    change_joystick = true;
    change = true;
  }
}

/***************************************************************************
   Function Name: check_change
   Description:  verifie s'il y a eu un changement de valeur pour le joystick et les boutons
                 si oui alors il envoie les nouvelles informations
   Parameters:
   Return:
***************************************************************************/
void check_change() {
#if TRAME
  if (change_joystick) {
    
    change_joystick = false;
    bus.send_packet(44, to_send_joystick, 5);
  }
  if (change_bouton1) {
    
    change_bouton1 = false;
    bus.send_packet(44, to_send_bouton1, 2);
  }
  if (change_bouton2) {
    
    change_bouton2 = false;
    bus.send_packet(44, to_send_bouton2, 2);
  }
  if (change_bouton3) {
    
    change_bouton3 = false;
    bus.send_packet(44, to_send_bouton3, 2);
  }
  if (change_bouton4) {
    
    change_bouton4 = false;
    bus.send_packet(44, to_send_bouton4, 2);
  }
#else
  if (change) {

    change = false;
    bus.send_packet(44, to_send, 9);
  }
#endif

}

void loop() {
  // put your main code here, to run repeatedly:
  bus.update(); //never forget to call the update() function once per loop cycle to send info
  bouton_pressed();
  check_joystick();
  check_change();
}

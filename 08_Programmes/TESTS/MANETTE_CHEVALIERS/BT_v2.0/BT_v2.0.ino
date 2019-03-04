
/***************************************************************************
   Include the necessarty library
***************************************************************************/
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  // Arduino LCD library
#include <PJON.h> // you need to download the library PJON
#include <SoftwareSerial.h>

/***************************************************************************
   List of pin used
***************************************************************************/
// pin definition for the tft lcd screen on the Mega
#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8

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
#define buzzer 34

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
   Define to where is adressed the first byte of the data received
***************************************************************************/
#define damage 1

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
bool joystick_down = false;
bool joystick_up = false;

static bool change;
bool etat_change = false;


static bool damage_taken = false;
/***************************************************************************
  Variables to configure the bluetooth
***************************************************************************/
byte header = 0xAA;
byte test_header;
bool sucess = false;
bool first = true;
bool blu_done = false;
bool PComm = false;
bool pp = false;
#define waiting 3000

/***************************************************************************
  Other variables
***************************************************************************/
bool once = false;
bool firstTime = false;
static int menu = 1;
static int pos_menu = 0;
int last_pos_menu = pos_menu;
int mode_jeu;
static bool fin = false;

bool configHUD = false;
bool setupBluetooth = false;
static int countBluetooth = 0;
bool show_pic = false;
int nb_heartMax;
static int nb_heart;
int last_nb_heart;
bool etat_heart[5] = {false, false, false, false, false};

static bool shieldActived = false;
static bool shieldCooldown = false;
static bool setupShield = false;
#define SHIELD_TIME 5000
#define SHIELD_COOLDOWN 5000

static bool specialAttak = false;
static bool specialCooldown = false;
static bool setupSpecial = false;
#define SPECIAL_TIME 1000
#define SPECIAL_COOLDOWN 1000

/***************************************************************************
  Liste des timer
***************************************************************************/
unsigned long timer;
unsigned long timer_bluetooth = 0;
unsigned long timer_bluetooth2 = 0;
#define interval_bluetooth 1000
int interval_bluetooth2;
#define max_bluetooth 5
unsigned long timer_game;
unsigned long timerShield;
unsigned long timerSpecial;
unsigned long chrono;
double ecart = 1000;

static int minute;
static int seconde;
static unsigned long temps;
double m, s;
int m1, s1;

#define delay_Blu1 400
#define delay_Blu2 2000

/***************************************************************************
  Array of char who will be sent to the other arduino
***************************************************************************/
/*
  namespace {
  // name of namespace left empty --> this is the anonymous namespace
  // now the IDE will not mess with our stuff

  #define TRAME 0 //defini quel type de trame le programme doit traiter
  //0 = une liste avec toutes les valeurs
  //1 = les valeurs sont traiter indpendamment des autres

  #if TRAME // if TRAME = 1
  char to_send_joystick[5]; // [0] = joystick
  // [1] = first byte val_joystick[0] // [2] = second byte val_joystick[0]
  // [3] = first byte val_joystick[1] // [4] = second byte val_joystick[1]

  char to_send_bouton1[2] = {bouton1, 0};
  // [0] = bouton1 // [1] = the state of the button -> 2 if pressed, else 1

  char to_send_bouton2[2] = {bouton2, 0};
  // [0] = bouton2 // [1] = the state of the button -> 2 if pressed, else 1

  char to_send_bouton3[2] = {bouton3, 0};
  // [0] = bouton3 // [1] = the state of the button -> 2 if pressed, else 1

  char to_send_bouton4[2] = {bouton4, 0};
  // [0] = bouton4 // [1] = the state of the button -> 2 if pressed, else 1

  char to_send_mode[2] = {mode_de_jeu, 0};
  // [0] = mode_de_jeu // [1] = current menu on the arduino

  #else // if TRAME = 0
  char to_send[9] = {0, 0, 0, 0, 1, 1, 1, 1, 1};
  //[0,1] = value X from the joystick //[2,3] = value Y from the joystick
  //[4] = state of bouton 1 -> 2 if pressed, else 1
  //[5] = state of bouton 2 -> 2 if pressed, else 1
  //[6] = state of bouton 3 -> 2 if pressed, else 1
  //[7] = state of bouton 4 -> 2 if pressed, else 1
  //[8] = current menu of the arduino
  //menu: 1 = bluetooth / 2 = main menu / 3 = in game / 4 = pause / 5 = game over
  #endif
  }
*/
//NEW TRAME
char p0[6] = {0, 'P','a','u','s','e'};
char r0[8] = {0, 'R','e','s','t','a','r','t'};
char o0[5] = {0, 'O','v','e','r'};

char su1[9] = {1, 'S','h','i','e','l','d','U','p'};
char sd1[11] = {1, 'S','h','i','e','l','d','D','o','w','n'};
char sup1[10] = {1, 'S','p','e','c','i','a','l','U','p'};
char sdo1[12] = {1,'S','p','e','c','i','a','l','D','o','w','n'};

char x2[3] = {2};
char virgule2[2] = {2, ','};
char y2[3] = {2};
char joy2[8]={2,0,0,0,',',0,0,0};


char ll3[9] = {3, 'L','o','s','e','L','i','f','e'};
char gl3[9] = {3, 'G','a','i','n','L','i','f','e'};

TFT TFTscreen = TFT(lcd_cs, dc, rst);

// <Strategy name> bus(selected device id)
PJON<ThroughSerial> bus(45);

SoftwareSerial blueToothSerial(RxD, TxD);


// this variable represents the image to be drawn on screen
PImage menu1;
PImage connection;
PImage GameOver;
PImage heart;
PImage no_heart;
PImage shield;
PImage explo;
PImage note;
PImage nots;

/***************************************************************************
   Function Name: setup
   Description:
   Parameters:
   Return:
***************************************************************************/
void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  blueToothSerial.begin(9600);
  //setupBlueToothConnection();
  bus.strategy.set_serial(&blueToothSerial); // Pass the Serial object you want to use for communication
  bus.include_port(true, 8001); // Include custom port, Ports from 0 to 8000 are reserved to known protocols,
  // ports from 8001 to 65535 are free for custom use cases
  bus.set_synchronous_acknowledge(false);
  bus.begin(); // Important

  // initialize and clear the GLCD screen
  TFTscreen.begin();
  //TFTscreen.background(0, 0, 0);
  if (!SD.begin(sd_cs)) {
    //Serial.println(F("failed!"));
    return;
  }
  menu1 = TFTscreen.loadImage("blueapp.bmp");
  if (!menu1.isValid()) {
    //Serial.println(F("error while loading menu1.bmp"));
    return;
  }
  connection = TFTscreen.loadImage("app.bmp");
  if (!connection.isValid()) {
    //Serial.println(F("error while loading Sans titre.bmp"));
    return;
  }
  heart = TFTscreen.loadImage("heart.bmp");
  if (!heart.isValid()) {
    //Serial.println(F("error while loading Sans titre.bmp"));
    return;
  }
  no_heart = TFTscreen.loadImage("noheart.bmp");
  if (!no_heart.isValid()) {
    //Serial.println(F("error while loading noheart.bmp"));
    return;
  }
  shield = TFTscreen.loadImage("shield.bmp");
  if (!shield.isValid()) {
    //Serial.println(F("error while loading shieldon.bmp"));
    return;
  }
  nots = TFTscreen.loadImage("nots.bmp");
  if (!nots.isValid()) {
    //Serial.println(F("error while loading shieldof.bmp"));
    return;
  }
  note = TFTscreen.loadImage("note.bmp");
  if (!note.isValid()) {
    //Serial.println(F("error while loading shieldof.bmp"));
    return;
  }
  explo = TFTscreen.loadImage("explo.bmp");
  if (!explo.isValid()) {
    //Serial.println(F("error while loading shieldof.bmp"));
    return;
  }
  GameOver = TFTscreen.loadImage("go.bmp");
  if (!GameOver.isValid()) {
    //Serial.println(F("error while loading go.bmp"));
    return;
  }
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(bouton_1, INPUT_PULLUP);
  pinMode(bouton_2, INPUT_PULLUP);
  pinMode(bouton_3, INPUT_PULLUP);
  pinMode(bouton_4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  val_joystick_base[0] = analogRead(joystick_X); //neutral state X
  val_joystick_base[1] = analogRead(joystick_Y); //neutral state Y
  // Fill the array
  /*
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
    }
  */
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
        /*
          #if TRAME
          to_send_bouton1[1] = 2;
          #else
          to_send[4] = 2;
          #endif
        */
        change_bouton1 = true;
      }
      etat_bouton_1 = true;
    } else {
      etat_bouton_1 = false;
      val_bouton1 = false;
      /*
        #if TRAME
        to_send_bouton1[1] = 1;
        #else
        to_send[4] = 1;
        #endif
      */

    }
    if (digitalRead(bouton_2) == LOW) {
      delay(1);
      if (etat_bouton_2 == false) {
        //incomingByte = 56;
        val_bouton2 = true;
        /*
          #if TRAME
          to_send_bouton2[1] = 2;
          #else
          to_send[5] = 2;
          #endif
        */
        change_bouton2 = true;
      }
      etat_bouton_2 = true;
    } else {
      etat_bouton_2 = false;
      val_bouton2 = false;
      /*
        #if TRAME
        to_send_bouton2[1] = 1;
        #else
        to_send[5] = 1;
        #endif
      */
    }
    if (digitalRead(bouton_3) == LOW) {
      delay(1);
      if (etat_bouton_3 == false) {
        //incomingByte = 55;
        val_bouton3 = true;
        /*
          #if TRAME
          to_send_bouton3[1] = 2;
          #else
          to_send[6] = 2;
          #endif
        */
        change_bouton3 = true;
      }
      etat_bouton_3 = true;
    } else {
      etat_bouton_3 = false;
      val_bouton3 = false;
      /*
        #if TRAME
        to_send_bouton3[1] = 1;
        #else
        to_send[6] = 1;
        #endif
      */
    }
    if (digitalRead(bouton_4) == LOW) {
      delay(1);
      if (etat_bouton_4 == false) {
        //incomingByte = 54;
        val_bouton4 = true;
        /*
          #if TRAME
          to_send_bouton4[1] = 2;
          #else
          to_send[7] = 2;
          #endif
        */
        change_bouton4 = true;
      }
      etat_bouton_4 = true;
    } else {
      etat_bouton_4 = false;
      val_bouton4 = false;
      /*
        #if TRAME
        to_send_bouton4[1] = 1;
        #else
        to_send[7] = 1;
        #endif
      */

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
     Function Name: fonction_bouton
     Description:  selon les boutons presser, effectue diverses actions
     Parameters:
     Return:
  ***************************************************************************/

  void fonction_bouton() {

    //switch (incomingByte) {
    //case 57:
    if (val_bouton1) {
      if (menu == 2) {
        pos_menu--;
        if (pos_menu < 1) {
          pos_menu = 3;
        }
      }
      if (menu == 3) {
        if (!shieldCooldown && !shieldActived) {
          shieldActived = true;
          setupShield = true;
          timerShield = timer;
        }
      }
      if (menu == 4) {
        pos_menu--;
        if (pos_menu < 1) {
          pos_menu = 2;
        }
      }
      val_bouton1 = false;
    }
    //break;
    //case 56:
    if (val_bouton2) {
      if (menu == 2) {
        pos_menu++;
        if (pos_menu > 3) {
          pos_menu = 1;
        }
      }
      if (menu == 3) {
        if (!specialCooldown && !specialAttak) {
          specialAttak = true;
          setupSpecial = true;
          timerSpecial = timer;
        }
      }
      if (menu == 4) {
        pos_menu++;
        if (pos_menu > 2) {
          pos_menu = 1;
        }
      }
      val_bouton2 = false;
    }
    //break;
    //case 55:
    if (val_bouton3) {
      if (menu == 3) {
        /*
          if (shieldActived) {
          gainHeart();
          }
          else {
          looseHeart();
          }
        */
        damage_taken = true;
      }
      if (menu == 2 && pos_menu != 0) {
        menu = 3;
        mode_jeu = pos_menu;
        setupBluetooth = false;
        configHUD = false;
      }
      if (menu == 4) {
        if (pos_menu == 1) {
          menu = 3;
          configHUD = false;
          bus.send_packet(44, r0, 8);
        }
        if (pos_menu == 2) {
          menu = 2;
          setupBluetooth = false;
        }
      }
      val_bouton3 = false;
    }
    //break;
    //case 54:
    if (val_bouton4) {
      if (menu == 3) {
        menu = 4;
        setupBluetooth = false;
        //temps = temps - (chrono - timer_game);
      }
      if (menu == 5) {
        menu = 2;
        setupBluetooth = false;
      }
      val_bouton4 = false;
    }
    //break;
    //}
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

      /*
        #if TRAME
        to_send_joystick[1] = highByte(val_joystick[0]);
        to_send_joystick[2] = lowByte(val_joystick[0]);
        #else
        to_send[0] = highByte(val_joystick[0]);
        to_send[1] = lowByte(val_joystick[0]);
        #endif
      */
      char b[4];
      String str;
      str = String(analogRead(joystick_X));
      str.toCharArray(b, 4);
      joy2[1] = str[0]; joy2[2] = str[1]; joy2[3] = str[2];
      change_joystick = true;
      change = true;
    }

    //Check the axe Y
    if (val_joystick[1] != val_joystick_base[1]) {

      /*
        #if TRAME
        to_send_joystick[3] = highByte(val_joystick[1]);
        to_send_joystick[4] = lowByte(val_joystick[1]);
        #else
        to_send[2] = highByte(val_joystick[1]);
        to_send[3] = lowByte(val_joystick[1]);
        #endif
      */
      char b[4];
      String str;
      str = String(analogRead(joystick_Y));
      str.toCharArray(b, 4);
      joy2[5] = str[0]; joy2[6] = str[1]; joy2[7] = str[2];
      change_joystick = true;
      change = true;
    }
    if (menu == 2) {
      if (val_joystick[1] >= 530) {
        if (!joystick_up) {
          joystick_up = true;
          pos_menu--;
          if (pos_menu < 1) {
            pos_menu = 3;
          }
        }
      }
      else {
        joystick_up = false;
      }
      if (val_joystick[1] <= 490) {
        if (!joystick_down) {
          joystick_down = true;
          pos_menu++;
          if (pos_menu > 3) {
            pos_menu = 1;
          }
        }
      }
      else {
        joystick_down = false;
      }
    }
    if (menu == 4) {
      if (val_joystick[1] >= 530) {
        if (!joystick_up) {
          joystick_up = true;
          pos_menu--;
          if (pos_menu < 1) {
            pos_menu = 2;
          }
        }
      }
      else {
        joystick_up = false;
      }
      if (val_joystick[1] <= 490) {
        if (!joystick_down) {
          joystick_down = true;
          pos_menu++;
          if (pos_menu > 2) {
            pos_menu = 1;
          }
        }
      }
      else {
        joystick_down = false;
      }
    }
  }


  /*************************************************
     Ecrit du texte
   *************************************************/

  void drawText (int Size, int Color1, int Color2, int Color3, int PosX, int PosY, char text[])
  {
    TFTscreen.setTextSize(Size);
    TFTscreen.stroke(Color1, Color2, Color3);
    TFTscreen.text(text, PosX, PosY);
  }

  /***************************************************************************
     Function Name: check_change
     Description:  verifie s'il y a eu un changement de valeur
                   pour le joystick et les boutons
                   si oui alors il envoie les nouvelles informations
     Parameters:
     Return:
  ***************************************************************************/
  void check_change() {

    /*
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
    */
    if (change) {

        change = false;
        bus.send_packet(44, joy2, 8);
      }
  }

  /*************************************************
     Perte point de vie
   *************************************************/
  void looseHeart() {
    //take a heart, if the player is at 0 heart, it will launch the game-over screen
    nb_heart--;
    if (nb_heart == 0) {
      menu = 5;
      setupBluetooth = false;
    }
    //display the empty_heart on a heart
    if (last_nb_heart != nb_heart) {
      last_nb_heart = nb_heart;
      etat_heart[nb_heart] = false;
      TFTscreen.image(no_heart, 28 * (nb_heart) + 1, 1);
    }
  }

  /*************************************************
     Gain point de vie
   *************************************************/
  void gainHeart() {
    //give a heart then check if the player has too many heart
    nb_heart++;
    if (nb_heart >= nb_heartMax) {
      nb_heart = nb_heartMax;
    }
    //if the player can receive a heart it will diplay it on the screen
    if (last_nb_heart != nb_heart) {
      last_nb_heart = nb_heart;
      etat_heart[nb_heart - 1] = true;
      TFTscreen.image(heart, 28 * (nb_heart - 1) + 1, 1);
    }
  }

  /*************************************************
     Check damage
   *************************************************/
  void checkDamage() {
    if (damage_taken) {
      damage_taken = false;
      if (shieldActived) {
        gainHeart();
        bus.send_packet(44, gl3, 9);
      }
      else {
        looseHeart();
        bus.send_packet(44, ll3, 9);
      }
    }
  }
  /*************************************************
       Detail menu principal
     *************************************************/
  void detail_menu() {

    // set the stroke color to black
    TFTscreen.stroke(0, 0, 0);

    // set the fill color to black
    TFTscreen.fill(0, 0, 0);
    switch (last_pos_menu) {
      case 1:
        TFTscreen.rect(8, 8, 76, 18);
        drawText (2, 255, 255, 255, 10, 10, "MELEE");
        drawText(1, 0, 0, 0, 5, 75, "MELEE: Bataille contre le\n Minotaure, seul, avec ou\n contre d'autres chevalier\n n points de vie.");
        break;
      case 2:
        TFTscreen.rect(8, 28, 76, 18);
        drawText (2, 255, 255, 255, 10, 30, "JOUTE");
        drawText(1, 0, 0, 0, 5, 75, "JOUTE: Bataille contre un\n ou plusieurs chevaliers.\n n points de vie.");
        break;
      case 3:
        TFTscreen.rect(8, 48, 76, 18);
        drawText (2, 255, 255, 255, 10, 50, "DUEL");
        drawText(1, 0, 0, 0, 5, 75, "DUEL: un contre un,\n un seul point de vie.");
        break;
    }
    // set the stroke color to red
    TFTscreen.stroke(243, 70, 70);

    // set the fill color to red
    TFTscreen.fill(243, 70, 70);
    switch (pos_menu) {
      case 1:
        TFTscreen.rect(8, 8, 76, 18);
        drawText (2, 0, 0, 0, 10, 10, ">MELEE");
        drawText(1, 255, 255, 255, 5, 75, "MELEE: Bataille contre le\n Minotaure, seul, avec ou\n contre d'autres chevalier\n n points de vie.");
        break;
      case 2:
        TFTscreen.rect(8, 28, 76, 18);
        drawText (2, 0, 0, 0, 10, 30, ">JOUTE");
        drawText(1, 255, 255, 255, 5, 75, "JOUTE: Bataille contre un\n ou plusieurs chevaliers.\n n points de vie.");
        break;
      case 3:
        TFTscreen.rect(8, 48, 76, 18);
        drawText (2, 0, 0, 0, 10, 50, ">DUEL");
        drawText(1, 255, 255, 255, 5, 75, "DUEL: un contre un,\n un seul point de vie.");
        break;
    }
  }

  /*************************************************
     HUD
   *************************************************/
  void hud(int gameMode) {

    if (shieldActived) {

      
      if (setupShield) {
        bus.send_packet(44,su1,9);
        TFTscreen.image(nots, 19, 83);

        // set the stroke color to blue
        TFTscreen.stroke(0, 0, 255);

        // draw line
        TFTscreen.line(0, 0, 159, 0);
        TFTscreen.line(159, 0, 159, 127);
        TFTscreen.line(159, 127, 0, 127);
        TFTscreen.line(0, 127, 0, 0);
        setupShield = false;
      }
      if (timer - timerShield >= SHIELD_TIME) {
        bus.send_packet(44,sd1,11);
        shieldActived = false;
        shieldCooldown = true;

        // set the stroke color to black
        TFTscreen.stroke(0, 0, 0);

        // draw line
        TFTscreen.line(0, 0, 159, 0);
        TFTscreen.line(159, 0, 159, 127);
        TFTscreen.line(159, 127, 0, 127);
        TFTscreen.line(0, 127, 0, 0);
        timerShield = timer;
      }
    }
    if (shieldCooldown) {
      
      if (timer - timerShield >= SHIELD_COOLDOWN) {
        shieldCooldown = false;
        // set the stroke color to white
        TFTscreen.stroke(255, 255, 255);

        // set the fill color to white
        TFTscreen.fill(255, 255, 255);

        TFTscreen.rect(19, 83, 22, 22);
      }
    }
    if (specialAttak) {
      if (setupSpecial) {
        bus.send_packet(44,sup1,10);
        TFTscreen.image(note, 117, 87);
        // set the stroke color to red
        TFTscreen.stroke(255, 0, 0);

        // draw line
        TFTscreen.line(0, 0, 159, 0);
        TFTscreen.line(159, 0, 159, 127);
        TFTscreen.line(159, 127, 0, 127);
        TFTscreen.line(0, 127, 0, 0);
        setupSpecial = false;
      }
      if (timer - timerSpecial >= SPECIAL_TIME) {
        bus.send_packet(44,sdo1,12);
        specialAttak = false;
        specialCooldown = true;

        // set the stroke color to black
        TFTscreen.stroke(0, 0, 0);

        // draw line
        TFTscreen.line(0, 0, 159, 0);
        TFTscreen.line(159, 0, 159, 127);
        TFTscreen.line(159, 127, 0, 127);
        TFTscreen.line(0, 127, 0, 0);
        timerSpecial = timer;
      }
    }
    if (timer - timerSpecial >= SPECIAL_COOLDOWN) {
      specialCooldown = false;
      // set the stroke color to black
      TFTscreen.stroke(0, 0, 0);

      // set the fill color to black
      TFTscreen.fill(0, 0, 0);

      TFTscreen.rect(117, 87, 21, 21);
    }
    if (fin) {
      menu = 5;
      setupBluetooth = false;
    }
    /*

    */
  }

  /*************************************************
     Detail menu pause
   *************************************************/
  void detail_pause() {

    // set the stroke color to black
    TFTscreen.stroke(0, 0, 0);

    // set the fill color to black
    TFTscreen.fill(0, 0, 0);
    switch (last_pos_menu) {
      case 1:
        TFTscreen.rect(8, 28, 124, 18);
        drawText (2, 255, 255, 255, 10, 30, "REPRENDRE");
        break;
      case 2:
        TFTscreen.rect(8, 48, 124, 18);
        drawText (2, 255, 255, 255, 10, 50, "QUITTER");
        break;
    }
    // set the stroke color to red
    TFTscreen.stroke(243, 70, 70);

    // set the fill color to red
    TFTscreen.fill(243, 70, 70);
    switch (pos_menu) {
      case 1:
        TFTscreen.rect(8, 28, 124, 18);
        drawText (2, 0, 0, 0, 10, 30, ">REPRENDRE");
        break;
      case 2:
        TFTscreen.rect(8, 48, 124, 18);
        drawText (2, 0, 0, 0, 10, 50, ">QUITTER");
        break;
    }
  }

  /***************************************************************************
     Function Name: conversion
     Description:  convert an integer into a character array,
                   then display it on the screen
     Parameters: the integer to convert, the position X on the screen and the color
     Return: nothing
  ***************************************************************************/
  void conversion(int taille2, int color, int placeX, int placeY, int toConvert) {
    char b[6];
    String str;
    str = String(toConvert);
    str.toCharArray(b, 6);
    drawText(taille2, color, color, color, placeX, placeY, b);
  }

  /*************************************************
    Chronometre
  *************************************************/
  void chronometre() {
    chrono = millis();
    //Serial.println(temps);

    if (chrono >= ecart + timer_game) {
      ecart = ecart + 1000;
      //lastChrono = chrono;
      //Serial.println(ecart);
      if (menu == 3) {
        conversion(2, 0, 82, 42, seconde);
        seconde--;
        if (seconde < 0) {
          seconde = 59;
          conversion(2, 0, 64, 42, minute);
          minute--;
          conversion(2, 255, 64, 42, minute);
        }
        conversion(2, 255, 82, 42, seconde);
      }
      if (menu == 4) {
        conversion(1, 0, 139, 8, seconde);
        seconde--;
        if (seconde < 0) {
          seconde = 59;
          conversion(1, 0, 121, 8, minute);
          minute--;
          conversion(1, 255, 121, 8, minute);
        }
        conversion(1, 255, 139, 8, seconde);
      }

      //Serial.println(seconde);

    }

    if (chrono - timer_game >= temps) {
      fin = true;
    }
  }

  /*************************************************
     Menu à afficher
   *************************************************/
  void mode_menu() {

    //TFTscreen.background(0, 0, 0);

    switch (menu) {
      case 1: //Appairage bluetooth
        if (!setupBluetooth) {
          blueToothSerial.begin(9600);
          /*
            #if TRAME
            to_send_mode[1] = 1;
            bus.send_packet(44, to_send_mode, 2);
            #else
            to_send[8] = 1;
            bus.send_packet(44, to_send, 9);
            #endif
          */
          TFTscreen.background(255, 255, 255);
          TFTscreen.image(menu1, 37, 48);
          setupBluetooth = true;
          timer_bluetooth = timer;
          firstTime = true;
          timer_bluetooth2 = timer;
        }
        configBluetooth();
        menu = 2;
        setupBluetooth = false;
        break;
      case 2: //Menu principal
        if (!setupBluetooth) {

          /*
            #if TRAME
            to_send_mode[1] = 2;
            bus.send_packet(44, to_send_mode, 2);
            #else
            to_send[8] = 2;
            bus.send_packet(44, to_send, 9);
            #endif
          */
          setupBluetooth = true;
          TFTscreen.background(0, 0, 0);
          pos_menu = 0;
          last_pos_menu = 0;
          drawText (1, 255, 255, 255, 0, 0, "Main menu");
          drawText (2, 255, 255, 255, 10, 10, "MELEE");
          drawText (2, 255, 255, 255, 10, 30, "JOUTE");
          drawText (2, 255, 255, 255, 10, 50, "DUEL");

          // set the stroke color to white
          TFTscreen.stroke(255, 255, 255);

          // draw a line
          TFTscreen.line(0, 70, 160, 70);
        }
        else {
          bouton_pressed();
          fonction_bouton();
          check_joystick();
          if (last_pos_menu != pos_menu) {
            detail_menu();
            last_pos_menu = pos_menu;
          }
        }
        break;
      case 3: //HUD
        if (!setupBluetooth) {
          setupBluetooth = true;
          for (int j = 0; j < sizeof(etat_heart) / sizeof(bool); j++) {
            etat_heart[j] = false;
          }
          if (mode_jeu == 3) {
            nb_heartMax = 1;
            nb_heart = 1;
            etat_heart[0] = true;
          }
          else {
            nb_heartMax = 5;
            nb_heart = 5;
            for (int i = 0; i < sizeof(etat_heart) / sizeof(bool); i++) {
              etat_heart[i] = true;
            }
          }
          last_nb_heart = nb_heart;

          minute = 3;
          seconde = 0;
          temps = 60 * minute + seconde;
          chrono = millis();
          timer_game = chrono;
          //lastChrono = chrono;
          temps = temps * 1000;
          ecart = 1000;
        }
        if (!configHUD) {

          /*
            #if TRAME
            to_send_mode[1] = 3;
            bus.send_packet(44, to_send_mode, 2);
            #else
            to_send[8] = 3;
            bus.send_packet(44, to_send, 9);
            #endif
          */
          if (mode_jeu == 1) {
            temps = 60 * minute + seconde;
            chrono = millis();
            timer_game = chrono;
            //lastChrono = chrono;
            temps = temps * 1000;
            ecart = 1000;
          }
          configHUD = true;
          TFTscreen.background(0, 0, 0);
          conversion(2, 255, 64, 42, minute);
          conversion(2, 255, 82, 42, seconde);
          //drawText(1, 255, 255, 255, 121, 8, "03");
          drawText(2, 255, 255, 255, 73, 42, ":");
          //drawText(1, 255, 255, 255, 139, 8, "00");

          TFTscreen.image(shield, 2, 62);
          TFTscreen.image(explo, 98, 68);
          for (int k = 0; k < sizeof(etat_heart) / sizeof(bool); k++) {
            if (etat_heart[k]) {
              TFTscreen.image(heart, k * 28 + 1, 1);
            }
            if (!etat_heart[k] && mode_jeu != 3) {
              TFTscreen.image(no_heart, k * 28 + 1, 1);
            }
          }
        }
        bouton_pressed();
        fonction_bouton();
        check_joystick();
        check_change();
        while (blueToothSerial.available() > 0) {
          Serial.println("ok");
          char c = blueToothSerial.read();
          damage_taken = true;
        }
        checkDamage();
        chronometre();
        hud(mode_jeu);
        break;
      case 4: //Pause
        if (!setupBluetooth) {

          /*
            #if TRAME
            to_send_mode[1] = 4;
            bus.send_packet(44, to_send_mode, 2);
            #else
            to_send[8] = 4;
            bus.send_packet(44, to_send, 9);
            #endif
          */
          bus.send_packet(44, p0, 6);
          setupBluetooth = true;
          TFTscreen.background(0, 0, 0);
          pos_menu = 0;
          last_pos_menu = 0;
          drawText (1, 255, 255, 255, 0, 0, "Pause");
          drawText (2, 255, 255, 255, 10, 30, "REPRENDRE");
          drawText (2, 255, 255, 255, 10, 50, "QUITTER");
          conversion(1, 255, 121, 8, minute);
          conversion(1, 255, 139, 8, seconde);
          //drawText(1, 255, 255, 255, 121, 8, "03");
          drawText(1, 255, 255, 255, 129, 9, ":");
          //drawText(1, 255, 255, 255, 139, 8, "00");
        }
        else {
          bouton_pressed();
          fonction_bouton();
          check_joystick();
          if (mode_jeu != 1) {
            chronometre();
          }
          if (last_pos_menu != pos_menu) {
            detail_pause();
            last_pos_menu = pos_menu;
          }
          break;
        case 5: //Game Over
          if (!setupBluetooth) {

            /*
              #if TRAME
              to_send_mode[1] = 5;
              bus.send_packet(44, to_send_mode, 2);
              #else
              to_send[8] = 5;
              bus.send_packet(44, to_send, 9);
              #endif
            */
            bus.send_packet(44, o0, 5);
            TFTscreen.image(GameOver, 0, 0);
            setupBluetooth = true;
            fin = false;
          }
          bouton_pressed();
          fonction_bouton();
          break;
        }
    }
  }

  /*************************************************
     Function Name: Loop
     Description:  main code
     Parameters:
     Return:
   *************************************************/
  void loop() {

    // put your main code here, to run repeatedly:
    if (once) {
      bus.update(); //never forget to call the update() function once per loop cycle to send info
      //bus.receive();
    }
    else {
      once = true;
    }
    timer = millis();
    mode_menu();
  }

  /***************************************************************************
     Function Name: configBluetooth
     Description:  configure the bluetooth, check if the bluetooth shield is responding,
                   then check if communnication via PJON is free
     Parameters:
     Return:
  ***************************************************************************/
  void configBluetooth() {
    while (!PComm) {
      timer = millis();

      if (blu_done && !PComm) {
        if (!pp) {
          if (timer - timer_bluetooth2 >= waiting) {
            pp = true;
            bus.update();
            if (bus.send_packet(44, "All is ok?!", 11) == PJON_ACK) {
              //Serial.println("44 is ok!");
              PComm = true;
            }
          }
        }
        if (pp) {
          bus.update();
          if (bus.send_packet(44, "All is ok?!", 11) == PJON_ACK) {
            //Serial.println("44 is ok!");
            PComm = true;
          }
        }
      }
      if (!blu_done) {
        if (!sucess) {
          if (first || timer - timer_bluetooth2 >= waiting) {
            //Serial.println("send");
            first = false;
            timer_bluetooth2 = timer;
            blueToothSerial.write(header);
          }
          if (blueToothSerial.available() > 0) {
            //Serial.println("receive");
            test_header = blueToothSerial.read();
            if (test_header == header) {
              sucess = true;
            }
          }
        }
        if (sucess) {
          //Serial.println("ok");
          //sucess = false;
          blu_done = true;
          first = true;
          timer_bluetooth2 = timer;
        }
      }
      if (timer - timer_bluetooth >= interval_bluetooth) {

        timer_bluetooth = timer;
        show_pic = !show_pic;
        //
        if (show_pic) {
          TFTscreen.image(connection, 69, 52);
          //countBluetooth++;
        } else {
          // set the fill color to white
          TFTscreen.fill(255, 255, 255);

          // draw a white box in the screen center
          TFTscreen.rect(69, 52, 20, 26);
        }
      }
    }
  }

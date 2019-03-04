#include <SD.h>
#include <TFT.h>  // Arduino LCD library
#include <SoftwareSerial.h> //librairie de protocole

//#include <SPI.h>

#include "CommunicationProtocol.h"
#include "Manette.h"


/*********** DEBUT BLUETOOTH ***********/
// pin for the bluetooth communication
#define RxD 11 //il s'agit du pin 2 sur le shield mais à cause du mega il faut le relier au pin 11
#define TxD 3

SoftwareSerial blueToothSerial(RxD, TxD); // Communication RX/TX vers le Shield Seeedstudio 2.x
CommunicationProtocol communicationProtocol;
int sendBlueToothCommand(char command[], int size = -1);
#define MASTER 1   //change th is macro to define the Bluetooth as Master or not BLUETOOTH -----------*/

String received = "";
char recvChar;
int sizeOfData = 0;
bool blueToothConnected = false;
/*-------------FIN BLUETOOTH-----------*/

/************* DEBUT ECRAN *************/
/*PINES ECRAN
   MOSI = 11
   MISO = 12
   SCK = 13
*/

#define sd_cs  4//4 sur nano
#define lcd_cs 10//10 sur nano
#define dc     9//9 sur nano
#define rst    8//8 sur nano

/*
  PImage heart;
  PImage noHeart;
  PImage shield;
  PImage gameOver;
*/
PImage menu1;
PImage connection;
PImage GameOver;
PImage heart;
PImage no_heart;
PImage shield;
PImage explo;
PImage note;
PImage nots;

TFT TFTscreen = TFT(lcd_cs, dc, rst);
/************** FIN ECRAN **************/

//Variables pour la fonciton Millis()
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
unsigned long currentTime = 0;
/***************************************************************************
   List of pin used
***************************************************************************/
#define joystick_X A0
#define joystick_Y A1
#define bouton_1 27
#define bouton_2 25
#define bouton_3 29
#define bouton_4 23
//#define buzzer 34
/***************************************************************************
   Buzzer
***************************************************************************/
#define bip1 440
#define bip2 880
#define longBip 1000
#define courtBip 500

/***************************************************************************
  Variables where the value are stored
***************************************************************************/
static int val_joystick[2]; //[0]=X   [1]=Y // value of the joystick
static int val_joystick_base[2]; //[0]=X   [1]=Y // value of the neutral state of the joystick
static bool val_bouton1;
static bool val_bouton2;
static bool val_bouton3;
static bool val_bouton4;
//static int incomingByte;

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
  Other variables
***************************************************************************/
bool once = false;
bool firstTime = false;
static int menu = 2;
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
#define SHIELD_TIME 1500
#define SHIELD_COOLDOWN 5000

static bool specialAttak = false;
static bool specialCooldown = false;
static bool setupSpecial = false;
#define SPECIAL_TIME 1000
#define SPECIAL_COOLDOWN 5000

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
//Variables concernant le joystick

//Déclaration du tableau d'envoi de données
int sendBlue[6];
int i = 0;
//Variables d'interface

//Variables pour SD
char recv_str[100];

/*********** CLASSE MANETTE ***********/
Manette manette;
/*-------------FIN MANETTE-----------*/

void setup() {

  //Serial.begin(9600);

  /*********** DEBUT BLUETOOTH ***********/
  blueToothSerial.begin(38400);
  blueToothSerial.print("AT");

  communicationProtocol.addSoftwareSerialBluetooth(&blueToothSerial);
  setupBlueToothConnection(); //initialize Bluetoothl
  /*-------------FIN BLUETOOTH-----------*/

  /*********** CLASSE MANETTE ***********/
  /**< On dit à Manette qu'il doit utiliser le communicationProtocol qu'on lui envoie en argument afin que les données soient envoyées par ce biais-là */
  manette.addCommunicationProtocolParent(&communicationProtocol);
  /**< On initialise la manette */
  manette.init();
  /*-------------FIN MANETTE-----------*/

  pinMode(bouton_1, INPUT_PULLUP);
  pinMode(bouton_2, INPUT_PULLUP);
  pinMode(bouton_3, INPUT_PULLUP);
  pinMode(bouton_4, INPUT_PULLUP);
  //pinMode(buzzer, OUTPUT);

  val_joystick_base[0] = analogRead(joystick_X); //neutral state X
  val_joystick_base[1] = analogRead(joystick_Y); //neutral state Y

  // initialize the display
  TFTscreen.begin();
  // black background
  TFTscreen.background(0, 0, 0);
  // set the font color to white
  TFTscreen.stroke(0, 0, 0);

  if (!SD.begin(sd_cs))
  {
    //Serial.println("failed!");
    return;
  }
  //Je charge toute les images nécessaires
  menu1 = TFTscreen.loadImage("blueapp.bmp");
  connection = TFTscreen.loadImage("app.bmp");
  heart = TFTscreen.loadImage("heart.bmp");
  no_heart = TFTscreen.loadImage("noheart.bmp");
  shield = TFTscreen.loadImage("shield.bmp");
  nots = TFTscreen.loadImage("nots.bmp");
  note = TFTscreen.loadImage("note.bmp");
  explo = TFTscreen.loadImage("explo.bmp");
  GameOver = TFTscreen.loadImage("go.bmp");

  if (!heart.isValid())
  {
    //Serial.println("error while loading heart");
  }
  if (heart.isValid() == false)
  {
    return;
  }

}
/***************************************************************************
     Function Name: bouton_pressed
     Description:  verifie si des boutons sont enclecher
                   detecteur de flon montant
     Parameters:
     Return:
  ***************************************************************************/
void bouton_pressed() {

  //incomingByte = 0;

  if (digitalRead(bouton_1) == LOW) {
    delay(1);
    if (etat_bouton_1 == false) {
      //incomingByte = 57;
      val_bouton1 = true;

      change_bouton1 = true;
    }
    etat_bouton_1 = true;
  } else {
    etat_bouton_1 = false;
    val_bouton1 = false;


  }
  if (digitalRead(bouton_2) == LOW) {
    delay(1);
    if (etat_bouton_2 == false) {
      //incomingByte = 56;
      val_bouton2 = true;

      change_bouton2 = true;
    }
    etat_bouton_2 = true;
  } else {
    etat_bouton_2 = false;
    val_bouton2 = false;

  }
  if (digitalRead(bouton_3) == LOW) {
    delay(1);
    if (etat_bouton_3 == false) {
      //incomingByte = 55;
      val_bouton3 = true;

      change_bouton3 = true;
    }
    etat_bouton_3 = true;
  } else {
    etat_bouton_3 = false;
    val_bouton3 = false;

  }
  if (digitalRead(bouton_4) == LOW) {
    delay(1);
    if (etat_bouton_4 == false) {
      //incomingByte = 54;
      val_bouton4 = true;

      change_bouton4 = true;
    }
    etat_bouton_4 = true;
  } else {
    etat_bouton_4 = false;
    val_bouton4 = false;


  }
  if (etat_bouton_4 || etat_bouton_3 || etat_bouton_2 || etat_bouton_1) {
    if (!etat_change) {
      change = true;
    }
    etat_change = true;
  }
  else {
    etat_change = false;
    //incomingByte = 0;
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
    manette.sendJoystickPosition(val_joystick[0], val_joystick[1]);
    change_joystick = true;
    change = true;
  }

  //Check the axe Y
  if (val_joystick[1] != val_joystick_base[1]) {
    manette.sendJoystickPosition(val_joystick[0], val_joystick[1]);
    change_joystick = true;
    change = true;
  }
  if (menu == 2) {
    if (val_joystick[1] >= 800) {
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
    if (val_joystick[1] <= 300) {
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
    if (val_joystick[1] >= 800) {
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
    if (val_joystick[1] <= 300) {
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

/*************************************************
     Perte point de vie
   *************************************************/
void loseHeart() {
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
      //noTone(buzzer);
      //tone(buzzer,bip1,longBip);
      gainHeart();
    }
    else {
      //noTone(buzzer);
      //tone(buzzer,bip2,longBip);
      loseHeart();
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
      //noTone(buzzer);
      //tone(buzzer,bip1,courtBip);
      manette.sendActivateProtection();
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
      //noTone(buzzer);
      //tone(buzzer,bip2,courtBip);
      manette.sendDesactivateProtection();
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
      //noTone(buzzer);
      //tone(buzzer,bip1,courtBip);

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
      //noTone(buzzer);
      //tone(buzzer,bip2,courtBip);

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

        TFTscreen.background(255, 255, 255);
        TFTscreen.image(menu1, 37, 48);
        setupBluetooth = true;
        timer_bluetooth = timer;
        firstTime = true;
        timer_bluetooth2 = timer;
      }
      menu = 2;
      setupBluetooth = false;
      break;
    case 2: //Menu principal
      if (!setupBluetooth) {

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
          //noTone(buzzer);
          //tone(buzzer,bip2,courtBip);
          detail_menu();
          last_pos_menu = pos_menu;
        }
      }
      break;
    case 3: //HUD
      if (!setupBluetooth) {
        //noTone(buzzer);
        //tone(buzzer,bip1,courtBip);
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
        manette.sendRestartGame();
      }
      bouton_pressed();
      fonction_bouton();
      check_joystick();
      //checkDamage();
      chronometre();
      hud(mode_jeu);
      break;
    case 4: //Pause
      if (!setupBluetooth) {

        manette.sendPauseGame();
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
          manette.sendGameOver();
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
   Attendre reponse du shield Bluetooth
 *************************************************/
void waitResponseFromBluetooth() {
  manette.sendConnectionRequest();

  while (blueToothSerial.available()) {
    // On place le byte reçu par Bluetooth dans recvChar
    recvChar = blueToothSerial.read();
    //Serial.print("received: ");
    //Serial.println(recvChar);
    // On envoie ce byte à la classe CommunicationProtocol qui va s'occuper de décomposer tous les prochains bytes reçus jusqu'à la fin du message qui fera en sorte de renvoyer VRAI à communicationProtocol.isAvailable()
    communicationProtocol.parseBytePerByte(recvChar);
  }

  if (communicationProtocol.isAvailable() > 0)
  {
    sizeOfData      = communicationProtocol.getDataSize(); // On place la taille du message reçu dans size
    received        = communicationProtocol.getData(); // On place le message reçu dans received

    //Serial.println(received);
    switch (communicationProtocol.getLastPacketID())
    {
      case 0: // Game

        if (received == "OkConn") {
          blueToothConnected = true;
        }
        break;
    }
  }
}

void loop() {
  // Nous attendons que la connexion au Bluetooth se fasse
  while (!blueToothConnected)
  {
    waitResponseFromBluetooth();
    delay(100);
  }
  timer = millis();
  mode_menu();

  while (blueToothSerial.available()) {
    // On place le byte reçu par Bluetooth dans recvChar
    recvChar = blueToothSerial.read();
    // On envoie ce byte à la classe CommunicationProtocol qui va s'occuper de décomposer tous les prochains bytes reçus jusqu'à la fin du message qui fera en sorte de renvoyer VRAI à communicationProtocol.isAvailable()
    communicationProtocol.parseBytePerByte(recvChar);
  }

  if (communicationProtocol.isAvailable() > 0)
  {
    sizeOfData      = communicationProtocol.getDataSize(); // On place la taille du message reçu dans size
    received        = communicationProtocol.getData(); // On place le message reçu dans received

    switch (communicationProtocol.getLastPacketID())
    {
      case 1: // Contact
        //Serial.print("Something happened : ");
        //Serial.println(received);
        if (received == "LoseLife")
        {
          if (menu == 3)
          {
            loseHeart();
          }
          // On renvoie au Bluetooth comme quoi on a bien reçu LoseLife
        }
        else if (received == "GainLife")
        {
          //Serial.println("gain life");
          gainHeart();
          // On renvoie au Bluetooth comme quoi on a bien reçu GainLife
        }
        break;
    }
  }
  delay(1);
}

//used for compare two string, return 0 if one equals to each other
int strcmp(char *a, char *b)
{
  unsigned int ptr = 0;
  while (a[ptr] != '\0')
  {
    if (a[ptr] != b[ptr]) return -1;
    ptr++;
  }
  return 0;
}

//configure the Bluetooth through AT commands
int setupBlueToothConnection()
{
#if MASTER
  //Serial.println("this is MASTER\r\n");
#else
  //Serial.println("this is SLAVE\r\n");
#endif

  //Serial.print("Setting up Bluetooth link\r\n");
  delay(2000);//wait for module restart


  //wait until Bluetooth was found
  /*while (1)
    {
    //Serial.println("AT test");
    if (sendBlueToothCommand("AT") == 0)
    {
      if (strcmp((char *)recv_str, (char *)"OK") == 0)
      {
        //Serial.println("Bluetooth exists\r\n");
        //break;
      }
    }
    delay(500);
    }*/

  sendBlueToothCommand("AT");//restore factory configurations

  //configure the Bluetooth
  sendBlueToothCommand("AT+DEFAULT");//restore factory configurations
  delay(2000);
  sendBlueToothCommand("AT+CLEAR");
  delay(1000);
  sendBlueToothCommand("AT+AUTH1");//enable authentication
  delay(1000);
  sendBlueToothCommand("AT+PIN1984");//set password
  delay(1000);
  sendBlueToothCommand("AT+NOTI1");
  delay(1000);

  sendBlueToothCommand("AT+BAUD6");
  delay(400);



  //set role according to the macro
#if MASTER
  sendBlueToothCommand("AT+ROLEM");//set to master mode
  delay(1000);
  sendBlueToothCommand("AT+NAMEDragonM");//set name
  delay(2000);
#else
  sendBlueToothCommand("AT+ROLES");//set to slave mode
  delay(1000);
  sendBlueToothCommand("AT+NAMEDragonS");//set name
  delay(1000);
#endif
  sendBlueToothCommand("AT+RESTART");//restart module to take effect
  delay(2000);//wait for module restart

  //check if the Bluetooth always exists
  sendBlueToothCommand("AT");
  delay(1000);
  return 0;
}


//send command to Bluetooth and return if there is a response received
int sendBlueToothCommand(char command[], int size = -1)
{
  //Serial.print("send: ");
  //Serial.print(command);
  //Serial.println("");

  if (size == -1)
    blueToothSerial.print(command);
  else
    blueToothSerial.write(command, size);

  delay(300);

  if (recvMsg(1000) != 0) return -1;

  Serial.print("recv: ");
  Serial.println(recv_str);

  return 0;
}

//receive message from Bluetooth with time out
int recvMsg(unsigned int timeout)
{
  //wait for feedback
  unsigned int time = 0;
  unsigned char num;
  unsigned char i;

  //waiting for the first character with time out
  i = 0;
  while (1)
  {
    delay(50);
    if (blueToothSerial.available())
    {
      recv_str[i] = char(blueToothSerial.read());
      i++;
      break;
    }
    time++;
    if (time > (timeout / 50)) return -1;
  }

  //read other characters from uart buffer to string
  while (blueToothSerial.available() && (i < 100))
  {
    recv_str[i] = char(blueToothSerial.read());
    i++;
  }
  recv_str[i] = '\0';

  return 0;
}


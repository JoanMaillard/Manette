
// include the necessary libraries
#include <SPI.h>
#include <SD.h>
#include <TFT.h>  // Arduino LCD library

// pin definition for the Mega
#define sd_cs  4
#define lcd_cs 10
#define dc     9
#define rst    8

#define bouton_1 7
#define bouton_2 6
#define bouton_3 5
#define bouton_4 3

static int incomingByte;
boolean etat_bouton_1 = false;
boolean etat_bouton_2 = false;
boolean etat_bouton_3 = false;
boolean etat_bouton_4 = false;

static bool change;
bool etat_change = false;

static int menu = 1;
static int pos_menu = 0;
int last_pos_menu = pos_menu;
int mode_jeu;
static bool fin = false;

bool configHUD = false;
bool setupBluetooth = false;
bool show_pic = false;
int nb_heartMax;
static int nb_heart;
int last_nb_heart;
bool etat_heart[4] = {false, false, false, false};

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

//Liste des timer
unsigned long timer;
unsigned long timer_bluetooth = 0;
#define interval_bluetooth 1000
#define max_bluetooth 5
unsigned long timer_game;
unsigned long timerShield;
unsigned long timerSpecial;
unsigned long chrono;
//unsigned long lastChrono;
double ecart = 1000;

static int minute;
static int seconde;
static unsigned long temps;
double m, s;
int m1, s1;


TFT TFTscreen = TFT(lcd_cs, dc, rst);

// this variable represents the image to be drawn on screen
PImage menu1;
PImage connection;
PImage GameOver;
PImage heart;
PImage no_heart;
PImage shield;
PImage explo;
PImage yesnt;


void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
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
  yesnt = TFTscreen.loadImage("not.bmp");
  if (!yesnt.isValid()) {
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
  pinMode(bouton_1, INPUT_PULLUP);
  pinMode(bouton_2, INPUT_PULLUP);
  pinMode(bouton_3, INPUT_PULLUP);
  pinMode(bouton_4, INPUT_PULLUP);
}

/*************************************************
   Pression des boutons
 *************************************************/

// attribue une valeur a incomingByte selon le bouton presse

void bouton_pressed() {

  incomingByte = 0;
  //unsigned long currentMillis=millis();
  if (digitalRead(bouton_1) == LOW) {
    delay(1);
    if (etat_bouton_1 == false) {
      incomingByte = 57;
    }
    etat_bouton_1 = true;
  } else {
    etat_bouton_1 = false;

  }
  if (digitalRead(bouton_2) == LOW) {
    delay(1);
    if (etat_bouton_2 == false) {
      incomingByte = 56;
    }
    etat_bouton_2 = true;
  } else {
    etat_bouton_2 = false;

  }
  if (digitalRead(bouton_3) == LOW) {
    delay(1);
    if (etat_bouton_3 == false) {
      incomingByte = 55;
    }
    etat_bouton_3 = true;
  } else {
    etat_bouton_3 = false;

  }
  if (digitalRead(bouton_4) == LOW) {
    delay(1);
    if (etat_bouton_4 == false) {
      incomingByte = 54;
    }
    etat_bouton_4 = true;
  } else {
    etat_bouton_4 = false;

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

/*************************************************
   Fonctions des boutons
 *************************************************/

void fonction_bouton() {

  switch (incomingByte) {
    case 57:
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
      break;
    case 56:
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
      break;
    case 55:
      if (menu == 3) {
        if (shieldActived) {
          gainHeart();
        }
        else {
          looseHeart();
        }
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
      break;
    case 54:
      if (menu == 3) {
        menu = 4;
        setupBluetooth = false;
        temps = temps - (chrono - timer_game);
      }
      if (menu == 5) {
        menu = 2;
        setupBluetooth = false;
      }
      break;
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

void looseHeart() {
  nb_heart--;
  if (nb_heart == 0) {
    menu = 5;
    setupBluetooth = false;
  }
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
  nb_heart++;
  if (nb_heart >= nb_heartMax) {
    nb_heart = nb_heartMax;
  }
  if (last_nb_heart != nb_heart) {
    last_nb_heart = nb_heart;
    etat_heart[nb_heart - 1] = true;
    TFTscreen.image(heart, 28 * (nb_heart - 1) + 1, 1);
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
      drawText(1, 0, 0, 0, 5, 75, "MELEE: Bataille contre le\n Minotaure, \n 4 points de vie.");
      break;
    case 2:
      TFTscreen.rect(8, 28, 76, 18);
      drawText (2, 255, 255, 255, 10, 30, "JOUTE");
      drawText(1, 0, 0, 0, 5, 75, "JOUTE: Tous contre tous,\n nombre de joueurs\n illimite. 4 points de vie.");
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
      drawText(1, 255, 255, 255, 5, 75, "MELEE: Bataille contre le\n Minotaure, \n 4 points de vie.");
      break;
    case 2:
      TFTscreen.rect(8, 28, 76, 18);
      drawText (2, 0, 0, 0, 10, 30, ">JOUTE");
      drawText(1, 255, 255, 255, 5, 75, "JOUTE: Tous contre tous,\n nombre de joueurs\n illimite. 4 points de vie.");
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
      TFTscreen.image(yesnt, 12, 102);

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
      TFTscreen.image(shield, 2, 94);
    }
  }
  if (specialAttak) {
    if (setupSpecial) {
      TFTscreen.image(yesnt, 135, 104);
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
    TFTscreen.image(explo, 125, 94);
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

void conversion(int toConvert, int place, int color) {
  char b[6];
  String str;
  str = String(toConvert);
  str.toCharArray(b, 6);
  drawText(1, color, color, color, place, 8, b);
}

/*************************************************
  Chronometre
*************************************************/

void chronometre() {
  chrono = millis();
  //Serial.println(temps);

  if (chrono /*- lastChrono*/ >= ecart + timer_game) {
    ecart = ecart + 1000;
    //lastChrono = chrono;
    Serial.println(ecart);
    conversion(seconde,139,0);
    seconde--;
    if(seconde<0){
      seconde=59;
      conversion(minute, 121, 0);
      minute--;
      conversion(minute, 121, 255);
    }
    /*
    conversion(m1, 121, 0);
    conversion(s1, 139, 0);

    unsigned long over, elapsed;
    m = int((chrono - timer_game) / 60000);
    over = (chrono - timer_game) % 60000;
    s = int(over / 1000);
    s1 = int(s);
    m1 = int(m);
    */
    conversion(seconde, 139, 255);
    //conversion (s1, 121,255);
    Serial.println(seconde);
    
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
  static int countBluetooth = 0;
  switch (menu) {
    case 1: //Appairage bluetooth
      if (!setupBluetooth) {
        TFTscreen.background(255, 255, 255);
        TFTscreen.image(menu1, 37, 48);
        setupBluetooth = true;
        timer_bluetooth = timer;
      }
      else {
        if (timer - timer_bluetooth >= interval_bluetooth) {
          // save the last time you blinked the LED
          timer_bluetooth = timer;
          show_pic = !show_pic;
          //
          if (show_pic) {
            TFTscreen.image(connection, 69, 52);
            countBluetooth++;
          } else {
            // set the fill color to white
            TFTscreen.fill(255, 255, 255);

            // draw a white box in the screen center
            TFTscreen.rect(69, 52, 20, 26);
          }
          if (countBluetooth == max_bluetooth) {
            menu = 2;
            setupBluetooth = false;
          }
        }
      }
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
          nb_heartMax = 4;
          nb_heart = 4;
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
        configHUD = true;
        TFTscreen.background(0, 0, 0);
        conversion(minute, 121, 255);
        conversion(seconde, 139, 255);
        //drawText(1, 255, 255, 255, 121, 8, "03");
        drawText(1, 255, 255, 255, 129, 9, ":");
        //drawText(1, 255, 255, 255, 139, 8, "00");

        TFTscreen.image(shield, 2, 94);
        TFTscreen.image(explo, 125, 94);
        for (int k = 0; k < sizeof(etat_heart) / sizeof(bool); k++) {
          if (etat_heart[k]) {
            TFTscreen.image(heart, k * 28 + 1, 1);
          }
          if (!etat_heart[k] && mode_jeu != 3) {
            TFTscreen.image(no_heart, k * 28 + 1, 1);
          }
        }
        //temps = chrono - temps;
        
      }
      bouton_pressed();
      fonction_bouton();
      chronometre();
      hud(mode_jeu);
      break;
    case 4: //Pause
      if (!setupBluetooth) {
        setupBluetooth = true;
        TFTscreen.background(0, 0, 0);
        pos_menu = 0;
        last_pos_menu = 0;
        drawText (1, 255, 255, 255, 0, 0, "Pause");
        drawText (2, 255, 255, 255, 10, 30, "REPRENDRE");
        drawText (2, 255, 255, 255, 10, 50, "QUITTER");
        conversion(minute, 121, 255);
        conversion(seconde, 139, 255);
        //drawText(1, 255, 255, 255, 121, 8, "03");
        drawText(1, 255, 255, 255, 129, 9, ":");
        //drawText(1, 255, 255, 255, 139, 8, "00");
      }
      else {
        bouton_pressed();
        fonction_bouton();
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
   Loop
 *************************************************/

void loop() {

  // put your main code here, to run repeatedly:
  timer = millis();
  mode_menu();
}

// Wire Master Writer

#include <Wire.h>
#include <Keyboard.h>

#define adresse 0x7F
byte header[2] = {0xAA, 0xAA};
static byte test_header[2];
static bool confirm_header = true;
static bool change = false;
int header_adresse;

void setup()
{
  //Serial.begin(9600);
  Wire.begin(adresse); // join i2c bus (address optional for master)
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);// request event
  Keyboard.begin();
}

//boolean Player[4] = {false, false, false, false};
boolean Player[2] = {false, false};
bool is_empty = false;
bool player_waiting = false;
int adresse_wait = 5;
static int nb_player = 0;
static int slave_adresse = 0;

static byte player1[2] = {0b00000000, 0b00000000};
static byte player2[2] = {0b00000000, 0b00000000};
//static byte player3[2] = {0b00000000, 0b00000000};
//static byte player4[2] = {0b00000000, 0b00000000};

static bool player_change1 = false;
static bool player_change2 = false;
//static bool player_change3 = false;
//static bool player_change4 = false;

const int debut_ascii = 21;
const int ahhhh = 12;
static int je_suis_perdu = 0;

void requestEvent()
{
  for (int i = 0; i < sizeof(Player) / sizeof(bool); i++)
  {
    if (!Player[i])
    {
      if (!is_empty)
      {
        slave_adresse = i + 1;
        is_empty = true;
        Player[i] = true;
        Wire.write(header, 2);
        Wire.write(slave_adresse);
        nb_player++;
      }
    }
  }
  if (!is_empty)
  {
    Wire.write(header, 2);
    Wire.write(adresse_wait);
    player_waiting = true;
  }
  //Serial.println(nb_player);
  is_empty = false;
}

void receiveEvent(int howMany)
{
  //Serial.println("data received");
  while (3 < Wire.available())
  {
    for (int i = 0; i < 2; i++)
    {
      test_header[i] = Wire.read();
    }
  }
  for (int j = 0 ; j < 2; j++)
  {
    if (header[j] != test_header[j])
    {
      confirm_header = false;
    }
    if (confirm_header) {
      test_header[j] = 0b00000000;
    }
  }
  if (confirm_header)
  {

    while (2 < Wire.available())
    {
      header_adresse = Wire.read();
    }
    //Serial.println("begin data");
    int k = 0;
    //Serial.print("header_adresse :");
    //Serial.println(header_adresse);
    switch (header_adresse)
    {
      case 1:
        while (0 < Wire.available())
        {
          player1[k] = Wire.read();
          k++;
        }
        player_change1 = true;
        change = true;
        break;
      case 2:
        while (0 < Wire.available())
        {
          player2[k] = Wire.read();
          k++;
        }
        player_change2 = true;
        change = true;
        break;
        /*
      case 3:
        while (0 < Wire.available())
        {
          player3[k] = Wire.read();
          k++;
        }
        player_change3 = true;
        change = true;
        break;
      case 4:
        while (0 < Wire.available())
        {
          player4[k] = Wire.read();
          k++;
        }
        player_change4 = true;
        change = true;
        break;
        */
      default:
        change = false;
    }
  }
}

char choose_char(int number,bool press_release) {
  switch (number) {
    case 33:
if(press_release){
  Keyboard.press('q');
}else{
  Keyboard.release('q');
}
    break;
    case 34:
if(press_release){
  Keyboard.press('w');
}else{
  Keyboard.release('w');
}
    break;
    case 35:
if(press_release){
  Keyboard.press('e');
}else{
  Keyboard.release('e');
}
    break;
    case 36:
if(press_release){
  Keyboard.press('r');
}else{
  Keyboard.release('r');
}
    break;
    case 37:
if(press_release){
  Keyboard.press('t');
}else{
  Keyboard.release('t');
}
    break;
    case 38:
if(press_release){
  Keyboard.press('z');
}else{
  Keyboard.release('z');
}
    break;
    case 39:
if(press_release){
  Keyboard.press('u');
}else{
  Keyboard.release('u');
}
    break;
    case 40:
if(press_release){
  Keyboard.press('i');
}else{
  Keyboard.release('i');
}
    break;
    case 41:
if(press_release){
  Keyboard.press('o');
}else{
  Keyboard.release('o');
}
    break;
    case 42:
if(press_release){
  Keyboard.press('p');
}else{
  Keyboard.release('p');
}
    break;
    case 43:
if(press_release){
  Keyboard.press('a');
}else{
  Keyboard.release('a');
}
    break;
    case 44:
if(press_release){
  Keyboard.press('s');
}else{
  Keyboard.release('s');
}
    break;
    case 45:
if(press_release){
  Keyboard.press('d');
}else{
  Keyboard.release('d');
}
    break;
    case 46:
if(press_release){
  Keyboard.press('f');
}else{
  Keyboard.release('f');
}
    break;
    case 47:
if(press_release){
  Keyboard.press('g');
}else{
  Keyboard.release('g');
}
    break;
    case 48:
if(press_release){
  Keyboard.press('h');
}else{
  Keyboard.release('h');
}
    break;
    case 49:
if(press_release){
  Keyboard.press('j');
}else{
  Keyboard.release('j');
}
    break;
    case 50:
if(press_release){
  Keyboard.press('k');
}else{
  Keyboard.release('k');
}
    break;
    case 51:
if(press_release){
  Keyboard.press('l');
}else{
  Keyboard.release('l');
}
    break;
    case 52:
if(press_release){
  Keyboard.press('y');
}else{
  Keyboard.release('y');
}
    break;
    case 53:
if(press_release){
  Keyboard.press('x');
}else{
  Keyboard.release('x');
}
    break;
    case 54:
if(press_release){
  Keyboard.press('c');
}else{
  Keyboard.release('c');
}
    break;
    case 55:
if(press_release){
  Keyboard.press('v');
}else{
  Keyboard.release('v');
}
    break;
    case 56:
if(press_release){
  Keyboard.press('b');
}else{
  Keyboard.release('b');
}
    break;
    
  }
}

void despair(boolean joueur, byte joueurarray[], int n)
{

  if (joueur)
  {
    //Serial.print("change :");
    //Serial.println(n);
    joueur = false;
    for (int i1 = 0; i1 < sizeof(joueurarray) / sizeof(byte); i1++)
    {
      //Serial.println("ok");
      if (i1 == 0)
      {
        //Serial.println("ok2");
        for (int j1 = 0; j1 < 4; j1++)
        {

          je_suis_perdu = debut_ascii + n * ahhhh + j1;
          //Serial.print("valeur bouton :");
          //Serial.println(je_suis_perdu);
          if (bitRead(joueurarray[i1], j1) == 1)
          {
            //Serial.println(je_suis_perdu);
            choose_char(je_suis_perdu,true);
          }
          else
          {
            choose_char(je_suis_perdu,false);
          }
        }
      }
      if (i1 == 1)
      {
        for (int j11 = 0; j11 < 8; j11++)
        {
          je_suis_perdu = debut_ascii + n * ahhhh + j11 + 4;
          if (bitRead(joueurarray[i1], j11) == 1)
          {
            //Serial.println(je_suis_perdu);
            choose_char(je_suis_perdu,true);
          }
          else
          {
            choose_char(je_suis_perdu,false);
          }
        }
      }
    }
  }
}

void loop()
{
  if (player_waiting)
  {
    //Serial.println("player waiting");
    for (int r = 0; r < sizeof(Player) / sizeof(bool); r++)
    {
      if (Player[r])
      {
        Wire.requestFrom(r + 1, 2);
        while (0 < Wire.available()) // slave may send less than requested
        {
          for (int i = 0; i < 2; i++)
          {
            test_header[i] = Wire.read();
          }
        }
        for (int j = 0 ; j < 2; j++)
        {
          if (header[j] != test_header[j])
          {
            confirm_header = false;
          }
          if (confirm_header)
          {
            test_header[j] = 0b00000000;
          }
        }
        if (!confirm_header)
        {
          Player[r] = false;
          nb_player--;
          //Serial.println("player absent");
          Wire.beginTransmission(adresse_wait);
          Wire.write(header, 2);
          Wire.endTransmission();
        }
        confirm_header = true;
      }
    }
    player_waiting = false;
    //Serial.println(nb_player);
  }
  if (change)
  {
    despair(player_change1, player1, 1);
    despair(player_change2, player2, 2);
    //despair(player_change3, player3, 3);
    //despair(player_change4, player4, 4);
    change = false;
  }
}

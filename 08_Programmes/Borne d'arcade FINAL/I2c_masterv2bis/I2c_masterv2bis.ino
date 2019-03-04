// Wire Master Writer

#include <Wire.h>
#include <Keyboard.h>

//déclaration des varaiables
#define adresse 0x7F
byte header[2] = {0xAA, 0xAA};
static byte test_header[2];
static bool confirm_header = true;
//static bool change = false;
int header_adresse;
char up_arrow = KEY_UP_ARROW;
char down_arrow = KEY_DOWN_ARROW;
char left_arrow = KEY_LEFT_ARROW;
char right_arrow = KEY_RIGHT_ARROW;
char enter = KEY_RETURN;
char backspace = KEY_BACKSPACE;

void setup()
{
  Serial.begin(9600);
  Wire.begin(adresse); // join i2c bus (address optional for master)
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);// request event
  Keyboard.begin();
  
}

//boolean Player[4] = {false, false, false, false};
boolean Player[2] = {false, false};
static bool is_empty = false;
bool player_waiting = false;
bool player_coming = false;
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

static int debut_ascii = 21;
static int ahhhh = 12;
static int je_suis_perdu;

void requestEvent()
{

  Serial.println("request event");
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
        player_coming = true;
        //delay(10);
      }
    }
  }
  if (!is_empty)
  {
    Wire.write(header, 2);
    Wire.write(adresse_wait);
    player_waiting = true;
    player_coming = true;
  }
  //Serial.println(nb_player);
  is_empty = false;
}

char choose_char(int number, bool press_release)
{
  switch (number)
  {
    case 33:
      if (press_release) //Player 1 Right
      {
        Keyboard.press(right_arrow);
      }
      else
      {
        Keyboard.release(right_arrow);
      }
      break;
    case 34:
      if (press_release) //Player 1 Left
      {
        Keyboard.press(left_arrow);
      }
      else
      {
        Keyboard.release(left_arrow);
      }
      break;
    case 35:
      if (press_release) //Player 1 Down
      {
        Keyboard.press(down_arrow);
      }
      else
      {
        Keyboard.release(down_arrow);
      }
      break;
    case 36:
      if (press_release)  //Player 1 Up
      {
        Keyboard.press(up_arrow);
      }
      else
      {
        Keyboard.release(up_arrow);
      }
      break;
    case 37:
      if (press_release) //Player 1 L1
      {
        Keyboard.press('b');
      }
      else
      {
        Keyboard.release('b');
      }
      break;
    case 38:
      if (press_release) //Player 1 R1
      {
        Keyboard.press('n');
      }
      else
      {
        Keyboard.release('n');
      }
      break;
    case 39:
      if (press_release) //Player 1 Y /!\ Il va considérer un layout etats-unien et envoyer z si y est appuyé et inversément
      {
        Keyboard.press('y');
      }
      else
      {
        Keyboard.release('y');
      }
      break;
    case 40:
      if (press_release) //Player 1 X
      {
        Keyboard.press('x');
      }
      else
      {
        Keyboard.release('x');
      }
      break;
    case 41:
      if (press_release) //Player 1 B
      {
        Keyboard.press('c');
      }
      else
      {
        Keyboard.release('c');
      }
      break;
    case 42:
      if (press_release) //Player 1 A
      {
        Keyboard.press('v');
      }
      else
      {
        Keyboard.release('v');
      }
      break;
    case 43:
      if (press_release) //Player 1 Select
      {
        Keyboard.press(backspace);
      }
      else
      {
        Keyboard.release(backspace);
      }
      break;
    case 44:
      if (press_release) //Player 1 Start
      {
        Keyboard.press(enter); 
      }
      else
      {
        Keyboard.release(enter);
      }
      break;
    case 45:
      if (press_release) //Player 2 Right
      {
        Keyboard.press('r');
      }
      else
      {
        Keyboard.release('r');
      }
      break;
    case 46:
      if (press_release) //Player 2 Left
      {
        Keyboard.press('e');
      }
      else
      {
        Keyboard.release('e');
      }
      break;
    case 47:
      if (press_release) //Player 2 Down
      {
        Keyboard.press('w');
      }
      else
      {
        Keyboard.release('w');
      }
      break;
    case 48:
      if (press_release) //Player 2 Up
      {
        Keyboard.press('q');
      }
      else
      {
        Keyboard.release('q');
      }
      break;
    case 49:
      if (press_release) //Player 2 L1
      {
        Keyboard.press('s');
      }
      else
      {
        Keyboard.release('s');
      }
      break;
    case 50:
      if (press_release) //Player 2 R1
      {
        Keyboard.press('a');
      }
      else
      {
        Keyboard.release('a');
      }
      break;
    case 51:
      if (press_release) //Player 2 Y
      {
        Keyboard.press('p');
      }
      else
      {
        Keyboard.release('p');
      }
      break;
    case 52:
      if (press_release) //Player 2 X
      {
        Keyboard.press('o');
      }
      else
      {
        Keyboard.release('o');
      }
      break;
    case 53:
      if (press_release) //Player 2 B
      {
        Keyboard.press('i');
      }
      else
      {
        Keyboard.release('i');
      }
      break;
    case 54:
      if (press_release) //Player 2 A
      {
        Keyboard.press('u');
      }
      else
      {
        Keyboard.release('u');
      }
      break;
    case 55:
      if (press_release) //Player 2 Select /!\ Il va considérer un layout etats-unien et envoyer z si y est appuyé et inversément
      {
        Keyboard.press('z');
      }
      else
      {
        Keyboard.release('z');
      }
      break;
    case 56:
      if (press_release) //Player 2 Start
      {
        Keyboard.press('t');
      }
      else
      {
        Keyboard.release('t');
      }
      break;

  }
}

void receiveEvent(int howMany)
{
  /*
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
    }
    if (confirm_header)
    {
    while (2 < Wire.available())
    {
      header_adresse = Wire.read();
    }
    int k = 0;
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
      case 3: while (0 < Wire.available()) {
          player3[k] = Wire.read();
          k++;
        }
        player_change3 = true;
        change = true;
        break;
      case 4:
        while (0 < Wire.available()) {
          player4[k] = Wire.read();
          k++;
        }
        player_change4 = true;
        change = true;
        break;

      default:
        change = false;

    }
    }
  */
}

void despair(boolean joueur, byte joueurarray[], int n)
{
  //if (joueur)
  {
    //joueur = false;
    for (int i1 = 0; i1 < sizeof(joueurarray) / sizeof(byte); i1++)
    {
      if (i1 == 0)
      {
        for (int j1 = 0; j1 < 4; j1++)
        {
          je_suis_perdu = debut_ascii + n * ahhhh + j1;
          if (bitRead(joueurarray[i1], j1) == 1)
          {
            //Serial.println(je_suis_perdu);
            choose_char(je_suis_perdu, true);
          }
          else
          {
            choose_char(je_suis_perdu, false);
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
            choose_char(je_suis_perdu, true);
          }
          else
          {
            choose_char(je_suis_perdu, false);
          }
        }
      }
    }
    //}
  }
}
void loop()
{
  
  /*
    if (player_waiting) {
      Serial.println("player waiting");
      for (int r = 0; r < sizeof(Player) / sizeof(bool); r++) {
        if (Player[r]) {
          Wire.requestFrom(r + 1, 2);
          while (3 < Wire.available()) { // slave may send less than requested
            for (int i = 0; i < 2; i++) {
              test_header[i] = Wire.read();
            }
          }
          for (int j = 0 ; j < 2; j++) {
            if (header[j] != test_header[j]) {
              confirm_header = false;
            }
            if (!confirm_header) {
              test_header[j] = 0b00000000;
            }
          }
          if (!confirm_header) {
            Player[r] = false;
            nb_player--;
            Serial.println("player absent");
          }
          confirm_header = true;
        }
      }
      if (nb_player < sizeof(Player) / sizeof(bool)) {
        Wire.beginTransmission(adresse_wait);
        Wire.write(header, 2);
        Wire.endTransmission();

        Serial.println(nb_player);
      }
      player_waiting = false;
    }
  */
  if (nb_player > 0)
  {
    if (player_coming)
    {
      delay(5000);
      player_coming = false;
    }
    //Serial.println("OK");
    for (int r1 = 0; r1 < sizeof(Player) / sizeof(bool); r1++)
    {
      if (Player[r1])
      {
        Wire.requestFrom(r1 + 1, 5);
        while (3 < Wire.available())
        {
          for (int i = 0; i < 2; i++)
          {
            test_header[i] = Wire.read();
            //Serial.println(test_header[i]);
          }
        }
        for (int j = 0 ; j < 2; j++)
        {
          if (header[j] != test_header[j])
          {
            confirm_header = false;
            //Serial.println("false");
          }
          if (confirm_header)
          {
            test_header[j] = 0b00000000;
          }
        }
        
        if (confirm_header)
        {
          //Serial.println("OK2");
          while (2 < Wire.available())
          {
            header_adresse = Wire.read();
          }
          int k = 0;
          switch (header_adresse)
          {
            case 1:
              while (0 < Wire.available())
              {
                player1[k] = Wire.read();
                k++;
              }
              //Serial.println("OK3");
              despair(player_change1, player1, 1);
              //player_change1 = true;
              //change = true;
              break;
            case 2:
              while (0 < Wire.available())
              {
                player2[k] = Wire.read();
                k++;
              }
              despair(player_change2, player2, 2);
              //player_change2 = true;
              //change = true;
              break;
          }
        }
        else if(player_waiting&&!confirm_header)
        {
          Player[r1] = false;
          nb_player--;
          Serial.println("player absent");
          Serial.println(nb_player);
        }
        confirm_header = true;
        if (player_waiting)
        {
          Serial.println("player waiting");
          if (nb_player < sizeof(Player) / sizeof(bool))
          {
            Wire.beginTransmission(adresse_wait);
            Wire.write(header, 2);
            Wire.endTransmission();

            Serial.println(nb_player);
          }
          player_waiting = false;
        }
      }
      //despair(player_change3, player3, 3);
      //despair(player_change4, player4, 4);
      //change = false;
    }
  }
}

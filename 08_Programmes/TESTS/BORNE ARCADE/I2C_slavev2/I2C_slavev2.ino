// Wire Slave Receiver

#include <Wire.h>

#define bouton1  2
#define bouton2  3
#define bouton3  4
#define bouton4  5
#define bouton5  6
#define bouton6  7
#define bouton7  8
#define bouton8  9
#define bouton9  10
#define bouton10 11
#define bouton11 12
#define bouton12 13

#define leonardo 0x7F
int adresse;
static bool redefine_adresse = false;
bool player = false;
bool waiting = false;
byte header[2] = {0xAA, 0xAA};
static byte test_header[2];
static bool confirm_header = true;
static byte trame[2] = {0b00000000, 0b00000000};
static byte copie_trame[2] = {0b00000000, 0b00000000};
static bool change = false;

// function that executes whenever data is received from master
// this function is registered as an event, see setup()

void receiveEvent(int howMany) 
{
 // Serial.println("data received");
  while (0 < Wire.available()) { // slave may send less than requested
    for (int i = 0; i < 2; i++) {
      test_header[i] = Wire.read();
    }
  }
  for (int j = 0 ; j < 2; j++) {
    if (header[j] != test_header[j]) {
      confirm_header = false;
    }
  }
  if (confirm_header) {
    redefine_adresse = false;
  }
  confirm_header = true;
}


void configuration(int new_adresse) {
  if (new_adresse <= 4) {
    Wire.begin(new_adresse);
    Wire.onReceive(receiveEvent); // register event
    Wire.onRequest(requestEvent);// request event
    redefine_adresse = true;
    waiting = false;
    player = true;
    //Serial.print("adresse:");
   // Serial.println(new_adresse);
    activate_pin();
  } else {
    Wire.begin(new_adresse);
    Wire.onReceive(receiveEvent); // register event
    Wire.onRequest(requestEvent);// request event
    redefine_adresse = true;
    waiting = true;
    player = false;
    //Serial.println("en attente");
  }
}

void activate_pin() {

  pinMode(bouton1, INPUT_PULLUP);
  pinMode(bouton2, INPUT_PULLUP);
  pinMode(bouton3, INPUT_PULLUP);
  pinMode(bouton4, INPUT_PULLUP);
  pinMode(bouton5, INPUT_PULLUP);
  pinMode(bouton6, INPUT_PULLUP);
  pinMode(bouton7, INPUT_PULLUP);
  pinMode(bouton8, INPUT_PULLUP);
  pinMode(bouton9, INPUT_PULLUP);
  pinMode(bouton10, INPUT_PULLUP);
  pinMode(bouton11, INPUT_PULLUP);
  pinMode(bouton12, INPUT_PULLUP);

}

void setup() {
  //Serial.begin(9600);             // start serial for output
  Wire.begin();           // join i2c bus with address
}

void requestEvent() {
  Wire.write(header, 2);
}

#define zero  0b00000000
#define one   0b00000001
#define two   0b00000010
#define three 0b00000100
#define four  0b00001000
#define five  0b00010000
#define six   0b00100000
#define seven 0b01000000
#define eight 0b10000000

#define not_zero  0b11111111
#define not_one   0b11111110
#define not_two   0b11111101
#define not_three 0b11111011
#define not_four  0b11110111
#define not_five  0b11101111
#define not_six   0b11011111
#define not_seven 0b10111111
#define not_eight 0b01111111

void button(int bouton, int seq_trame, byte place, byte not_place) {
  if (digitalRead(bouton) == LOW) {
    delay(10);
    //Serial.println("button pressed");
    trame[seq_trame] = trame[seq_trame] | place;
  } else {
    delay(10);
    trame[seq_trame] = trame[seq_trame] & not_place;
  }
}

void loop() {
  if (!redefine_adresse) {
    //Serial.println("debut recherche");
    Wire.requestFrom(leonardo, 3);
    //Serial.println("fin recherche");
    while (1 < Wire.available()) { // slave may send less than requested
      for (int i = 0; i < 2; i++) {
        test_header[i] = Wire.read();
      }
    }
    for (int j = 0 ; j < 2; j++) {
      if (header[j] != test_header[j]) {
        confirm_header = false;
      }
    }
    if (confirm_header) {
      while (Wire.available()) {
        adresse = Wire.read();
      }
      configuration(adresse);
    }
    confirm_header = true;
  }
  if (player) {
    button(bouton1,  0, four, not_four);
    button(bouton2,  0, three, not_three);
    button(bouton3,  0, two, not_two);
    button(bouton4,  0, one, not_one);
    button(bouton5,  1, eight, not_eight);
    button(bouton6,  1, seven, not_seven);
    button(bouton7,  1, six, not_six);
    button(bouton8,  1, five, not_five);
    button(bouton9,  1, four, not_four);
    button(bouton10, 1, three, not_three);
    button(bouton11, 1, two, not_two);
    button(bouton12, 1, one, not_one);
    /*
    for (int i = 0; i < 2; i++) {
      if (trame[i] != copie_trame[i]) {
        change = true;
      }
    }
    if (change) {
      for (int j = 0; j < 2; j++) {
        copie_trame[j] = trame[j];
      }
      */
      Wire.beginTransmission(leonardo);
      Wire.write(header, 2);
      Wire.write(adresse);
      Wire.write(trame, 2);
      Wire.endTransmission();
      //change = false;
    }
  }





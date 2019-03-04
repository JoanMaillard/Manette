#include <SoftwareSerial.h>
#include <PJON.h>

byte header = 0xAA;
byte test_header;
bool sucess = false;
bool first = true;
bool blu_done = false;
bool PComm = false;
bool pp = false;
int avail;
unsigned long chrono;
unsigned long last_chrono;
#define waiting 3000

#define RxD         11 //il s'agit du pin 2 sur le shield mais à cause du mega il faut le relier au pin 11
#define TxD         3
#define bouton      22
SoftwareSerial blueToothSerial(RxD, TxD);
PJON<ThroughSerial> bus(45);

void setup() {
  // put your setup code here, to run once:
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(bouton, INPUT_PULLUP);
  blueToothSerial.begin(9600);
  Serial.begin(9600);
  //blueToothSerial.flush();
  chrono = millis();
  last_chrono = chrono;
  Serial.println("begin");

  /*
    // Pass the blueToothSerial Serial instance you want to use for PJON communication
    bus.strategy.set_serial(&blueToothSerial);

    // Avoid synchronous acknowledgement
    bus.set_synchronous_acknowledge(false);

    bus.begin();
  */
  // Pass the blueToothSerial Serial instance you want to use for PJON communication
  bus.strategy.set_serial(&blueToothSerial);
  // Run in bi-directional PJON_HALF_DUPLEX mode
  bus.set_communication_mode(PJON_HALF_DUPLEX);
  // Avoid synchronous acknowledgement
  bus.set_synchronous_acknowledge(false);

  bus.begin();
  
}


void loop() {
  // put your main code here, to run repeatedly:
  if (blu_done && !PComm) {
    if (!pp) {
      if (chrono - last_chrono >= waiting) {
        pp = true;
        bus.update();
        if (bus.send_packet(44, "All is ok?!", 11) == PJON_ACK) {
          Serial.println("44 is ok!");
          PComm = true;
        }
      }
    }
    if (pp) {
      bus.update();
      if (bus.send_packet(44, "All is ok?!", 11) == PJON_ACK) {
        Serial.println("44 is ok!");
        PComm = true;
      }
    }
  }
  chrono = millis();
  if (!blu_done) {
    if (!sucess) {
      if (first || chrono - last_chrono >= waiting) {
        Serial.println("send");
        first = false;
        last_chrono = chrono;
        blueToothSerial.write(header);
      }
      if (blueToothSerial.available() > 0) {
        Serial.println("receive");
        test_header = blueToothSerial.read();
        if (test_header == header) {
          sucess = true;
        }
      }
    }
    if (sucess) {
      Serial.println("ok");
      //sucess = false;
      blu_done = true;
      first = true;
      last_chrono = chrono;
    }
  }
  if (blu_done && PComm) {
    Serial.println("setupComplete");
  }
  /*
    avail = blueToothSerial.available();
    Serial.println(avail);
  */
}

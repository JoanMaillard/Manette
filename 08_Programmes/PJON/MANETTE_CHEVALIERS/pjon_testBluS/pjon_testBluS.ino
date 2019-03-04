#include <SoftwareSerial.h>
#include <PJON.h>

byte header = 0xAA;
byte test_header;
bool sucess = false;
bool first = true;
bool blu_done = false;
bool PComm = false;
int avail;
int temp = 0;
unsigned long chrono;
unsigned long last_chrono;
#define waiting 3000

#define RxD         11
#define TxD         12
#define bouton      9
bool etat_bouton = false;
SoftwareSerial blueToothSerial(RxD, TxD);
PJON<ThroughSerial> bus(44);

void setup() {
  // put your setup code here, to run once:
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(bouton, INPUT_PULLUP);
  blueToothSerial.begin(9600);
  Serial.begin(9600);
  while(!Serial);
  //blueToothSerial.flush();
  chrono = millis();
  last_chrono = chrono;
  Serial.println("begin");
  bus.strategy.set_serial(&blueToothSerial);
  // Run in bi-directional PJON_HALF_DUPLEX mode
  bus.set_communication_mode(PJON_HALF_DUPLEX);
  // Avoid synchronous acknowledgement
  bus.set_synchronous_acknowledge(false);
  bus.begin();
  bus.set_receiver(receiver_function);
}

void receiver_function(uint8_t *payload, uint16_t length, const PJON_Packet_Info &packet_info) {
  // Make use of the payload before sending something, the buffer where payload points to is
  // overwritten when a new message is dispatched

  for (int i = 0; i < length; i++) {
    char c = payload[i];
    Serial.print(c);
  }
  Serial.println("");

  PComm = true;
};

void loop() {
  // put your main code here, to run repeatedly:
  if (!first) {
    /*
      // Pass the blueToothSerial Serial instance you want to use for PJON communication
      bus.strategy.set_serial(&blueToothSerial);

      bus.begin();
      bus.set_receiver(receiver_function);
    */
    first = true;
  }
  chrono = millis();
  if (!blu_done) {
    if (!sucess) {
      if (blueToothSerial.available() > 0) {
        Serial.println("receive");
        avail = blueToothSerial.available();
        Serial.println(avail);
        test_header = blueToothSerial.read();
        if (test_header == header) {
          Serial.println("ok");
          sucess = true;
          //temp++;
        }
      }
    }
    if (sucess) {
      //if (chrono - last_chrono >= waiting) {
      Serial.println("send");
      last_chrono = chrono;
      blueToothSerial.write(header);
      sucess = false;
      first = false;
      blu_done = true;
      //}
    }
  }
  if (blu_done && first) {
    bus.receive();
  }
  if (PComm) {
    Serial.println("setupComplete");
  }
}

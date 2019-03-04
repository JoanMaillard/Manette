/*
   FM.h
   A library for SeeedStudio Grove FM

   Copyright (c) 2012 seeed technology inc.
   Website    : www.seeed.cc
   Author     : Steve Chang
   Create Time: JULY 2014
   Change Log : Modified by loovee 2013-10-29  ,   Modified by jacob yan 2014-7-29

   The MIT License (MIT)

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/
///*
//#define PJON_INCLUDE_TS
//#define PJON_INCLUDE_ASYNC_ACK true
#include <PJON.h>
//*/
#include <SoftwareSerial.h>   //Software Serial Port

#define RxD         11
#define TxD         3

//#define PINLED      9

//#define LEDON()     digitalWrite(PINLED, HIGH)
//#define LEDOFF()    digitalWrite(PINLED, LOW)

#define DEBUG_ENABLED  1

SoftwareSerial blueToothSerial(RxD, TxD);
PJON<ThroughSerial> bus(54);


bool come_on = false;

void setup()
{
  Serial.begin(9600);
  while(!Serial);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // Initialize LED 13 to be off
  //LEDOFF();
  blueToothSerial.begin(9600);

  //setupBlueToothConnection();
  //wait 1s and flush the serial buffer
  delay(1000);
  Serial.flush();

  blueToothSerial.flush();


  // Pass the blueToothSerial Serial instance you want to use for PJON communication
  bus.strategy.set_serial(&blueToothSerial);

  bus.begin();
  bus.set_receiver(receiver_function);

}

void receiver_function(uint8_t *payload, uint16_t length, const PJON_Packet_Info &packet_info) {
  // Make use of the payload before sending something, the buffer where payload points to is
  // overwritten when a new message is dispatched
Serial.println("OK");
  for (int i = 0; i < length; i++) {
    char c = payload[i];
    Serial.print(c);
  }
  Serial.println("");

  /*  Serial.print("Header: ");
    Serial.print(packet_info.header, BIN);
    // If packet formatted for a shared medium
    if(packet_info.header & PJON_MODE_BIT) {
    Serial.print(" Receiver bus id: ");
    Serial.print(packet_info.receiver_bus_id[0]);
    Serial.print(packet_info.receiver_bus_id[1]);
    Serial.print(packet_info.receiver_bus_id[2]);
    Serial.print(packet_info.receiver_bus_id[3]);
    Serial.print(" Receiver id: ");
    Serial.print(packet_info.receiver_id);
    // If sender info is included
    if(packet_info.header & PJON_TX_INFO_BIT) {
      Serial.print(" Sender bus id: ");
      Serial.print(packet_info.sender_bus_id[0]);
      Serial.print(packet_info.sender_bus_id[1]);
      Serial.print(packet_info.sender_bus_id[2]);
      Serial.print(packet_info.sender_bus_id[3]);
    }
    }
    // If sender device id is included
    if(packet_info.header & PJON_TX_INFO_BIT) {
    Serial.print(" Sender id: ");
    Serial.print(packet_info.sender_id);
    }
    // Payload Length
    Serial.print(" Length: ");
    Serial.print(length);
    // If port id is included
    if(packet_info.header & PJON_PORT_BIT) {
    Serial.print(" Port bit: ");
    Serial.print(packet_info.port);
    }
    Serial.println();
  */
};


void loop()
{
  //char recvChar;
  ///*
  bus.receive();
  //blueToothSerial.flush();
  //*/
  /*
    while (1)
    {
    if (blueToothSerial.available() > 0)
    { //check if there's any data sent from the remote bluetooth shield

      recvChar = blueToothSerial.read();
      Serial.println(recvChar);
      /*
            if (recvChar == '1')
            {
              //LEDON();
            }
            else if (recvChar == '0')
            {
              //LEDOFF();
            }
  */
  //}
  //}
}
/***************************************************************************
   Function Name: setupBlueToothConnection
   Description:  initilizing bluetooth connction
   Parameters:
   Return:
***************************************************************************/
void setupBlueToothConnection()
{

  blueToothSerial.begin(9600);

  blueToothSerial.print("AT");
  delay(400);

  blueToothSerial.print("AT+DEFAULT");             // Restore all setup value to factory setup
  delay(2000);

  blueToothSerial.print("AT+NAMESeeedBTSlave");    // set the bluetooth name as "SeeedBTSlave" ,the length of bluetooth name must less than 12 characters.
  delay(400);

  blueToothSerial.print("AT+ROLES");             // set the bluetooth work in slave mode
  delay(400);

  blueToothSerial.print("AT+PIN0044");             // set the pair code to connect
  delay(400);

  //blueToothSerial.print("AT+BAUD6");             // set the baudrate to 38400
  //delay(400);

  blueToothSerial.print("AT+AUTH1");             //
  delay(400);

  blueToothSerial.flush();

  Serial.println("Setup complete");
}

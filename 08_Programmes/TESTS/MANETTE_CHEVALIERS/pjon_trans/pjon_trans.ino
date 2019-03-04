
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
#include <SoftwareSerial.h>                         // Software Serial Port

#define RxD         2
#define TxD         3

//#define PINBUTTON   9                               // pin of button

#define DEBUG_ENABLED  1

int incomingByte = 0;  // for incoming serial data
int test = 10;

SoftwareSerial blueToothSerial(RxD, TxD);
PJON<ThroughSerial> bus(45);



void setup()
{
  Serial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  //pinMode(PINBUTTON, INPUT_PULLUP);
  blueToothSerial.begin(9600);

  //setupBlueToothConnection();
  //wait 1s and flush the serial buffer
  delay(1000);
  Serial.flush();

  blueToothSerial.flush();

  ///*
  // Pass the blueToothSerial Serial instance you want to use for PJON communication
  bus.strategy.set_serial(&blueToothSerial);

  // Avoid synchronous acknowledgement
  bus.set_synchronous_acknowledge(false);

  bus.begin();

  // Send B to device 44 every second
  //bus.send_repeatedly(44, "B", 1, 1000000);
  //*/
}

void loop()
{
  /*
    bus.update();
    bus.send_packet(44, "Hi!", 3);
    if (bus.send_packet(44, "All is ok?!", 11) == PJON_ACK) {
    Serial.println("44 is ok!");
    }
    if (bus.send_packet(44, "All is ok?!", 11) == PJON_BUSY) {
    Serial.println("44 is busy!");
    }
    if (bus.send_packet(44, "All is ok?!", 11) == PJON_FAIL) {
    Serial.println("44 failed!");
    }
    blueToothSerial.flush();
    //static unsigned char state = 0;             // led off
  */
  /*
    if (digitalRead(PINBUTTON) == LOW)
    {
      state = 1 - state;

      Serial.println("button on");
      Serial.println(state);
      blueToothSerial.print(state);

      delay(10);
      while (digitalRead(PINBUTTON) == LOW)    // until button release
      {
        delay(10);
      }

      Serial.println("button off");
    }
  */
  /*
    // reply only when you receive data:
    if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    blueToothSerial.write(incomingByte);
    //bus.send_packet(44,"Hello World!",12,1);
    }
  */
  /*
    else{
    blueToothSerial.write(test);
    }
  */
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

  blueToothSerial.print("AT+NAMESeeedMaster");    // set the bluetooth name as "SeeedMaster" ,the length of bluetooth name must less than 12 characters.
  delay(400);

  blueToothSerial.print("AT+ROLES");             // set the bluetooth work in slave mode
  delay(400);

  

  blueToothSerial.print("AT+PIN0041");             // set the pair code to connect
  delay(400);

  //blueToothSerial.print("AT+BAUD6");             // set the baudrate to 38400
  //delay(400);

  blueToothSerial.print("AT+CLEAR");             // Clear connected device mac address
  delay(400);

blueToothSerial.print("AT+AUTH1");
  delay(400);

  blueToothSerial.flush();

  Serial.println("Setup complete");
}

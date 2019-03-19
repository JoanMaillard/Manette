#define SDA_PORT PORTD
#define SDA_PIN 6 // = A4
#define SCL_PORT PORTD
#define SCL_PIN 7 // = A5
#include <SoftI2CMaster.h>

#define iobusAddress 0
#define pinaxis1 0
#define pinaxis2 1
#define pinaxis3 2
#define pinaxis4 3
#define pinaxis5 4
#define pinaxis6 5
#define DATA_SIZE 8
#define I2C_7BITADDR 0x20


const byte regA = 0x12;
const byte regB = 0x13;
byte potVal1, potVal2, joy1X, joy1Y, joy2X, joy2Y;
int minIn1, minIn2, minInx3, minInx4, minIny3, minIny4, maxIn1, maxIn2, maxInx3, maxInx4, maxIny3, maxIny4;
bool calibrating = false;
bool calPressed = false;

void setup() {
  // put your setup code here, to run once:
  minIn1 = 0;
  minIn2 = 0;
  minInx3 = 0;
  minIny3 = 0;
  minInx4 = 0;
  minIny4 = 0;
  maxIn1 = 1023;
  maxIn2 = 1023;
  maxInx3 = 1023;
  maxIny3 = 1023;
  maxInx4 = 1023;
  maxIny4 = 1023;
  Serial.begin(115200);
  i2c_init();
  if (!i2c_start((I2C_7BITADDR<<1)|I2C_WRITE)) { // start transfer
        Serial.println("I2C device busy");
        return;
    }
  i2c_write(0);
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR<<1)|I2C_WRITE);
  i2c_write(1);
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR<<1)|I2C_WRITE);
  i2c_write(0x0C);
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR<<1)|I2C_WRITE);
  i2c_write(0x0D);
  i2c_write(0xFF);
  i2c_stop();
  Serial.println("setup complete");
  pinMode(pinaxis1, INPUT);
  pinMode(pinaxis2, INPUT);
  pinMode(pinaxis3, INPUT);
  pinMode(pinaxis4, INPUT);
  pinMode(pinaxis5, INPUT);
  pinMode(pinaxis6, INPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  byte *buttonData = getButtons();
  
  calButCheck(buttonData[0]);
  
  
  //if (!calibrating) {Serial.write(mainData,DATA_SIZE);}
  //else {}
  if (calibrating) {
    digitalWrite(8,HIGH);
    minIn1 = 0;
    minIn2 = 0;
    minInx3 = 0;
    minIny3 = 0;
    minInx4 = 0;
    minIny4 = 0;
    maxIn1 = 1023;
    maxIn2 = 1023;
    maxInx3 = 1023;
    maxIny3 = 1023;
    maxInx4 = 1023;
    maxIny4 = 1023;
    int temp[12] = {1023, 1023, 1023, 1023, 1023, 1023, 0, 0, 0, 0, 0, 0};
    int tpotVal1, tpotVal2, tjoy1X, tjoy1Y, tjoy2X, tjoy2Y;
    while (calibrating) {
      byte *buttonData = getButtons();
      calButCheck(buttonData[0]);
      tpotVal1 = analogRead(pinaxis1);
      Serial.println(tpotVal1);
      tpotVal2 = analogRead(pinaxis2);
      tjoy1X = analogRead(pinaxis3);
      tjoy1Y = analogRead(pinaxis4);
      tjoy2X = analogRead(pinaxis5);
      tjoy2Y = analogRead(pinaxis6);
      if (tpotVal1 < temp[0]) { //minimums
        temp[0]=tpotVal1;
      }
      if (tpotVal2 < temp[1]) {
        temp[1] = tpotVal2;
      }
      if (tjoy1X < temp[2]) {
        temp[2] = tjoy1X;
      }
      if (tjoy1Y < temp[3]) {
        temp[3] = tjoy1Y;
      }
      if (tjoy2X < temp[4]) {
        temp[4] = tjoy2X;
      }
      if (tjoy2Y < temp[5]) {
        temp[5] = tjoy2Y;
      }
      if (tpotVal1 > temp[6]) { //maximums
        temp[6]=tpotVal1;
      }
      if (tpotVal2 > temp[7]) {
        temp[7] = tpotVal2;
      }
      if (tjoy1X > temp[8]) {
        temp[8] = tjoy1X;
      }
      if (tjoy1Y > temp[9]) {
        temp[9] = tjoy1Y;
      }
      if (tjoy2X > temp[10]) {
        temp[10] = tjoy2X;
      }
      if (tjoy2Y > temp[11]) {
        temp[11] = tjoy2Y;
      }
    }
    minIn1 = temp[0];
    minIn2 = temp[1];
    minInx3 = temp[2];
    minIny3 = temp[3];
    minInx4 = temp[4];
    minIny4 = temp[5];
    maxIn1 = temp[6];
    maxIn2 = temp[7];
    maxInx3 = temp[8];
    maxIny3 = temp[9];
    maxInx4 = temp[10];
    maxIny4 = temp[11];
  }
  else {
    digitalWrite(8,LOW);
    getValues();
    byte *mainData = conc(buttonData[0], buttonData[1]);
    Serial.print(mainData[0]);
    Serial.print(", ");
    Serial.print(mainData[1]);
    Serial.print(", ");
    Serial.print(mainData[2]);
    Serial.print(", ");
    Serial.print(mainData[3]);
    Serial.print(", ");
    Serial.print(mainData[4]);
    Serial.print(", ");
    Serial.print(mainData[5]);
    Serial.print(", ");
    Serial.print(mainData[6]);
    Serial.print(", ");
    Serial.println(mainData[7]);
  }
}
  
byte * getButtons() {
  static byte vals[2]; 
  if (!i2c_start((I2C_7BITADDR<<1)|I2C_WRITE)) { // start transfer
        Serial.println("I2C device busy");
        return;
    }
  i2c_write(regA);
  i2c_rep_start((I2C_7BITADDR<<1)|I2C_READ); // restart for reading
  byte val1 = i2c_read(true); // read one byte and send NAK to terminate
  i2c_stop(); // send stop condition
  if (!i2c_start((I2C_7BITADDR<<1)|I2C_WRITE)) { // start transfer
       Serial.println("I2C device busy");
       return;
   }
  i2c_write(regB);
  i2c_rep_start((I2C_7BITADDR<<1)|I2C_READ); // restart for reading
  byte val2 = i2c_read(true); // read one byte and send NAK to terminate
  i2c_stop(); // send stop condition
  vals[0] = val1;
  vals[1] = val2;
  return vals; 
  }

void getValues() {
  potVal1 = map(constrain(analogRead(pinaxis1), minIn1, maxIn1),minIn1,maxIn1,0,255); //get axies constrained between their max values
  potVal2 = map(constrain(analogRead(pinaxis2), minIn2, maxIn2),minIn2,maxIn2,0,255);
  joy1X = map(constrain(analogRead(pinaxis3), minInx3, maxInx3),minInx3,maxInx3,0,255);
  joy1Y = map(constrain(analogRead(pinaxis4), minIny3, maxIny3),minIny3,maxIny3,0,255);
  joy2X = map(constrain(analogRead(pinaxis5), minInx4, maxInx4),minInx4,maxInx4,0,255);
  joy2Y = map(constrain(analogRead(pinaxis6), minIny4, maxIny4),minIny4,maxIny4,0,255);
}

void calButCheck(byte val1) {
if (!calPressed && !bitRead(val1,0)) {
    calPressed = true;
    if (calibrating)
      {calibrating = false;}
   else {calibrating = true;}
  }
  else if (bitRead(val1,0)) {
    calPressed = false;
  }
}

byte * conc(byte val1, byte val2) {
  static byte concatenated[DATA_SIZE];
  byte *buttonData = getButtons();
  concatenated[0] = 255-buttonData[0];
  concatenated[1] = 255-buttonData[1];
  concatenated[2] = potVal1;
  concatenated[3] = potVal2;
  concatenated[4] = joy1X;
  concatenated[5] = joy1Y;
  concatenated[6] = joy2X;
  concatenated[7] = joy2Y;
  return concatenated;
}

#define SDA_PORT PORTD
#define SDA_PIN 6 // = A4
#define SCL_PORT PORTD
#define SCL_PIN 7 // = A5
#include <SoftI2CMaster.h>
#include <EEPROM.h>

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
byte definitiveValues[6] = {0}; //1: trig 1; 2: trig 2; 3-6: joysticks
int calibValues[16] = {0};
bool calibrating = false;
bool calPressed = false;

void setup() {
  // put your setup code here, to run once:
  if (EEPROM.read(32) == 255) { //if first launch, meaning no calibrated values are present in EEPROM)
    for (byte i = 0; i < 16; i++) {
      if (i < 6) {
        calibValues[i] = 0;
      }
      if (i >= 6 && i < 12) {
        calibValues[i] = 1023;
      }
      if (i >= 12) {
        calibValues[i] = 512;
      }
    }
    calibrating = true;
  }
  else {
    for (byte i = 0; i < 16; i++) { //puts all memorized calibration values into current-use memory
      calibValues[i] = (int)((EEPROM.read(2 * i) << 8) | EEPROM.read(2 * i + 1));
    }
  }
  Serial.begin(115200);
  i2c_init();
  if (!i2c_start((I2C_7BITADDR << 1) | I2C_WRITE)) { // start transfer
    //Serial.println("I2C device busy");
    return;
  }
  i2c_write(0); //initialize MCP23017: address 0 as inputs
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR << 1) | I2C_WRITE);
  i2c_write(1); //initialize MCP23017: address 1 as inputs
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR << 1) | I2C_WRITE);
  i2c_write(0x0C); //initialize MCP23017: address 12 as pullup
  i2c_write(0xFF);
  i2c_stop();
  i2c_start((I2C_7BITADDR << 1) | I2C_WRITE);
  i2c_write(0x0D); //initialize MCP23017: address 13 as pullup
  i2c_write(0xFF);
  i2c_stop();
  //Serial.println("setup complete");
  pinMode(pinaxis1, INPUT); //initialize axis input pins
  pinMode(pinaxis2, INPUT);
  pinMode(pinaxis3, INPUT);
  pinMode(pinaxis4, INPUT);
  pinMode(pinaxis5, INPUT);
  pinMode(pinaxis6, INPUT);
  pinMode(8, OUTPUT); //initialize calibration mode LED pin
  pinMode(9, INPUT_PULLUP); //initialize calibration button pin
}

void loop() {

  byte *buttonData = getButtons();
  calButCheck(); //checks calibration button

  if (calibrating) { //calibration procedure if enabled
    //Serial.println("Calibrating...");
    digitalWrite(8, HIGH); //enable calibration LED
    int temp[12] = {0};
    for (byte i = 0; i < 16; i++) { //puts default values everywhere for calibration purposes
      if (i < 6) {
        calibValues[i] = 0;
        temp[i] = 1023;
      }

      else if (i < 12) {
        calibValues[i] = 1023;
        temp[i] = 0;
      }
      else {
        calibValues[i] = 512;
      }
    }
    int tempCalibValues[6] = {0};
    while (calibrating) {
      byte *buttonData = getButtons();
      calButCheck(); //check calibration button for calibration end
      for (byte i = 0; i < 6; i++) {
        tempCalibValues[i] = analogRead(i); //gather raw data for calibration
      }
      for (byte i = 0; i < 6; i++) { //minimums
        if (tempCalibValues[i] < temp[i]) {
          temp[i] = tempCalibValues[i];
        }
      }
      for (byte i = 0; i < 6; i++) { //maximums
        if (tempCalibValues[i] > temp[i + 6]) {
          temp[i + 6] = tempCalibValues[i];
        }
      }
    }
    //end of calibration procedure
    for (byte i = 0; i < 12; i++) { //puts calibrated values into current memory
      if (i < 6) {
        calibValues[i] = temp[i];
      }
      else {
        calibValues[i] = temp[i] - 2;
      }
    }
    for (byte i = 2; i < 6; i++) { //middle values on joysticks for centering (per-axis-side calculation)
      calibValues[i + 10] = analogRead(i);
    }

    for (byte i = 0; i < 16; i++) { //puts calibrated values into permanent memory (EEPROM)
      if (i < 6 || i >= 12) {
        EEPROM.update(2 * i, highByte(calibValues[i]));
        EEPROM.update(2 * i + 1, lowByte(calibValues[i]));
      }
      else {
        int tempStorable = temp[i] - 2;
        EEPROM.update(2 * i, highByte(tempStorable));
        EEPROM.update(2 * i + 1, lowByte(tempStorable));
      }
    }
    EEPROM.update(32, 0);
  } //end of calibration procedure __________________________________________________________________________

  else { //normal procedure if calibration procedure is disabled
    digitalWrite(8, LOW); //shut down calibration LED

    if (Serial.read() == 255) { //if the BLE transmitter has sent a data transfer request, gather values and send them away
      getValues();
      byte *mainData = conc(buttonData[0], buttonData[1]);
      Serial.write(mainData, 8);
    }
  }
}

byte * getButtons() { //interrogates the MCP23017 and handles the values it returns
  static byte vals[2];
  if (!i2c_start((I2C_7BITADDR << 1) | I2C_WRITE)) { // start transfer
    //Serial.println("I2C device busy");
    return;
  }
  i2c_write(regA);
  i2c_rep_start((I2C_7BITADDR << 1) | I2C_READ); // restart for reading
  byte val1 = i2c_read(true); // read one byte and send NAK to terminate
  i2c_stop(); // send stop condition
  if (!i2c_start((I2C_7BITADDR << 1) | I2C_WRITE)) { // start transfer
    //Serial.println("I2C device busy");
    return;
  }
  i2c_write(regB);
  i2c_rep_start((I2C_7BITADDR << 1) | I2C_READ); // restart for reading
  byte val2 = i2c_read(true); // read one byte and send NAK to terminate
  i2c_stop(); // send stop condition
  vals[0] = val1;
  vals[1] = val2;
  return vals;
}

void getValues() { //get all values from all axies
  int joyRawValues[4] = {0};
  for (byte i = 0; i < 4; i++) { //gather raw joystick values
    joyRawValues[i] = analogRead(i + 2);
  }

  //get axies constrained between their extreme values
  definitiveValues[0] = map(constrain(analogRead(pinaxis1), calibValues[0], calibValues[6]), calibValues[0], calibValues[6], 0, 255);
  definitiveValues[1] = map(constrain(analogRead(pinaxis2), calibValues[1], calibValues[7]), calibValues[1], calibValues[7], 0, 255);

  for (byte i = 0;  i < 4; i++) { //treat joystick values
    if (joyRawValues[i] <= calibValues[i + 12]) {
      definitiveValues[i + 2] = map(constrain(joyRawValues[i], calibValues[(int)2 + ((i / 2) + (2 * (i % 2)))], calibValues[i + 12]), calibValues[(int)2 + ((i / 2) + (2 * (i % 2)))], calibValues[i + 12], 0, 127);
    }
    else {
      definitiveValues[i + 2] = map(constrain(joyRawValues[i], calibValues[i + 12], calibValues[(int)8 + ((i / 2) + (2 * (i % 2)))]), calibValues[i + 12], calibValues[(int)8 + ((i / 2) + (2 * (i % 2)))], 128, 255);
    }
  }
}

void calButCheck() { //calibration button detection
  if (!calPressed && !digitalRead(9)) {
    calPressed = true;
    if (calibrating)
    {
      calibrating = false;
    }
    else {
      calibrating = true;
    }
  }
  else if (digitalRead(9)) {
    calPressed = false;
  }
}

byte * conc(byte val1, byte val2) { // data formatting procedure
  static byte concatenated[DATA_SIZE];
  byte *buttonData = getButtons();
  concatenated[0] = 255 - buttonData[0];
  concatenated[1] = 255 - buttonData[1];
  for (byte i = 0; i < 6; i++) {
    concatenated[i + 2] = definitiveValues[i];
  }
  return concatenated;
}

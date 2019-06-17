unsigned long debouncer[14] = {0};

/*
 * 
 * @func setup Default arduino setup. Initializes EEPROM memory, enables calibration if never attempted,
 * initializes i2c bus, initializes serial communication to client ESP32
 * @param null
 * @return void
 * 
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (byte i = 2; i<14; i++) {
    pinMode(i,INPUT_PULLUP);
  }
}

/*
 * 
 * @func loop Checks for calibration button and flag, then awaits data transfer requests and transmits
 * input data to the client BLE transmitter
 * @param null
 * @return void
 * 
 */

void loop() {
  byte *mainData = getButtons();
  if (Serial.read() == 255) { //if the BLE transmitter has sent a data transfer request, gather values and send them away
    Serial.write(mainData, 2);
  }
}

/*
 * 
 * @func getButtons Concatenates the button values
 * @param null
 * @return byte *
 * 
 */

byte * getButtons() { 
  byte outBuffer[2] = {0};
  for (byte i = 2; i<14; i++) {
    if (debounce(!digitalRead(i), i-2)) {
      if (i-2 < 8) {
        bitSet(outBuffer[0], i-2);
      }
      else {
        bitSet(outBuffer[1], i-10);
      }
    }
    else {
      if (i-2< 8) {
        bitClear(outBuffer[0], i-2);
      }
      else {
        bitClear(outBuffer[1], i-10);
      }
    }
  }
  return outBuffer;
}

/*
 * 
 * @func debounce debounce function for buttons, to avoid double presses on the hardware sie (10ms button press persistance)
 * @param bool button status (true if pressed)
 * @param byte button ID (starts at 0)
 * @return bool processed button status
 * 
 */
bool debounce(bool buttonStatus, byte buttonID) {
    if (buttonStatus) {
      debouncer[buttonID] = millis();
      return true;
    }
    else {
      if (debouncer[buttonID] + 10 > millis()) {
        return true;
      }
      else {
        return false;
      }
    }
}

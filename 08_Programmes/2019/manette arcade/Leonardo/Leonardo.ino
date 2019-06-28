#include <Keyboard.h>

char up_arrow = KEY_UP_ARROW;
char down_arrow = KEY_DOWN_ARROW;
char left_arrow = KEY_LEFT_ARROW;
char right_arrow = KEY_RIGHT_ARROW;
char enter = KEY_RETURN;
char backspace = KEY_BACKSPACE;
unsigned long timeoutTimeTag;
byte playerBind[2] = {0, 0};

static byte oldctrl1[2] = {0b00000000, 0b00000000};
static byte oldctrl2[2] = {0b00000000, 0b00000000};

static char controlMap[][2] = {
  {right_arrow, 'r'},
  {left_arrow, 'e'},
  {down_arrow, 'w'},
  {up_arrow, 'q'},
  {'b', 's'},
  {'n', 'a'},
  {'y', 'p'},
  {'x', 'o'},
  {'c', 'i'},
  {'v', 'u'},
  {backspace, 'z'}, {enter, 't'}
};

/*

   @func setup the default arduino setup. Initializes the serial and the keyboard thru USB interface
   @param null
   @return void

*/

void setup() {
  Serial1.begin(115200);
  Keyboard.begin();
}

/*

   @func loop the default arduino loop. Queries for controllers data and reads them. Binds them as needed. Starts control procedure.
   @param null
   @return void

*/

void loop() {
  byte ctrl1[] = {0, 0};
  byte ctrl2[] = {0, 0};
  Serial1.write(255);
  timeoutTimeTag = millis();
  while (Serial1.available() < 4) {if (millis() > timeoutTimeTag + 300) {
      timeoutTimeTag = millis();
      Serial1.write(255);
    }
  }
  Serial1.readBytes(ctrl1, 2);
  Serial1.readBytes(ctrl2, 2);
  bindControllers(ctrl1, ctrl2);
  if (playerBind[0] == 1 || playerBind[1] == 1) {
    pressControl(ctrl1, ctrl2);
  }
  for (byte i = 0; i < 2; i++) {
    oldctrl1[i] = ctrl1[i];
    oldctrl2[i] = ctrl2[i];
  }
}

/*

   @param bindControllers binds an active controller to an empty slot. Does nothing if both controllers are bound.
   @param byte the first controller's input
   @param byte the second controller's input
   @return void

*/

void bindControllers(byte p1[], byte p2[]) {
  if (playerBind[0] != 0 && playerBind[1] != 0) {
    return;
  }
  if (playerBind[0] == 0 && playerBind[1] == 0) {
    if (bitRead(p1[1], 7)) {
      playerBind[0] = 1;
    }
    else if (bitRead(p2[1], 7)) {
      playerBind[1] = 1;
    }
  }
  else {
    if (playerBind[0] == 0 && bitRead(p1[1], 7)) {
      playerBind[0] = 2;
    }
    else if (playerBind[1] == 0 && bitRead(p2[1], 7)) {
      playerBind[1] = 2;
    }
  }
}

/*

    @func keyPress sends the recommended keypresses
    @param bool true if the key is being pressed, false if released
    @param byte the internal key ID
    @param byte the post-mapping player the input comes from
    @return void

*/

void keyPress(bool effect, byte key, byte player) {
  if (effect) {
    Keyboard.press(controlMap[key][player]);
  }
  else {
    Keyboard.release(controlMap[key][player]);
  }
}

/*

   @func pressControl loops through all the input tables and sends the mapped keypresses to the keyPress function.
   @param byte[] first controller input table
   @param byte[] second controller input table
   @return void

*/

void pressControl(byte ctrl1[], byte ctrl2[]) {
  for (byte i = 0; i < 8; i++) {
    if (bitRead(ctrl1[0], i) != bitRead(oldctrl1[0], i)) {
      if (bitRead(ctrl1[0], i)) {
        keyPress(true, i, playerBind[0] - 1);
      }
      else {
        keyPress(false, i, playerBind[0] - 1);
      }
    }
    if (bitRead(ctrl2[0], i) != bitRead(oldctrl2[0], i)) {
      if (bitRead(ctrl2[0], i)) {
        keyPress(true, i, playerBind[1] - 1);
      }
      else {
        keyPress(false, i, playerBind[1] - 1);
      }
    }
  }
  for (byte i = 0; i < 4; i++) {
    if (bitRead(ctrl1[1], i) != bitRead(oldctrl1[1], i)) {
      if (bitRead(ctrl1[1], i)) {
        keyPress(true, i + 8, playerBind[0] - 1);
      }
      else {
        keyPress(false, i + 8, playerBind[0] - 1);
      }
    }
    if (bitRead(ctrl2[1], i) != bitRead(oldctrl2[1], i)) {
      if (bitRead(ctrl2[1], i)) {
        keyPress(true, i + 8, playerBind[1] - 1);
      }
      else {
        keyPress(false, i + 8, playerBind[1] - 1);
      }
    }
  }
}

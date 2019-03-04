#include "Keyboard.h"

const int APin = 7;
const int BPin = 6;
char capsLock = KEY_CAPS_LOCK;
char Delete = KEY_DELETE;

void setup()
{
  pinMode(APin, INPUT_PULLUP);
  pinMode(BPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop()
{
  if(digitalRead(APin) == LOW)
  {
    Keyboard.press('a');
  }
  else
  {
    Keyboard.release('a');
  }
  if(digitalRead(BPin) == LOW)
  {
    Keyboard.press('b');
  }
  else
  {
    Keyboard.release('b');
  }
}

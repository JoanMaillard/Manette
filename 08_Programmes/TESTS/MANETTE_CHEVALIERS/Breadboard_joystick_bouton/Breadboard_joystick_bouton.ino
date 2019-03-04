/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int sensorPinX = A0;    // Pin pour l'axe X
int sensorPinY = A1;    // Pin pour l'axe Y
int ledPin = 13;        // select the pin for the LED
int sensorValueX = 0;  // variable to store the value coming from the sensor
int sensorValueY = 0;
int joystickButtonPin = 2;
int joystickButtonState = HIGH;
int buttonPin = 4;
int buttonState = HIGH;

void setup() 
{
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(joystickButtonPin, INPUT_PULLUP);
}

void loop() 
{
  // read the value from the sensor:
  sensorValueX = analogRead(sensorPinX);  //Lis et stock la valeur de l'axe X
  sensorValueY = analogRead(sensorPinY);  //Lis et stock la valeur de l'axe Y
  buttonState = digitalRead(buttonPin);
  joystickButtonState = digitalRead(joystickButtonPin);
  Serial.print("X : ");
  Serial.println(sensorValueX);   //Affiche la valeur de X
  Serial.print("Y : ");
  Serial.println(sensorValueY);   //Affiche la valeur de Y
  Serial.println();
  if(joystickButtonState == false || buttonState == false) //Allume la LED intégrée au Nano si un des boutons est appuyé
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, false);
  }
}

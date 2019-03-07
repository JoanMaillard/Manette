#define pinaxis1 0
#define pinb1 2
#define pinb2 3

byte potVal;
bool but1, but2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinaxis1, INPUT);
  pinMode(pinb1,INPUT_PULLUP);
  pinMode(pinb2,INPUT_PULLUP);  
}

void loop() {
  // put your main code here, to run repeatedly:
  but1 = !digitalRead(pinb1);
  but2 = !digitalRead(pinb2);
  potVal = map(analogRead(pinaxis1),0,1023,0,255);
  byte *mainData = conc();
  Serial.write(mainData,3);
}

byte * conc() {
  static byte concatenated[3];
  if (but1) {
    concatenated[0] = 1;
  }
  else 
    concatenated[0] = 0;
  if (but2) {
    concatenated[1] = 1;
  }
  else 
    concatenated[1] = 0;
  concatenated[2] = potVal;
  return concatenated;
}

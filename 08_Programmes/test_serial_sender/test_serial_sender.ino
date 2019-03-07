#define pinaxis1 0
#define pinaxis2 1
#define pinaxis3 2
#define pinb1 2
#define pinb2 3
#define pinb3 4
#define DATA_SIZE 5

byte potVal, potX, potY;
bool but1, but2, but3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinaxis1, INPUT);
  pinMode(pinaxis2, INPUT);
  pinMode(pinaxis3, INPUT);
  pinMode(pinb1,INPUT_PULLUP);
  pinMode(pinb2,INPUT_PULLUP);
  pinMode(pinb3,INPUT_PULLUP);  
}

void loop() {
  // put your main code here, to run repeatedly:
  but1 = !digitalRead(pinb1);
  but2 = !digitalRead(pinb2);
  but3 = !digitalRead(pinb3);
  potVal = map(analogRead(pinaxis1),0,1023,0,255);
  potX = map(analogRead(pinaxis2),0,1023,0,255);
  potY = map(analogRead(pinaxis3),0,1023,0,255);
  byte *mainData = conc();
  Serial.write(mainData,DATA_SIZE);
}

byte * conc() {
  static byte concatenated[DATA_SIZE];
  for (int i = 0; i<DATA_SIZE; i++) {
    concatenated[i]=0;
  }
  //buttons serie 1
  if (but1) {
    concatenated[0]++;
  }
  concatenated[0] = concatenated[0]*2;
  if (but2) {
    concatenated[0]++;
  }
  concatenated[0] = concatenated[0]*2;
  if (but3) {
    concatenated[0]++;
  }
  //buttons serie 2
 if (but3) {
    concatenated[1]++;
  }
  concatenated[1] = concatenated[1]*2;
  if (but2) {
    concatenated[1]++;
  }
  concatenated[1] = concatenated[1]*2;
  if (but1) {
    concatenated[1]++;
  }
  //axies  
  concatenated[2] = potVal;
  concatenated[3] = potX;
  concatenated[4] = potY;
  return concatenated;
}

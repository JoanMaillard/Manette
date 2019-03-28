#define BUFFER_SIZE 8
#define INPUT_PIN

byte dataBuffer[BUFFER_SIZE];
void setup() {
  // put your setup code here, to run once:
  //pinMode(3,INPUT_PULLUP);
  //pinMode(2,OUTPUT);
  Serial.begin(115200);
  Serial3.begin(115200);
  //digitalWrite(2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte dataBufferWrite[2] = {127, 132};
  Serial3.readBytes(dataBuffer,BUFFER_SIZE);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    Serial.print(dataBuffer[i]);
    Serial.print(" ");
  }
  //Serial.print(millis());
  Serial.println("");
  Serial3.write(dataBufferWrite, 2);
  /*if (!digitalRead(3)) {
    reset();
  }//*/
}

/*void reset() {
  digitalWrite(2,LOW);
  delay(100);
  digitalWrite(2,HIGH);
}//*/

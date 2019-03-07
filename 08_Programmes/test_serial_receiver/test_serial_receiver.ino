#define BUFFER_SIZE 8

byte dataBuffer[BUFFER_SIZE];
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  Serial3.begin(19200);
  Serial.begin(2000000);
  //digitalWrite(2,LOW);
  delay(100);
  digitalWrite(2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial3.readBytes(dataBuffer,BUFFER_SIZE);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    Serial.print(dataBuffer[i]);
    Serial.print(" ");
  }
  //Serial.print(millis());
  Serial.println("");
}

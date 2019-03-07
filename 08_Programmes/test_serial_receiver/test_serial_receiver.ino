#define BUFFER_SIZE 8

byte dataBuffer[BUFFER_SIZE];
void setup() {
  // put your setup code here, to run once:
  Serial3.begin(19200);
  Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial3.readBytes(dataBuffer,BUFFER_SIZE);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    Serial.print(dataBuffer[i]);
    Serial.print(" ");
  }
  Serial.print(millis());
  Serial.println("");
}

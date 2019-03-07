byte dataBuffer[3];
void setup() {
  // put your setup code here, to run once:
  Serial3.begin(9600);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial3.readBytes(dataBuffer,3);
  for (int i = 0; i < sizeof(dataBuffer); i++) {
    Serial.println(dataBuffer[i]);
  }
}

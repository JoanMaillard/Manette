byte dataBuffer[1];
byte fullData[250];
void setup() {
  // put your setup code here, to run once:
  Serial3.begin(9600);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i< 250; i++) {
  Serial3.readBytes(dataBuffer,1);
  fullData[i] = dataBuffer[0];
  //Serial.println(dataBuffer[0]);
  }
  for (int i = 0; i < 250; i++) {
  Serial.println(fullData[i]);
  }
}

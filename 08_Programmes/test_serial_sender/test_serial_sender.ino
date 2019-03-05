byte mystr[1] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (mystr[0]<250) {
    Serial.write(mystr,1);
    mystr[0]++;
  }
  mystr[0] = 0;
}

void setup() 
{
  //on démarre la liaison en la réglant à une vitesse de 9600 bits par seconde.
  Serial.begin(9600);
}

void loop() 
{
  char i = 0;
  char lettre_min = 'a';
  char lettre_maj = 'A';

  Serial.println("Coucou voilà l'alphabet");

  for(i=0; i<26; i++)
  {
    Serial.print(lettre_maj);
    lettre_maj = ++lettre_maj;
    Serial.print(lettre_min);
    lettre_min = ++lettre_min;
    Serial.print(' ');
    delay(125);
  }
  Serial.println("");
  Serial.println("");

  delay(2500);
}

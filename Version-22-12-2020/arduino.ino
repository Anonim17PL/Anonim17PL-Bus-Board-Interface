#define  ledPin 13
void setup()
{
  // Ustawianie serial
  while(!Serial);
  Serial.begin(76800);
  Serial.setTimeout(10);
  // Ustawianie pinu 8 jako wyjście
  pinMode(8, OUTPUT);
}

void loop()
{
if(Serial.available()>0){
    int ile=Serial.parseInt();
    switch (ile){
      case 230:
           digitalWrite(9, 0);
      break;
      case 231:
            digitalWrite(9, 1);
      break;
      case 000:
           digitalWrite(8, 0);
      break;
      case 001:
            digitalWrite(8, 1);
      break;
      
    };
Serial.println(ile);
};

};
      

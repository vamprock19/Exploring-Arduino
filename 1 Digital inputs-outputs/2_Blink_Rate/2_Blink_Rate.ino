const int LED = 13;


void setup() 
{
  pinMode(LED, OUTPUT);
  

}

void loop()
{
  for(int i = 100; i < 1000; i++)
  {
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW);
    delay(i);
  }

}

const int LED = 9;
const int button = 2;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);

}

void loop()
{
  if(digitalRead(button) == LOW)
  {
    digitalWrite(LED, LOW);
    
  }
  else
  {
    digitalWrite(LED, HIGH);
  }

}

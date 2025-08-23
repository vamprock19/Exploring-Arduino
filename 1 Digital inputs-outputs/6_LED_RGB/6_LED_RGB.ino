
const int Blue        = 9;
const int Green      = 10;
const int Red        = 11;
const int button     = 2;

int buttonReleased=   -1;
int ledMode =          0;
long oldDelay =        0;
bool ledOn =          false;

void setup() 
{
  pinMode(Blue, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
  Serial.begin(9600);
  
}


void setMode(int Mode)
{
  
  // Red
  if(Mode == 1)
  {
    digitalWrite(Red,HIGH);
    digitalWrite(Green,LOW);
    digitalWrite(Blue,LOW);
  }
  
  // Green
  if(Mode == 2)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Green,HIGH);
    digitalWrite(Blue,LOW);
    
  }
  
  //Blue
  if(Mode == 3)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Green,LOW);
    digitalWrite(Blue,HIGH);
  }
  
  // Purple
  else if(Mode == 4)
  {
    digitalWrite(Red,HIGH);
    digitalWrite(Green,LOW);
    digitalWrite(Blue,HIGH);
  }

  // Cyan
  else if(Mode == 5)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Green,HIGH);
    digitalWrite(Blue,HIGH);
  }
  // Orange
  else if(Mode == 6)
  {
    digitalWrite(Red,HIGH);
    digitalWrite(Green,HIGH);
    digitalWrite(Blue,LOW);
  }
  // White
  else if(Mode == 7)
  {
    digitalWrite(Red,HIGH);
    digitalWrite(Green,HIGH);
    digitalWrite(Blue,HIGH);
  }
 
   // OFF
  if(Mode == 0)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Green,LOW);
    digitalWrite(Blue,LOW);
  }
}

void loop()
{
    int buttonPressed = digitalRead(button);
    long delayInMillis = millis();
   
    if(buttonPressed != buttonReleased && delayInMillis - oldDelay > 50) // true. overflow
    {
      oldDelay = delayInMillis;
      buttonReleased = buttonPressed; // 0
      
      if(buttonPressed == HIGH)
      {
        Serial.println("Button Pressed");
        ledMode++; 
        Serial.println(ledMode);
      }
      buttonReleased = buttonPressed;

      if(ledMode == 8)
      {
        ledMode = 0;
      }
      setMode(ledMode);
    }








    
}

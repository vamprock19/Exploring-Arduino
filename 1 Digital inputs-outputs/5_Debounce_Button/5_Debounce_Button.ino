const int LED        = 9;
const int button     = 2;

int buttonReleased=   -1;
long oldDelay =        0;
bool ledOn =          false;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(LED, LOW);
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
        ledOn = !ledOn; // it changes true / false depending its previous value
        Serial.println(ledOn);
      }
      buttonReleased = buttonPressed;
      digitalWrite(LED, ledOn);
    }
}

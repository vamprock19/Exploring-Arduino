const int LED        = 9;
const int button     = 2;

bool lastButton    = LOW;
bool currentButton = LOW;
bool ledOn =         false;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);


}

 bool debounce(bool last)
  {
    boolean current = digitalRead(button); // reads 2. Reads the button state
    if(last != current)                    // if it's different 
    {
      delay(5);                           // wait 5 mm's
      current = digitalRead(button);      // current = 2
    }
    return current; // it reads 2
  }

void loop()
{
  
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH)
  {
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  digitalWrite(LED, ledOn);
  

}

#include<SoftwareSerial.h>
// Use arduino bluetooth terminal to control the rc car
                // RX,TX
 SoftwareSerial BT(D7,D8); 

#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4

void setup() 
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
 
  BT.begin(9600);
  Serial.begin(9600);
  Serial.println("Bluetooth RC CAR is ready sir");
  
}
void loop()
{
  if(BT.available()) //  true
  {
    char c = BT.read();
    Serial.println(c);

    switch(c)
    {
      case 'f': 
      forward();
      break;  

      case 'b':
      backwards();
      break;

      case 'l':
      left();
      break;

      case 'r':
      right();
      break; 

      case 'p':
      rcStop();
      break;
      
    }
  }
}
void forward()
{
  digitalWrite(IN1, HIGH); // LEFT WHEEL 
  digitalWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  digitalWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  digitalWrite(IN4, HIGH); // RIGH HELL
}
void backwards()
{
  digitalWrite(IN1, LOW); // LEFT WHEEL 
  digitalWrite(IN3, HIGH);  // LEFT WHEEL BACKWARDS
  digitalWrite(IN2, HIGH); // RIGHT WHEEL BAKCWARDS
  digitalWrite(IN4, LOW); // RIGH HELL
 
  
}
void left()
{
  digitalWrite(IN1, LOW); // LEFT WHEEL 
  digitalWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  digitalWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  digitalWrite(IN4, HIGH); // RIGH HELL
}

void right()
{
  digitalWrite(IN1, HIGH); // LEFT WHEEL 
  digitalWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  digitalWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  digitalWrite(IN4, LOW); // RIGH HELL
}

void rcStop()
{
  digitalWrite(IN1, LOW); // LEFT WHEEL 
  digitalWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  digitalWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  digitalWrite(IN4, LOW); // RIGH HELL
}


  

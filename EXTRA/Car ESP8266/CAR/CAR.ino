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

  j
 
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
  analogWrite(IN1, HIGH); // LEFT WHEEL 
  analogWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  analogWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  analogWrite(IN4, HIGH); // RIGH HELL
}
void backwards()
{
  analogWrite(IN1, LOW); // LEFT WHEEL 
  analogWrite(IN3, 180);  // LEFT WHEEL BACKWARDS
  analogWrite(IN2, 180); // RIGHT WHEEL BAKCWARDS
  analogWrite(IN4, LOW); // RIGH HELL
 
  
}
void left()
{
  analogWrite(IN1, LOW); // LEFT WHEEL 
  analogWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  analogWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  analogWrite(IN4, HIGH); // RIGH HELL
}

void right()
{
  analogWrite(IN1, HIGH); // LEFT WHEEL 
  analogWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  analogWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  analogWrite(IN4, 26); // RIGH HELL
}

void rcStop()
{
  analogWrite(IN1, LOW); // LEFT WHEEL 
  analogWrite(IN3, LOW);  // LEFT WHEEL BACKWARDS
  analogWrite(IN2, LOW); // RIGHT WHEEL BAKCWARDS
  analogWrite(IN4, LOW); // RIGH HELL
}


  

#include <SoftwareSerial.h>

// RX, TX (use D1 as RX, D2 as TX)
SoftwareSerial BTserial(D1, D2);

void setup() 
{
  Serial.begin(115200);
  BTserial.begin(9600);   // HC-05 default
  Serial.println("BT on D1/D2");
}

void loop() 
{
  if (BTserial.available()) Serial.write(BTserial.read());
  if (Serial.available()) BTserial.write(Serial.read());
}

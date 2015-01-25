
//transmitting arduino

#include <Servo.h>

Servo myservo; //initialise servo

int pos = 0; // set position to zero

void setup()
{
  Serial.begin(9600); //commence serial comm.
}

void loop()
{
  for(pos = 0; pos <180; pos++)
  {  
    Serial.write(pos); //transmit position of servo over xbee
    delay(15);
  }
  
  for(pos = 180; pos >= 1; pos--)
  {
    Serial.write(pos); //transmit position of servo over xbee
    delay(15);
  }
}

//receiving arduino

#include <Servo.h>

Servo myservo;

int incomingPos; //set variable for incoming data

void setup() 
{  
  Serial.begin(9600); //commence serial comm.
  myservo.attach(9);  //setup servo on pin 9
}

void loop() {

  if (Serial.available() > 0) { //check if data is being transmitted
   
    incomingPos = Serial.read(); //Pass data into variable
    myservo.write(incomingPos); //Pass variable onto servo
  }
}


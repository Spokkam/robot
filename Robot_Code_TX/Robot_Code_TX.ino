//Transmitter 

#include <Servo.h>

int pos1 = 0; // initialise positions for servo 1
int pos2 = 180; // initialise positions for servo 2

const byte PIN_ANALOG_X = 0; // initialise x axis pin
const byte PIN_ANALOG_Y = 1; // initialise y axis pin

char InputRight=3, InputUp=4, InputDown=5, InputLeft=6; // set pins for buttons

void setup()
{
  Serial.begin(9600); // start serial comm.
  
  // Set all four input buttons
  
  pinMode(InputRight, INPUT);      
  digitalWrite(InputRight, HIGH);  
  pinMode(InputUp, INPUT);      
  digitalWrite(InputUp, HIGH);  
  pinMode(InputDown, INPUT);      
  digitalWrite(InputDown, HIGH);  
  pinMode(InputLeft, INPUT);      
  digitalWrite(InputLeft, HIGH);          
}

void loop()
{
  servoControl();
  motorControl();
  delay(100);
}

void servoControl()
{
  if(digitalRead(InputRight) == LOW)
  { 
    pos1 = pos1 + 30; // Increment servo 1 value by 30°
    if (pos1>179) { pos1 = 179; } // sets the upper limit for servo 1
    Serial.write(map(pos1,0,359,0,255)); // send servo 1 value out as a byte
  }
  if(digitalRead(InputLeft) == LOW)
  {
    pos1 = pos1 - 30; // Decrement servo 1 value by 30°
    if (pos1<0) { pos1 = 0; } // sets the lower limit for servo 1
    Serial.write(map(pos1,0,359,0,255)); // send servo 1 value out as a byte
  }
  if(digitalRead(InputUp) == LOW)
  {
    pos2 = pos2 + 30; // Increment servo 2 value by 30°  
    if (pos2>359) { pos2 = 359; } // Set the upper limit for servo 2
    Serial.write(map(pos2,0,359,0,255));  // send servo 2 value out as a byte
  }
  if(digitalRead(InputDown) == LOW)
  {
    pos2 = pos2 - 30; // Decrement servo 2 value by 30°
    if (pos2<180) { pos2 = 180; } // Set the upper limit for servo 2
    Serial.write(map(pos2,0,359,0,255)); // send servo 2 value out as a byte
  }
}


void motorControl()
{
  int throttle = 0; // create throttle variable for y axis
  throttle = analogRead(PIN_ANALOG_Y); // read from y axis pin
  throttle = map(throttle, 0, 1023, -127, 127); // map values within motor speed values
  int Direct = 0; // create direct variable for x axis
  Direct = analogRead(PIN_ANALOG_X); // read from x axis pin
  Direct = map(Direct, 0, 1023, -127, 127); // map values within motor speed values
  
  if(throttle>0 && (Direct >= -50 && Direct <= 50))  /*FORWARDS*/
  {Serial.println("F");}
  
  else if(throttle<0 && (Direct >= -50 && Direct <= 50))  /*BACKWARDS*/
  {Serial.println("B");}
  
  else if (Direct<-50 && throttle>=0)  /*LEFT*/ 
  {Serial.println("L");}
    
  else if (Direct>50 && throttle>=0)  /*RIGHT*/ 
  {Serial.println("R");}
    
  else if (Direct<-50 && throttle<0)  /*LEFT BACKWARDS*/
  {Serial.println("A");}
  
  else if (Direct>50 && throttle<0)   /*RIGHT BACKWARDS*/
  {Serial.println("D");}
  
  else  /*STATIONARY*/
  {Serial.println("S");}
}

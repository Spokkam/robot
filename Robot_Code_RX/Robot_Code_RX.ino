//Receiver 

#include <Servo.h>

Servo myservo1; // set servo 1
Servo myservo2; // set servo 2

int rst = 8; // set rstPin
char msg = ''; // create variable for serial commands

int incomingPos; // set variable for incoming data
int ledPin = 13; // set LedPin

void setup()
{
  Serial.begin(9600); // commence serial comm.
  myservo1.attach(9);  // setup servo on pin 9
  myservo2.attach(10); // setup servo on pin 10
  pinMode(ledPin, OUTPUT); // config ledPin 
  pinMode(rst, OUTPUT); // config rstPin 
  reset(); // call reset function for resetPin on motor controller
}

void loop() {

  if (Serial.available() > 0) { // check if data is being transmitted
    //servoControl(); // call servo function
    motorControl(); // call motor control function
  }
  delay(100);
}

void servoControl()
{
  incomingPos = Serial.read(); //Pass data into variable
    Serial.print("RawIn: "); // check byte value from receiver
    Serial.println(incomingPos);
    incomingPos = map(incomingPos,0,255,0,359); // Turn byte into degrees
    Serial.print("Mapped: ");
    Serial.println(incomingPos);
    
    if(incomingPos < 180 && (incomingPos != 178)){  // x axis
      Serial.print("Xbefore: ");
      Serial.println(incomingPos);
      Serial.print("XAfter: ");
      Serial.println(incomingPos);
      Serial.println("");
      myservo1.write(incomingPos); //Pass variable onto servo
    }
    else if(incomingPos > 180 && (incomingPos != 178)){ // y axis
        Serial.print("Ybefore: ");
        Serial.println(incomingPos);
        incomingPos-=180; // degree values above 180° mapped between 0° & 180°
        Serial.print("YAfter: ");
        Serial.println(incomingPos);
        Serial.println("");
        myservo2.write(incomingPos); //Pass variable onto servo
    }
    else if(incomingPos == 178){
      return; // value 178 indeterminate; ignore
    }
}

void led()
{
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
}

void reset()
{
  digitalWrite(rst, LOW); 
  delay(100); 
  digitalWrite(rst, HIGH); //reset pin must be kept high to operate
  delay(100); 
}

void motorControl()
{
  led(); // flash ledPin to signal data received
  msg = Serial.read();
  // | 0x04 - FORW LEFT, 0x05 BACK LEFT | 0x06 - FORW RIGHT, 0x07 - BACK RIGHT | 
  
  if(msg == 'F'){        /*FORWARDS*/
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x04); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x06); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      Serial.println("Received:" + msg);
    }
    if(msg == 'B'){                              /*Backwards*/
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x05); //motor # and direction, binary: 101
      Serial.write(127); //motor speed  
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x07); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      Serial.println("Received:" + msg);
    }
    if(msg == 'L'){                                  /*LEFT*/
      
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x05); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x06); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      Serial.println("Received:" + msg);
    }
    if(msg == 'R'){                                  /*RIGHT*/
    
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x04); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x07); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      Serial.println("Received:" + msg);
    }
    if(msg == 'A'){                        /*LEFT BACKWARDS*/
      
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x04); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x07); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      Serial.println("Received:" + msg);
    }
    if(msg == 'D'){                        /*RIGHT BACKWARDS*/
      
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x05); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x06); //motor # and direction, binary: 101
      Serial.write(127); //motor speed
      
      Serial.println("Received:" + msg);
    }
    if(msg == 'S'){                          /*STATIONARY*/
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x05); //motor # and direction, binary: 101
      Serial.write(0); //motor speed
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x07); //motor # and direction, binary: 101
      Serial.write(0); //motor speed
      
      Serial.println("Received:" + msg);
    }
}

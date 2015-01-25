int rst = 8; //reset pin of motor controller connected to digital pin 8

const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;

void setup()
{
  pinMode(rst, OUTPUT);

  digitalWrite(rst, LOW); 
  Serial.begin(9600);

  delay(100); 
  digitalWrite(rst, HIGH); //reset pin must be kept high to operate
  delay(100); 
  
}


void loop()
{
  
  int throttle = 0;
  throttle = analogRead(PIN_ANALOG_Y);
  throttle = map(throttle, 0, 1023, -127, 127);
  int Direct = 0;
  Direct = analogRead(PIN_ANALOG_X);
  Direct = map(Direct, 0, 1023, -127, 127);
  int LeftMotor = 0;
  int RightMotor = 0;
  
  if (throttle>0 && Direct == -3) {       /*FORWARDS*/
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x04); //motor # and direction, binary: 101
      Serial.write(throttle); //motor speed
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x06); //motor # and direction, binary: 101
      Serial.write(throttle); //motor speed
  }
  else
  if (throttle<0 && (Direct == -3 || Direct == -4))       /*BACKWARDS*/
  {  
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x05); //motor # and direction, binary: 101
      Serial.write(abs(throttle)); //motor speed  
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x07); //motor # and direction, binary: 101
      Serial.write(abs(throttle)); //motor speed
  }
  else
  if (Direct<-3 && throttle>0)      /*LEFT*/ 
  {  
     LeftMotor = throttle + abs(Direct);
     //motor_left 0x05 & 0x04
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x05); //motor # and direction, binary: 101
     Serial.write(LeftMotor); //motor speed
     
     RightMotor = throttle + abs(Direct);
     //motor_right 0x07 & 0x06
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x06); //motor # and direction, binary: 101
     Serial.write(RightMotor); //motor speed
    
  }
  else
  if (Direct<-100 && throttle == 0)      /*FULL LEFT*/ 
  {  
     //motor_left 0x05 & 0x04
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x05); //motor # and direction, binary: 101
     Serial.write(abs(Direct)); //motor speed
     
     
     //motor_right 0x07 & 0x06
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x06); //motor # and direction, binary: 101
     Serial.write(abs(Direct)); //motor speed
    
  }
  else
  if (Direct>-3 && throttle>0)      /*RIGHT*/ 
  {  
     LeftMotor = throttle + Direct;
     //motor_left 0x05 & 0x04
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x04); //motor # and direction, binary: 101
     Serial.write(LeftMotor); //motor speed
     
     RightMotor = throttle + Direct;
     //motor_right 0x07 & 0x06
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x07); //motor # and direction, binary: 101
     Serial.write(RightMotor); //motor speed
     
  }
  
  else
  if (Direct>100 && throttle == 0)      /*FULL RIGHT*/ 
  {  
     //motor_left 0x05 & 0x04
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x04); //motor # and direction, binary: 101
     Serial.write(Direct); //motor speed
     
     
     //motor_right 0x07 & 0x06
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x07); //motor # and direction, binary: 101
     Serial.write(Direct); //motor speed
     
  }
  else 
  if (Direct<-3 && throttle<0)      /*LEFT BACKWARDS*/
  {
     LeftMotor = throttle + Direct;
     //motor_left 0x05 & 0x04
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x05); //motor # and direction, binary: 101
     Serial.write(0x00); //motor speed
     
     RightMotor = throttle + Direct;
     //motor_right 0x07 & 0x06
     Serial.write(0x80); //start byte
     Serial.write(0x00); //device byte
     Serial.write(0x07); //motor # and direction, binary: 101
     Serial.write(abs(RightMotor)); //motor speed
     
  }
     
  else
  {  /*stationary fixed*/
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x05); //motor # and direction, binary: 101
      Serial.write(0x00); //motor speed
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x07); //motor # and direction, binary: 101
      Serial.write(0x00); //motor speed
  }// end if
 
    Serial.println(String(String("throttle:") + throttle + " "));
    Serial.println(String(String("Direct:") + Direct + " "));
    //delay(500);
   
  
}  // end loop()

 

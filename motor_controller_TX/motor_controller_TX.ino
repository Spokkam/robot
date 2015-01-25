
const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;

void setup()
{
  Serial.begin(9600);  
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
  
  

  if(throttle>0 && (Direct >= -50 && Direct <= 50))  /*FORWARDS*/
  {  
    Serial.println("F"); 
  }
  else if(throttle<0 && (Direct >= -50 && Direct <= 50))  /*BACKWARDS*/
  {
    Serial.println("B");
  }
  else if (Direct<-50 && throttle>=0)  /*LEFT*/ 
  {
    Serial.println("L");
  }
  else if (Direct>50 && throttle>=0)  /*RIGHT*/ 
  {
    Serial.println("R");
  }
  else if (Direct<-50 && throttle<0) /*LEFT BACKWARDS*/
  {
    Serial.println("A");
  }
  else if (Direct>50 && throttle<0) /*RIGHT BACKWARDS*/
  {
    Serial.println("D");
  }
  else  /*STATIONARY*/
  {
    Serial.println("S");
  }
  

  
  //Serial.println(String(String("throttle:") + throttle + " "));
  //Serial.println(String(String("Direct:") + Direct + " "));
  
  delay(250);
}
  
  
  
  
  
  

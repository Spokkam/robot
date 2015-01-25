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
  
  int valY = 0;
  valY = analogRead(PIN_ANALOG_Y);
  valY = map(valY, 0, 1023, -127, 127);
  int valX = 0;
  valX = analogRead(PIN_ANALOG_X);
  valX = map(valX, 0, 1023, 0, 127);
  
  if (valY>0) {       /*forwards*/
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x05); //motor # and direction, binary: 101
      Serial.write(valY); //motor speed
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x07); //motor # and direction, binary: 101
      Serial.write(valY); //motor speed
  }
  else
  if (valY<0)
  {    /*backwards*/
      //motor_left 0x05 & 0x04
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x04); //motor # and direction, binary: 101
      Serial.write(abs(valY)); //motor speed  
      //motor_right 0x07 & 0x06
      Serial.write(0x80); //start byte
      Serial.write(0x00); //device byte
      Serial.write(0x06); //motor # and direction, binary: 101
      Serial.write(abs(valY)); //motor speed
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
  
  
  Serial.println(String(String("y:") + valY + " "));
  delay(1000);
}  // end loop()


int rst = 8; //reset pin of motor controller connected to digital pin 8

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
  //motor_one 0x05 & 0x04

  Serial.write(0x80); //start byte
  Serial.write(0x00); //device byte
  Serial.write(0x05); //motor # binary: 101
  Serial.write(0x3F); //motor speed

  //motor_two 0x07 & 0x06

  Serial.write(0x80); //start byte
  Serial.write(0x00); //device byte
  Serial.write(0x07); //motor # binary: 111
  Serial.write(0x3F); //motor speed '0x3F'

}


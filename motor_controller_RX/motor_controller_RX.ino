int rst = 8; //reset pin of motor controller connected to digital pin 8
char msg = ' '; //contains the message from the arduino transmitter

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
  
  //Note: 0x05 - BACK LEFT, 0x07 - BACK RIGHT
  
  while(Serial.available() > 0) {
    msg = Serial.read();
    
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
    else if(msg == 'S'){                          /*STATIONARY*/
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
}
          


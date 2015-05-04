/********************* MOINEAU PUMP: GUI for Motor Testing (Arduino sketch)*************************  
 * Ligorio Cosimo, University of Pisa, School of Engineering, 2015
 * Last modified date 02/05/2015;
 * 
 * The stepper motor follows the commands received through the serial communication.
 * Every button in the GUI sends a value (char val, in ASCII code) to Arduino Uno. 
 * Arduino reads the value and controls the rotation and speed of the motor. Arduino 
 * Uno board and FE Motor Shield were used. 
 * NOTE: This code allows the motor to rotate counterclockwise (cc).
 
 * This example code is in the public domain.
 */

 /* Declaration of variables */
  char val; 
  int motorPinDirA = 2;
  int motorPinDirB = 8;
  int motorPinPwmA = 3;
  int motorPinPwmB = 9;
  int delayTime; 
 
  /* Initial state of pins*/
 void setup() {
  pinMode(motorPinDirA, OUTPUT);
  pinMode(motorPinDirB, OUTPUT);
  pinMode(motorPinPwmA,OUTPUT);
  pinMode(motorPinPwmB, OUTPUT);
  Serial.begin(9600);
  }
 
  void loop() {
     if(Serial.available()){;
    /*Beginning of serial communication*/
      val = Serial.read();
          }
                 /* Motor Stop*/
                 if(val == 'A'){ 
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, LOW);
                 }    
                
                /* Different speeds. If you change delayTime, you change the speed. Every button 
                 * in the Graphical User Interface is referred to a particular value of delayTime.
                 * Speed No. 1 for btnStart1;
                 */
                if(val == 'a'){
                delayTime = 262;
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);
                    } 
                 
                /*Speed No. 2 for btnStart2 */
                if(val == 'b'){
                delayTime = 131;
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);
                    } 
                 
                /*Speed No. 3 for btnStart3 */   
                if(val == 'c'){
                delayTime = 90;
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);
                    }   
                    
                /*Speed No. 4 for btnStart4 */    
                if(val == 'd'){
                delayTime = 65;
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);
                    }          
                  
                /*Speed No. 5 for btnStart5 */  
                  if(val == 'e'){
                delayTime = 52;
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);
                    }     
          
                /*Speed No. 6 for btnStart6 */
                if(val == 'f'){
                delayTime = 43633;
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delayMicroseconds(delayTime);
                    }    
       
                /* Speed No. 7 for btnStart7 
                 * Indicated as "Trial button"
                 * On 02/05/2015 set for 20 rad/s
                 */ 
                if(val == 'g'){
                delayTime = 6; 
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);
                    } 
                
                /*Speed No. 8 for btnStart8 */ 
                if(val == 'h'){
                delayTime = 25; 
                // 24834 microsecondi: 60 rpm; 
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delay(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delay(delayTime);
                    }  
                    
                /* Speed No. 9 for btnStart9 
                 * 10417 microseconds for 120 rpm; 
                 */ 
                if(val == 'i'){;
                delayTime = 10417; 
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delayMicroseconds(delayTime);
                    }     
                    
                /* Speed No. 10 for btnStart10
                 * 6944 microseconds: 180 rpm; 
                 */
                if(val == 'j'){
                delayTime = 6944; 
                
                digitalWrite(motorPinDirA, HIGH);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, HIGH);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, HIGH);
                digitalWrite(motorPinPwmB, LOW);
                delayMicroseconds(delayTime);

                digitalWrite(motorPinDirA, LOW);
                digitalWrite(motorPinDirB, LOW);
                digitalWrite(motorPinPwmA, LOW);
                digitalWrite(motorPinPwmB, HIGH);
                delayMicroseconds(delayTime);
                    }         
       delay(1);
     }
                  
 
 


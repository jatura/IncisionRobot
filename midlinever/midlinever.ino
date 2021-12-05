// Servo Potentiometer Angle control
// by Mountain A  (www.arduitronics.com)
// www.facebook.com/arduitronics
#include  <Servo.h>
Servo servo1;         // create servo object to control a servo 
Servo servo2;
Servo servo3;
Servo servo4;

int i,j,m1,m2;

float s1=106;
float s2=179;
float s3=175;
float l1=88;
float l2=172;
float l3=165;
float d1=s1-l1;
float d2=s2-l2;
float d3=s2-l2;

void setup() 
{ 
   Serial.println("Motor1");
   servo1.write(s1);
   
   Serial.println("Motor2");
   servo2.write(s2-20);
   
   Serial.println("Motor3");
   servo3.write(s3);
   
  Serial.begin(9600);
  servo1.attach(10);
  servo2.attach(6);
  servo3.attach(11);
  servo4.attach(9);
   
//    Serial.println(0);
    servo4.writeMicroseconds(0); // สั่งให้ Servo หมุนวนขวา
    delay(70); // หน่วงเวลา 2000ms
//    Serial.println("Motor4");
//    servo4.writeMicroseconds(1450); // สั่งให้ Servo หยุด
//    delay(2000); // หน่วงเวลา 2000ms
//    Serial.println(1000);
//    servo4.writeMicroseconds(3000); // สั่งให้ Servo หมุนวนขวาซ้าย
//    delay(50); // หน่วงเวลา 2000ms
//    Serial.println(300);
//    myservo.writeMicroseconds(1450); // สั่งให้ Servo หยุด
//    delay(2000); // หน่วงเวลา 2000ms
//    
//   Serial.println("Motor1");
//   servo1.write(89);
//   
//   Serial.println("Motor2");
//   servo2.write(173);
//   
//   Serial.println("Motor3");
//   servo3.write(160);
for (j=0;j<3;j++){
  for (i = 20; i>0; i--){
    servo2.write(s2-i);
    servo3.write(s3+i);
    delay(100);  
  }
  for (i = 0; i < d1; i++) {
    servo1.write(s1-i);   
   Serial.print("motor1 : ");
   Serial.println(s1-i);  
    m1=d2*i/d1;          
    servo2.write(s2-m1); 
   Serial.print("motor2 : ");
   Serial.println(s2+m1);  
    m2=d3*i/d1;   
    servo3.write(s3+m2);  
   Serial.print("motor3 : ");
   Serial.println(s3+m2);     
    delay(100);                     
  }
   
  for (i = 0; i<40; i++){
    servo2.write(160-i);
    servo3.write(175+i);
    delay(100);  
  }
  for (i = 0; i < 23; i++) {
    servo1.write(l1+i); 
    delay(100);  
  }
}
  
} 
  
void loop() 
{  
}

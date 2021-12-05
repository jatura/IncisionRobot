// Servo Potentiometer Angle control
// by Mountain A  (www.arduitronics.com)
// www.facebook.com/arduitronics
#include  <Servo.h>
Servo servo1;         // create servo object to control a servo 
Servo servo2;
Servo servo3;
Servo servo4;

int i,j,m1,m2;

float l1=123; //point 2
float l2=153;
float l3=147;
float s1=113; //point near 2
float s2=146;
float s3=134;
float n1=109; //point mid
float n2=160;
float n3=147;
float k1=95; //point near 1
float k2=140;
float k3=130;
float h1=90; //point 1
float h2=145;
float h3=140;
float d11=k1-h1; //1 n1
float d12=k2-h2;
float d13=k3-h3;
float d21=n1-k1; //n1 m
float d22=n2-k2;
float d23=n3-k3;
float d31=s1-n1; //m n2
float d32=s2-n2;
float d33=s3-n3;
float d41=l1-s1; //n2 2
float d42=l2-s2;
float d43=l3-s3;

float d=d11+d21+d31+d41;

void setup() 
{ 
   Serial.println("Motor1");
   servo1.write(h1);
   
   Serial.println("Motor2");
   servo2.write(h2-30);
   
   Serial.println("Motor3");
   servo3.write(h3);
   
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
    servo2.write(h2-i);
    servo3.write(h3+i);
    delay(100);  
  }
  for (i = 0; i < d11; i++) {
    servo1.write(h1+i);   
   Serial.print("motor1 : ");
   Serial.println(h1+i);  
    m1=d12*i/d11;          
    servo2.write(h2+m1); 
   Serial.print("motor2 : ");
   Serial.println(h2+m1);  
    m2=d13*i/d11;   
    servo3.write(h3+m2);  
   Serial.print("motor3 : ");
   Serial.println(h3+m2);     
    delay(100);                     
  }
  for (i = 0; i <= d22; i++) {
    m1=d21*i/d22;  
    servo1.write(k1+m1);   
   Serial.print("motor21 : ");
   Serial.println(k1+i);          
    servo2.write(k2+i); 
   Serial.print("motor22 : ");
   Serial.println(k2+m1);  
    m2=d23*i/d22;   
    servo3.write(k3+m2);  
   Serial.print("motor23 : ");
   Serial.println(k3+m2);     
    delay(100);                     
  }
  for (i = 0; i < d31; i++) {
    servo1.write(n1+i);   
   Serial.print("motor1 : ");
   Serial.println(n1+i);  
    m1=d32*i/d31;          
    servo2.write(n2+m1); 
   Serial.print("motor2 : ");
   Serial.println(n2+m1);  
    m2=d33*i/d31;   
    servo3.write(n3+m2);  
   Serial.print("motor3 : ");
   Serial.println(n3+m2);     
    delay(100);                     
  }
  for (i = 0; i < d41; i++) {
    servo1.write(s1+i);   
   Serial.print("motor1 : ");
   Serial.println(s1+i);  
    m1=d42*i/d41;          
    servo2.write(s2+m1); 
   Serial.print("motor2 : ");
   Serial.println(s2+m1);  
    m2=d43*i/d41;   
    servo3.write(s3+m2);  
   Serial.print("motor3 : ");
   Serial.println(s3+m2);     
    delay(100);                     
  }
   
  for (i = 0; i<40; i++){
    servo2.write(160-i);
    servo3.write(l3+i);
    delay(100);  
  }
  for (i = 0; i < d; i++) {
    servo1.write(l1-i); 
    delay(100);  
  }
}
  
} 
  
void loop() 
{  
}

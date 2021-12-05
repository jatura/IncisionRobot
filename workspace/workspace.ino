// Servo Potentiometer Angle control
// by Mountain A  (www.arduitronics.com)
// www.facebook.com/arduitronics
#include  <Servo.h>
Servo servo1;         // create servo object to control a servo 
Servo servo2;
Servo servo3;
Servo servo4;

int i,j,m1,m2;

float l1=0; //right top
float l2=30;
float l3=160;

float s1=0; //right bot
float s2=150;
float s3=30;

float n1=0; //right far
float n2=150;
float n3=160;

float k1=179; //left far
float k2=150;
float k3=160;

float h1=179; //left top
float h2=30;
float h3=160;

float w1=179; //left bot
float w2=150;
float w3=30;

//float d11=k1-h1; //1 n1
//float d12=k2-h2;
//float d13=k3-h3;
//float d21=n1-k1; //n1 m
//float d22=n2-k2;
//float d23=n3-k3;
//float d31=s1-n1; //m n2
//float d32=s2-n2;
//float d33=s3-n3;
//float d41=l1-s1; //n2 2
//float d42=l2-s2;
//float d43=l3-s3;

//float d=d11+d21+d31+d41;
int d1=179,d2=120,d3=130;
void setup() 
{ 
   Serial.println("Motor1");
   servo1.write(l1);
   
   Serial.println("Motor2");
   servo2.write(l2);
   
   Serial.println("Motor3");
   servo3.write(l3);
   
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

//for (j=0;j<3;j++){
  for (i = 0; i<d3; i++){  //rt rb
    servo2.write(l2+(d2*i/d3));
   Serial.print("motor12 : ");
   Serial.println(l2+i);
    servo3.write(l3-i); 
   Serial.print("motor13 : ");
   Serial.println(l3-i);
    delay(30);  
  }
  for (i = 0; i < d3; i++) { //rb rf
    servo3.write(s3+i);     
   Serial.print("motor23 : ");
   Serial.println(s3+i); 
    delay(30);             
  }
  for (i = 0; i < d2; i++) {  //rf rt
    servo2.write(n2-i);     
   Serial.print("motor32 : ");
   Serial.println(n2-i);
    delay(30);                
  }
  for (i = 0; i<d3; i++){  //rt rb
    servo2.write(l2+(d2*i/d3));
   Serial.print("motor12 : ");
   Serial.println(l2+i);
    servo3.write(l3-i); 
   Serial.print("motor13 : ");
   Serial.println(l3-i);
    delay(30);  
  }
  for (i = 0; i < d3; i++) { //rb rf
    servo3.write(s3+i);     
   Serial.print("motor23 : ");
   Serial.println(s3+i); 
    delay(30);                
  }
  for (i = 0; i < d1; i+=3) { //rf lf
    servo1.write(n1+i);  
   Serial.print("motor51 : ");
   Serial.println(n1+i);  
    delay(30);              
  }
  for (i = 0; i < d2; i++) {     //lf lt
    servo2.write(k2-i);    
   Serial.print("motor62 : ");
   Serial.println(k2-i);
    delay(30);              
  }
  for (i = 0; i<d3; i++){ //lt lb
    servo2.write(h2+(d2*i/d3));
   Serial.print("motor72 : ");
   Serial.println(h2+i);
    servo3.write(h3-i); 
   Serial.print("motor73 : ");
   Serial.println(h3-i);
    delay(30);  
  }
  for (i = 0; i < d3; i++) { //lb lf
    servo3.write(w3+i);  
   Serial.print("motor83 : ");
   Serial.println(w3+i);
    delay(30);  
  }
  for (i = 0; i < d2; i++) {     //lf lt
    servo2.write(k2-i);    
   Serial.print("motor92 : ");
   Serial.println(k2-i);
    delay(30);       
  }
  for (i = 0; i < d1; i+=3) {     //lt rt
    servo1.write(h1-i);  
   Serial.print("motor101 : ");
   Serial.println(h1-i);    
    delay(30);             
  }
//}
  
} 
  
void loop() 
{  
}

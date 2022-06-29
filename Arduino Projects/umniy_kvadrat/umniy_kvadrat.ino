#include <Servo.h>
Servo x;
Servo y;
Servo z;
void setup() {
x.attach(5);
y.attach(3);
z.attach(6);

}

void loop() {

text();
}
void text(){
 z.write(40);
delay(500);
  x.write(170);
  y.write(60);
    delay(100);
  z.write(150);
  delay(500);
  for (int i=60; i>10; i-=1){
 y.write(i);
 delay(50);   
  }
  delay(100);
   for (int i=170; i>150; i-=1){
 x.write(i);
 delay(50);   
  }
  for (int i=10; i<60; i+=1){
 y.write(i);
 delay(50);   
  }
  delay(100);
   for (int i=150; i<170; i+=1){
 x.write(i);
 delay(50);   
  }
 z.write(40);
delay(500);
  x.write(170);
  y.write(35);
    delay(100);
  z.write(150);
  delay(500);
  delay(100);
   for (int i=170; i>150; i-=1){
 x.write(i);
 delay(50);   
  }
   z.write(40);
delay(500);
  x.write(140);
  y.write(60);
    delay(100);
  z.write(150);
  delay(500);
  for (int i=60; i>10; i-=1){
 y.write(i);
 delay(50);   
  }
    for (int i=140; i>120; i-=1){
 x.write(i);
 delay(50);   
  }
    for (int i=10; i<35; i+=1){
 y.write(i);
 delay(50);   
  }
    for (int i=120; i<140; i+=1){
 x.write(i);
 delay(50);   
  }
}
/* void kvadrat(){
  z.write(40);
  delay(500);
  x.write(160);
  y.write(160);
    delay(1000);
  z.write(150);
  delay(500);
  for (int i=160; i>10; i-=2){
 y.write(i);
 delay(50);   
  }
  delay(100);
    for (int i=160; i>10; i-=2){
 x.write(i);
 delay(50);   
  }
  z.write(40);
  delay(500);
  x.write(160);
  y.write(160);
    delay(1000);
  z.write(150);
  delay(500);
   for (int i=160; i>10; i-=2){
 x.write(i);
 delay(50);   
  }
  
    for (int i=160; i>10; i-=2){
 y.write(i);
 delay(50);   
  }
  
}
*/


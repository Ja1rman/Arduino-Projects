#include <Servo.h>
Servo x;
Servo y;
int q;
void setup() {
x.attach(5);
y.attach(3);
circle();
}

void loop() {

}

void circle(){
  for (int i=150; i>90;i-=2){
      y.write(i-60);
      x.write(i);
     delay(50);

    }

    //delay(50);
  
  
}


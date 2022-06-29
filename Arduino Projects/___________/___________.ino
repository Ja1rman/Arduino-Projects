#include <Servo.h>         
Servo z;
Servo x;
Servo c;
Servo v;

int o;
int p;

void setup() {
z.attach(8); 
x.attach(9);
c.attach(10); 
v.attach(11); 
}

void loop() {
 int ffa1=analogRead(A2);
 ffa1=map(ffa1,0,1023,0,180); 
 x.write(ffa1);
 int ffa4=analogRead(A3);
 ffa4=map(ffa4,0,1023,0,90 );
 v.write(ffa4);
gjo();
z.write(o);
c.write(p);
}
void gjo(){
  int vrx=analogRead(A0);
  if (vrx<300) o--;
  if (vrx>700) o++;
 if (o<=0) o=0;
   if (o>=180) o=180;
  int vry=analogRead(A1);
  if (vry<300) p--; 
  if (vry>700) p++;
  if (p<=0) p=0;
  if (p>=180) p=180;  
}



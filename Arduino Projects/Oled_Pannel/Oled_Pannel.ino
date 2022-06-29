#include <iarduino_OLED.h>
iarduino_OLED oled (0x3C);
int x,y;
int z,c;
void setup() {
oled.begin();
oled.autoUpdate(LOW);
  z=random(120);
  c=random(50);
}

void loop() {
  eda();
 zm();

}
void eda(){
  if (x==z && y==c || x+2==z && y+2==c || x-2==z && y-2==c){
   oled.clrScr();
     z=random(122);
  c=random(58);
}

  oled.drawCircle(z,c,9,1,1);
  
}
void zm(){
  oled.update();
  oled.clrScr();
oled.drawCircle(x,y,5,0,0);

djo();

oled.drawCircle(x,y,5,1,1);
}
void djo(){
 int vrx=analogRead(A0);
  int vry=analogRead(A1);
  if (vrx<300) y+=2;
  if(vrx>700) y-=2;  
if (vry<300) x-=2;
  if(vry>700) x+=2;
    if (x>122) x=122;
  if(y>58) y=58;  
if (x<5) x=5;
if (y<5) y=5;
  
}


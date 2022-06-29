#include <iarduino_OLED.h>
iarduino_OLED oled (0x3C);
int z=0;
int x;
int y;
int v;
int b;
int n;
int m;
int k;
int h;
int vv;
int bb;
int nn;
int mm;
int kk;
int hh;
unsigned long previousMillis = 0;    
const long interval = 7000; 
void setup() {
Serial.begin(9600);
oled.begin();
oled.autoUpdate(LOW);
y=32;
x=32;
v=108;
n=128;
k=random(0,20);
h=random(40,64);
b=random(15,30);
m=n+b;
vv=108;
nn=128;
kk=random(0,20);
hh=random(40,64);
bb=random(15,30);
mm=nn+bb;
}
void loop() { 
  unsigned long currentMillis = millis();
int a=digitalRead(3);
Serial.println(a);    

  oled.clrScr();
if (a==0) {
    y=y+1; 
}
  else if (a==1) {
    y=y-1;   
  } 
  if (x>122){
    x=122;
  }
    if (y>58){
    y=58;
  }
    if (x<6){
    x=6;
  }
    if (y<6){
    y=6;
  }
oled.drawCircle(x,y,5,1,1);


pp();

 if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    z=1;
    
  }
  if(z==1){
    rr();
  }
  
oled.update();
}
void pp(){
  v=v-1;
n=n-1;
if (m<-20){
v=108;
n=128;
k=random(10,30);
h=random(30,64);
b=random(15,30);
}
m=n+b;
oled.drawRect(v,0,n,k,0,1);
oled.drawRect(m,h,m+20,64,0,1);
}

void rr(){
  vv=vv-1;
nn=nn-1;
if (mm<-20){
vv=108;
nn=128;
kk=random(10,30);
hh=random(30,64);
bb=random(15,30);
}
mm=nn+bb;
oled.drawRect(vv,0,nn,kk,0,1);
oled.drawRect(mm,hh,mm+20,64,0,1);
oled.update();
}
void rrr(){
  vvv=vvv-1;
nnn=nnn-1;
if (mmm<-20){
vvv=108;
nnn=128;
kkk=random(10,30);
hhh=random(30,64);
bbb=random(15,30);
}
mm=nn+bb;
oled.drawRect(vvv,0,nnn,kkk,0,1);
oled.drawRect(mmm,hhh,mmm+20,64,0,1);
oled.update();
}

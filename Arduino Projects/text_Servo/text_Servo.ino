#include <Servo.h>
Servo x;
Servo y;
Servo z;
int i;
void setup() {
x.attach(10);
y.attach(9);
z.attach(11);
nop();
}
void loop(){

}
void nop(){

z.write(40);
delay(500);
x.write(20);
y.write(140);
delay(500);
z.write(130);
delay(500);

for (i=140; i>40; i--){
y.write(i);
delay(50);
}
for (i=20; i<40; i++){
x.write(i);
delay(50);
}
for (i=40; i<140; i++){
y.write(i);
delay(50);
}
z.write(40);
delay(500);
x.write(42);
y.write(140);
delay(500);
z.write(130);
delay(500);
for (i=140; i>40; i--){
y.write(i);
delay(50);
}
for (i=42; i<62; i++){
x.write(i);
delay(50);
}
for (i=40; i<140; i++){
y.write(i);
delay(50);
}
z.write(40);
delay(500);
x.write(62);
y.write(90);
delay(500);
z.write(130);
delay(500);
for (i=62; i>42; i--){
x.write(i);
delay(50);
}




z.write(40);
delay(500);
x.write(64);
y.write(140);
delay(500);
z.write(130);
delay(500);

for (i=140; i>40; i--){
y.write(i);
delay(50);
}
for (i=42; i<86; i++){
x.write(i);
delay(50);
}
for (i=40; i<140; i++){
y.write(i);
delay(50);
}
z.write(40);
delay(500);
x.write(88);
y.write(140);
delay(500);
z.write(130);
delay(500);
for (i=140; i>40; i--){
y.write(i);
delay(50);
}
for (i=88; i<108; i++){
x.write(i);
delay(50);
}
for (i=40; i<140; i++){
y.write(i);
delay(50);
}
z.write(40);
delay(500);
x.write(108);
y.write(90);
delay(500);
z.write(130);
delay(500);
for (i=108; i>88; i--){
x.write(i);
delay(50);
}
}


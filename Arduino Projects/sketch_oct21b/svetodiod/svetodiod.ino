#include <Ultrasonic.h>
#include <Adafruit_NeoPixel.h> 
Ultrasonic ultrasonic(12,13);
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(8,4,NEO_GRB+NEO_KHZ800);
void setup() {
Serial.begin(9600);
pixels.begin();
}

void loop() {
  int q=random(0,255);
  int w=random(0,255);
  int e=random(0,255);
float a=ultrasonic.Ranging(CM);
delay(100);
if(a<20){
for (int i=0; i<8; i++){
pixels.setPixelColor(i,pixels.Color(q,w,e));
delay(50);
pixels.show();
}
}
}

#include <SPI.h>

#include <Adafruit_GFX.h>

#include <Max72xxPanel.h>

Max72xxPanel matrix=Max72xxPanel(9,2,1);
void setup() {
  matrix.setIntensity(4); 
for(int x2=0; x2<7;   x2++) {

  
 matrix.drawPixel(x2,x2,1);
  matrix.drawPixel(x2+1,x2,1);
    matrix.drawPixel(x2,x2+1,1);
   matrix.drawPixel(x2+1,x2+1,1);
 matrix.write(); 
 delay(500);
  matrix.drawPixel(x2,x2,0);
   matrix.drawPixel(x2+1,x2,0);
 matrix.drawPixel(x2,x2+1,0);
   matrix.drawPixel(x2+1,x2+1,0);
matrix.drawPixel(6,6,0);
}
 

}

void loop() {

  int k=6;
  int l=6;


 matrix.drawPixel(6,7,1);
  matrix.drawPixel(7,7,1);
    matrix.drawPixel(7,6,1);
   matrix.drawPixel(6,6,1);
 matrix.write(); 
  delay(500);
  matrix.drawPixel(k,l,1);
  matrix.write();
  
for(int x2=7; x2<14;   x2++) {
 matrix.drawPixel(x2+1,x2-7,1);
 matrix.write();
  delay(500);
  matrix.drawPixel(x2+1,x2-7,0);

} 
matrix.drawPixel(15,7,1);
   matrix.write(); 
   for(int x2=7; x2<14;   x2++) {
 matrix.drawPixel(x2+1,x2-7,1);
 matrix.write();
  delay(500);
  matrix.drawPixel(x2+1,x2-7,0);
   }
   matrix.drawPixel(15,6,1);
   matrix.write(); 
      for(int x2=7; x2<14;   x2++) {
 matrix.drawPixel(x2+1,x2-7,1);
 matrix.write();
  delay(500);
  matrix.drawPixel(x2+1,x2-7,0);
   }
   matrix.drawPixel(14,7,1);
   matrix.write(); 
      for(int x2=7; x2<14;   x2++) {
 matrix.drawPixel(x2+1,x2-7,1);
 matrix.write();
  delay(500);
  matrix.drawPixel(x2+1,x2-7,0);
   }
   matrix.drawPixel(14,6,1);
   matrix.write(); 
}

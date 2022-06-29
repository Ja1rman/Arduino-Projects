#include <iarduino_OLED.h>
#include <Ultrasonic.h>
#include <Servo.h>

iarduino_OLED oled(0x3C);
Ultrasonic ultra(12, 13);
Servo servo;

void setup() 
{
  oled.begin();
  servo.attach(9);
  oled.autoUpdate(false);
  Serial.begin(9600);
}

void loop() 
{
  int arr[180];
  oled.clrScr();
  for (int i = 0; i < 180; i++)
  {
    
    int count = ultra.read(CM);
    
    if (count > 30)
      count = 30;
    else if (count < 3)
      count = 3;

    count = map(count, 3, 30, 0, 45);
    servo.write(i);
    Serial.print(i); 
    Serial.print(","); 
    Serial.print(count); 
    Serial.print("."); 

    arr[i] = count;

    oled.drawCircle(64, 0, 50, 0, 1);
    oled.drawLine(64, 0, i, count, 1);
    oled.update();
  }
  oled.clrScr();
  delay(500);
  int arr2[180];
  
  for (int i = 180; i > 0; i--)
  {
    
    int count = ultra.read(CM);
    
    if (count > 30)
      count = 30;
    else if (count < 3)
      count = 3;

    count = map(count, 3, 30, 0, 45);
    servo.write(i);
    Serial.print(i); 
    Serial.print(","); 
    Serial.print(count); 
    Serial.print("."); 

    arr2[i] = count;

    oled.drawCircle(64, 0, 50, 0, 1);
    oled.drawLine(64, 0, i, count, 1);
    oled.update();
  }
}

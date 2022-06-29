#include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic u(12, 13);
Servo s;
int dis_point = 13;
int period = 50;
int time;
float error = 0, prev_error = 0, dis_error = 0;
float P = 0, I = 0, D = 0, PID = 0;
float kp = 1.1, ki = 0.2, kd = 14;
float distance = 0;

void setup() 
{
  Serial.begin(9600);
  s.attach(9);
  time = millis();
}

void loop() 
{
  if (millis() > time + period){
    time = millis();        
    float sum = 0;
    for (int i = 0; i < 80; i++)
    {
      distance = u.read(CM);
      if (distance > 21) distance = 21;
      if (distance < 4) distance = 4;
      sum = sum + distance;
    }
    distance = sum / 80;
    error = dis_point - distance;
    dis_error = error - prev_error;
    P = kp * error;
    D = kd * (dis_error / period);
    if (-3 < dis_error&&dis_error < 3) I = I + (ki * dis_error);
    else I = 0;
    PID = P + I + D;
    if (PID > 20) PID = 20;
    if (PID < -20) PID = -20;
    PID = map(PID, -20, 20, 120, 70);
    s.write(PID - 10);
    prev_error = error;
  }
}

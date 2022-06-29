#define trick 3
#define le 7
#define fe 8
#define re 5
#define motor1 9
#define motor2 10
#define motor3 11
#define motor4 12

long durl, durf, durr;
float cmLeft, cmForward, cmRight;

void Back();
void left();
void right();
void forward();

void setup() {
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
 pinMode(12, OUTPUT);
 pinMode(9, OUTPUT);
 Serial.begin(9600);
}

void loop() {
 digitalWrite(trick, LOW);
 delayMicroseconds(5);
 digitalWrite(trick, HIGH);
 delayMicroseconds(10);
 digitalWrite(trick, LOW);
 delayMicroseconds(5);

 durl = pulseIn(le, HIGH);
 cmLeft = (durl/58.2);
 digitalWrite(trick, LOW);
 delayMicroseconds(5);
 digitalWrite(trick, HIGH);
 delayMicroseconds(10);
 digitalWrite(trick, LOW);
 delayMicroseconds(5);
 
 durf = pulseIn(fe, HIGH);
 cmForward = (durf/58.2);
 digitalWrite(trick, LOW);
 delayMicroseconds(5);
 digitalWrite(trick, HIGH);
 delayMicroseconds(10);
 digitalWrite(trick, LOW);
 delayMicroseconds(5);
 
 durr = pulseIn(re, HIGH);
 cmRight = (durr/58.2);
 digitalWrite(trick, LOW);
 delayMicroseconds(5);
 digitalWrite(trick, HIGH);
 delayMicroseconds(10);
 digitalWrite(trick, LOW);
 delayMicroseconds(5);

  int d1 = analogRead(A0);
  int d2 = analogRead(A1);

  if (d1 > 120 && d2 > 120) {

     Back();
     delay(2000);
     left();
     delay(1000);
    
  } 
  else if(d1 > 120) {

    right();
    delay(1000);
    
  }
  else if(d2 > 120) {

    left();
    delay(1000);
    
  }


  if(cmForward < 40) {

    right();
    delay(1000);
    forward();
    delay(1000);
    left();
    delay(1000);

    while(cmLeft > 40) {
      
      forward();

      if(d1 > 120 || d2 > 120) break;
      
    }
    
  }
    if(cmLeft < 40){

    while(cmForward > 40) left();

    while(cmForward < 40) {
      
      forward();

      if(d1 > 120 || d2 > 120) break;
      
    }
      
  }
  else if(cmRight < 40) {
    
    while(cmForward > 40) right();

    while(cmForward < 40) {
      
      forward();

      if(d1 > 120 || d2 > 120) break;
      
    }
    
  } 
  else {

    while(cmLeft > 40 || cmRight > 40) left();
    
  }
  
   
}

void forward(){

  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  
}

void Back(){

  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  
}

void left(){

  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  
}

void right(){

  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  
}


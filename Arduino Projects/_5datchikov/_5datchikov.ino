int A;
int B;
int v1;
int v2;
int v3;
int v4;
int v5;
void setup() {
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
proverka();

}

void loop() {
 v1=analogRead(A1);
 v2=analogRead(A2);
 v3=analogRead(A3);
 v4=analogRead(A4);
 v5=analogRead(A5);
 maths();
if ( (v1==1) && (v2==0) && (v3==0) && (v4==0) && (v5==1) ){
  forward();
}
else if ( (v1==1) && (v2==1) && (v3==0) && (v4==0) && (v5==1) ){
  forward();
}
else if ( (v1==0) && (v2==0) && (v3==0) && (v4==1) && (v5==1) ){
 reversleft(); 
} 
else if ( (v1==1) && (v2==1) && (v3==0) && (v4==0) && (v5==0) ){
 reversright();
}
else if ( (v1==1) && (v2==1) && (v3==1) && (v4==1) && (v5==0) ){
 right();
}
else if ( (v1==0) && (v2==1) && (v3==1) && (v4==1) && (v5==1) ){
 left();
}
else vpered();
 }

 void proverka(){
 v1=analogRead(A1);
 v2=analogRead(A2);
 v3=analogRead(A3);
 v4=analogRead(A4);
 v5=analogRead(A5); 
     A=(v1+v2+v3+v4+v5)/5;
     delay(5000);
 v1=analogRead(A1);
 v2=analogRead(A2);
 v3=analogRead(A3);
 v4=analogRead(A4);
 v5=analogRead(A5); 
     B=(v1+v2+v3+v4+v5)/5; 
 }

void maths(){

 v1=map(v1,A,B,0,1);
  v2=map(v2,A,B,0,1);
   v3=map(v3,A,B,0,1);
    v4=map(v4,A,B,0,1);
     v5=map(v5,A,B,0,1);
}
void reversleft(){
  digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
    digitalWrite(10,LOW);
     digitalWrite(11,LOW);  
}
void reversright(){
  digitalWrite(8,LOW);
   digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
     digitalWrite(11,LOW);  
}
void left (){
  digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
     digitalWrite(11,LOW);
}
void forward (){
  digitalWrite(8,HIGH);
   digitalWrite(9,LOW);
    digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
}
void nazad (){
  digitalWrite(8,LOW);
   digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
     digitalWrite(11,LOW);
}
void right(){
  digitalWrite(8,LOW);
   digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
}
void Stop(){
  digitalWrite(8,LOW);
   digitalWrite(9,LOW);
    digitalWrite(10,LOW);
     digitalWrite(11,LOW);

}


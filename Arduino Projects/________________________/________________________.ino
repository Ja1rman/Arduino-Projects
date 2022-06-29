void setup() {
  Serial.begin (9600);

}

void loop() {
int vedro1=analogRead(A1);
int vedro2=analogRead(A2);
int vedro3=analogRead(A3);
int vedro4=analogRead(A4);
int vedro5=analogRead(A5);

if (vedro1<500){
  Serial.print ("1 ");
}
else {
  Serial.print("0 ");
}
if (vedro2<500){
  Serial.print ("1 ");
}
else {
  Serial.print("0 ");
}
if (vedro3<500){
  Serial.print ("1 ");
}
else {
  Serial.print("0 ");
}
if (vedro4<500){
  Serial.print ("1 ");
}
else {
  Serial.print("0 ");
}
if (vedro5<500){
  Serial.print ("1 ");
}
else {
  Serial.print("0 ");
}
Serial.println (" ");
}

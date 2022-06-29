int b;
unsigned long previousMillis = 0;      
const long interval = 60000;  
void setup() {
Serial.begin(9600);
}
void loop() {
int k=analogRead(A0);
if (k<200){
b=b+1;
}
unsigned long currentMillis = millis();
if (currentMillis - previousMillis >= interval) {
previousMillis = currentMillis;
Serial.println(b) ;     
b=0;
}
}


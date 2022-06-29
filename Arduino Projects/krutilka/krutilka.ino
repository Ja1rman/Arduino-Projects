int DT;
int CLK;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {
  DT = digitalRead(2);
  CLK = digitalRead(3);
  if (DT != CLK)
  {
    Serial.print("DT:");
    Serial.print(digitalRead(2));
    Serial.print(" ");
    Serial.print("CLK:");
    Serial.println(digitalRead(3));
  }
  DT = CLK;
}

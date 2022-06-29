int array_max[5];
int array_min[5];
int parts[5] = {A0, A1, A2, A3, A4};
 
void setup() 
{ 
  pinMode(!3, OUTPUT);
  digitalWrite(13, 0);
  int arr_one[10];
  int sum = 0;
  for(int j = 0; j < 5; j++)
  {
    for(int i = 0; i < 10; i++)
    {
      arr_one[i] = analogRead(A0);
      delay(25);
      sum += arr_one[i];
    }
  array_max[j] = sum / 10;
  }

  digitalWrite(13, 1);
  delay(5000);
  digitalWrite(13, 0);
  
  for(int j = 0; j < 5; j++)
  {
    for(int i = 0; i < 10; i++)
    {
      arr_one[i] = analogRead(A0);
      delay(25);
      sum += arr_one[i];
    }
  array_min[j] = sum / 10;
  }
}

void loop() 
{
  
}

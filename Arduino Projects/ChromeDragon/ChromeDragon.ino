#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

uint8_t dragon[8]  = { B00000,
                         B00000,
                         B00000,
                         B00011,
                         B00110,
                         B11111,
                         B01110,
                         B01010 };

uint8_t kaktus[8]  = { B00000,
                       B00000,
                       B00000,
                       B01100,
                       B11100,
                       B01110,
                       B11100,
                       B01100 };

uint8_t kaktus2[8]  = {B00000,
                       B00100,
                       B10100,
                       B10101,
                       B01101,
                       B00110,
                       B00100,
                       B00100 };         
                         
void setup() 
{
  lcd.init();  
  lcd.backlight();

  lcd.createChar(0, dragon);
  lcd.createChar(1, kaktus);
  lcd.createChar(2, kaktus2);
}

void loop() 
{
  int Numrandom = random(1, 3);
  int Numrandom2 = random(1, 3);
  int Numrandom3 = random(1, 3);
  int Numrandom4 = random(1, 3);
  int Numrandom5 = random(1, 3);
  int Numrandom6 = random(1, 3);
  int Numrandom7 = random(1, 3);
  int Numrandom8 = random(1, 3);

  int distrandom = random(2, 5);
  int distrandom2 = random(2, 5);
  int distrandom3 = random(2, 5);
  int distrandom4 = random(2, 5);
  int distrandom5 = random(2, 5);
  int distrandom6 = random(2, 5);
  int distrandom7 = random(2, 5);
  int distrandom8 = random(2, 5);


  
  int kolvorandom = random(1, 4);
  int now = 20;
  int res = 1;
  int y = 1;
  while (res != 0)
  {
    lcd.setCursor(now, y);
    lcd.print(char(Numrandom));
    
    lcd.setCursor(now + distrandom, y);
    lcd.print(char(Numrandom2));

    lcd.setCursor(now + distrandom + distrandom2, y);
    lcd.print(char(Numrandom3));

    lcd.setCursor(now + distrandom + distrandom2 + distrandom3, y);
    lcd.print(char(Numrandom4));

    lcd.setCursor(now + distrandom + distrandom2 + distrandom3 + distrandom4, y);
    lcd.print(char(Numrandom5));

    lcd.setCursor(now + distrandom + distrandom2 + distrandom3 + distrandom4 + distrandom5, y);
    lcd.print(char(Numrandom6));

    lcd.setCursor(now + distrandom + distrandom2 + distrandom3 + distrandom4 + distrandom5 + distrandom6, y);
    lcd.print(char(Numrandom7));

    lcd.setCursor(now + distrandom + distrandom2 + distrandom3 + distrandom4 + distrandom5 + distrandom6 + distrandom7, y);
    lcd.print(char(Numrandom8));
    
    lcd.setCursor(2, y);
    lcd.print(char(0));
    now--;
    delay(1000);
    lcd.clear();
  }    
}

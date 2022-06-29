#include <LiquidCrystal_I2C.h>
#include <iarduino_RTC.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

iarduino_RTC time(RTC_DS1302, 8, 6, 7);
void setup() {
  lcd.init();
  lcd.backlight();
  delay(300);                                            // задержка в 300мс перед началом инициализации
  Serial.begin(9600);                              // устанавливаем скорость передачи данных с модулей в 9600 бод
  time.begin();                                       // функция служит для инициализации работы модуля
// Ниже у нас прописываются временные значения в виде секунд, минут, часов, даты, включая месяц и год, и также можете указать день недели
  time.settime(10,10,10,4,10,20,3);  // 10  сек, 10 мин, 10 час, 4 , октября, 2017 года, среда 
}   
void loop(){
    lcd.setCursor(0, 0);
    lcd.print(time.gettime("d-m-Y"));   // выводим время
    lcd.setCursor(0, 1);
    lcd.print(time.gettime("H:i:s, D"));
    Serial.println(time.gettime("d-m-Y, H:i:s, D"));
    delay(1000);  // делаем небольшую задержку, чтобы не выводить время слишком часто 
  
}

#include <Wire.h>                             // библиотека для протокола IIC
#include <LiquidCrystal_I2C.h>        // подключаем библиотеку LCD IIC
LiquidCrystal_I2C LCD(0x27, 20, 4); // присваиваем имя lcd для дисплея

int level = 1;       // переменная для отсчета уровня
int pause = 400; // переменная для задержки
byte p = 0;          // переменная для времени прыжка

// создаем массивы дракончика, дерева, камня и птицы
byte derevo228[8] = {
 0b00000, 0b00000, 0b00000, 0b11011, 0b11011, 0b11011, 0b01100, 0b01100
};
byte kamen228[8] = {
 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b01110, 0b11111
};
byte ptica[8] = {
 0b00100, 0b00101, 0b01111, 0b11111, 0b10100, 0b00100, 0b00000, 0b00000
};
uint8_t dracon[8]  = { B00000,
                         B00000,
                         B00000,
                         B00011,
                         B00110,
                         B11111,
                         B01110,
                         B01010 };

uint8_t kamen[8]  = { B00000,
                       B00000,
                       B00000,
                       B01100,
                       B11100,
                       B01110,
                       B11100,
                       B01100 };

uint8_t derevo[8]  = {B00000,
                       B00100,
                       B10100,
                       B10101,
                       B01101,
                       B00110,
                       B00100,
                       B00100 };   

void setup() {
 pinMode (10, OUTPUT); // подключаем пьезодинамик
 pinMode (A1, INPUT);     // подключаем кнопку
 analogWrite(A1, LOW);
 LCD.init();                        // инициализация LCD дисплея
 LCD.backlight();              // включение подсветки дисплея
Serial.begin(9600);
 // создаем символы дракончика, дерева, камня и птицы
 LCD.createChar(0, dracon);
 LCD.createChar(1, derevo);
 LCD.createChar(2, kamen);
 LCD.createChar(3, ptica);
 LCD.createChar(4, derevo228);
 LCD.createChar(5, kamen228);
 
 // начинаем игру: выводим надпись GO!
 LCD.setCursor(7, 0);
 LCD.print("GO!");
 delay(400);
 tone(10, 600);
 delay(100);
 noTone(10);
 LCD.clear();
}

void loop() {
  Serial.println(digitalRead(2));
  // первоначальное положение дракончика и препятствия
  byte d = 1;
  byte x = 15;
  byte y = 1;
  // выбираем препятствие, которое появится, рандомно
  byte i = random (1, 6);
  if (i == 3) y = 0;
  else y = 1;

  while (x > 0) {
    // очищаем экран и выводим номер уровня
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print(level);

    // считываем данные с кнопки и учитываем количество циклов в прыжке
    // если дакончик находится в прыжке долго - возвращаем его вниз
    if (digitalRead(2) == 1) d = 0;
    if (digitalRead(2) == 0) d = 1;
    if (p > 3) d = 1;

    // выводим дракончика в нужной строке
    LCD.setCursor(4, d);
    LCD.print(char(0));
    // выводим препятствие
    LCD.setCursor(x, y);
    tone(10, 50);
    LCD.print(char(i));
    noTone(10);

    // если дракончик наткнулся на препятствие выводим надпись GAME OVER!
    if (x == 4 && y == d) {
      delay(400);
      tone(10, 50);
      delay(100);
      noTone(10);
      delay(100);
      tone(10, 20);
      delay(300);
      noTone(10);
      LCD.clear();
      delay(200);
      LCD.setCursor(3, 0);
      LCD.print("GAME OVER!");
      delay(600);
      LCD.clear();
      delay(400);
      LCD.setCursor(3, 0);
      LCD.print("GAME OVER!");
      delay(600);
      LCD.clear();
      LCD.setCursor(3, 1);
      LCD.print("LEVEL: ");
      LCD.print(level);
      delay(400);
      LCD.setCursor(3, 0);
      LCD.print("GAME OVER!");
      delay(3000);
      LCD.clear();

      // начинаем игру заново, обнулив уровень игры
      LCD.setCursor(7, 0);
      LCD.print("GO!");
      delay(400);
      tone(10, 600);
      delay(100);
      noTone(10);
      LCD.clear();

      level = 0;
      pause = 400;
      p = 0;
      y = 1;
      x = 0;
      break;
    }

    // если дракончик прыгнул, издаем звук
    if (d == 0) { tone(10, 200); delay(100); noTone(10); }
    else { delay(100); }

    // если дракончик не столкнулся, то меняем положение препятствия
    // начинаем считать сколько циклов дракончик находится в прыжке
    delay(pause);
    x = x - 1;
    p = p + 1;
    if (p > 4) p = 0; 
 }

  // переходим на следующий уровень и сокращаем время задержки
  tone(10, 800);
  delay(20);
  level = level + 1;
  pause = pause - 20;
  if (pause < 0) pause = 0;
}

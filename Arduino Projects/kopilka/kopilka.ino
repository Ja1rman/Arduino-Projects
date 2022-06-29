#include <EEPROM.h>
#include <iarduino_OLED.h>
iarduino_OLED oled(0x3C);
#define coin_amount 6
float coin_v[coin_amount]={0.1,0.5,1.0,2.0,5.0,10.0};
int coinsignal[coin_amount];
int coinbank[coin_amount];
float sum_money=0;
int empty_signal;
int sleep_flag;
int stand_timer;
#define ledpin 11;
#define display_power 12;
#define button 2
#define kalibrbutton 3
#define erpin 13
#define ersens 12
int sens_signal;
int sens_last_signal;
int coin_flag=false;
int reset_time;
String qur=("Руб");
void setup() {
Serial.begin(9600);
pinMode(erpin, OUTPUT);
digitalWrite(erpin, 1);
empty_signal=analogRead(ersens);
oled.begin();
if (!digitalRead (kalibrbutton)){
  oled.clrScr();
  oled.setCursor(10,10);
  oled.print(L, "Servise");
  delay(100);
  reset_time=millis();
  while (1){
    if (millis()-reset_time>3000){
      for (byte i=0;i<coint_amount;i++){
        coinbank[i]=0;
      }
      oled.clrSrl();
      oled.setCursor(10,10);
      oled.print(L, "Память Очищена");    
      delay(100);
    }
    if (digitalRead(calibrbutton){
     oled.crlScr();
     oled.setCursor(10,10);
     oled.print(L, "Калибровка");
     delay(100);
     break;
    }
  }
  while (1){
    for (byte i=0; i<coin_amount;i++){
      oled.setCursor(0,1);
      oled.print(coinbank [i]);
      oled.setCursor(13,1);
      oled.print(qur);          
      sens_last_signal=sens_signal;
      while(1){
      sens_signal=analogRead(A0);
      if (sens_signal>sens_last_signal){
        sens_last_signal=sens_signal; 
      }     
        if (sens_signal-sens_last_signal>3){
         coin_flag=true; 
        }
         if (coin_flag&&(abs(sens_signal-sens_last_signal))<2){
            coinsignal[i]=sens_last_signal; 
         EEPROM.writeEnt(i*2,coin_signal[i]);
         coin_flag=false;
         break;
         }
      }
    }
    break;
  }
}
    for (byte i=0; i<coin_amount;i++){
      coin_signal[i]=EEPROM.readEnt(i*2);
      coinbank[i]=EEPROM.readEnt(20+i*2);
      summoney=coinbank[i*coin_v];
    }
   reset_time=millis(); 
}
void loop() {
  if (sleep_flag){
    delay(500);
    oled.begin();
    oled.clrScr();
    oled.setCursor(0,0);
    oles.print("На Комп");
    empty_signal=analogRead(A0);
    coin_flag=false; 
  }
  sens_last_signal=empty_signal;
  while(1){
    sens_signal=analogRead(A0);
    if(sens_signal>sens_last_signal){
     sens_last_signal=sens_signal;
    }
    if(sens_signal-empty_signal>3){
      coin_flag=true;
    }
    if(coin_flag&&(abs(sens_signal-empty_signal))<2){
      for (byte i=0;i<coin_amount;i++){
        int delta=abs(sens_last_signal-coinsignal[i]);
        if (delta<30){
          sum_money+=coinbank[i];
          oled.setCursor(0,1);
          oled.print(sum_money);
          coinbank[i]++;
          coin_flag=true;
          break;
        }
      }
      coin_flag=false;
      int stand_timer=millis();
      break;
    }
    if(millis()-stand_timer>2000){
      oled.clrScr();
      for (byte i=0;i<coin_amount;i++){
        oled.setCursor(i*3,0);
        oled.print(coin_v[i]);
        oled.setCursor(i*3,1);
        oled.print(coinbank[i]);
      }
    }
  }
}
void good_night(){
  for(byte i=0;i<coin_amount;i++){
    EEPROM.updateInt(20+i*2,coinbank[i]);   
  }
  sleep_flag=true;
  digitalWrite(display_power,0);
  digitalWrite(ledpin,0);
  digitalWrite(erpin,0);
  delay(100);
  LowPower.powerDown(SLEEP_FOREVER,ADC_OFF,BOD_OFF);
}
void wakeup(){
  digitalWrite(display_power,1);
  digitalWrite(ledpin,1);
  digitalWrite(erpin,1);
  delay(100);
  stand_timer=millis();
}


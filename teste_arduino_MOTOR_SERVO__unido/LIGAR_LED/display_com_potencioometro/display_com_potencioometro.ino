/* potenciometro e tela display*/
#include<LiquidCrystal.h>

LiquidCrystal lcd (12,11,5,4,3,2);

void setup(){
  lcd.begin (16,2);// quantas colunas e linhas tem o display
  lcd.setCursor(0,0); // aonde ele comeca escrever
  lcd.print("HolaMyGenteSomos:;)");
  lcd.setCursor(0,1);
  lcd.print("AnaCamilaKelita");
  }

void loop (){}

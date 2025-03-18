#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

/*exercicios 
Autor:Gabriel Peres
Data:18/03/2025
*/

#define Botao1 0
#define Botao2 145
#define Botao3 329
#define Botao4 505
#define Botao5 741



void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print(">");
  
  
}

void loop()    
{
  int Botao = analogRead(A0);
  
  if(Botao == 0){
  lcd.setCursor(0, 0);
  lcd.print(">   ");
  lcd.setCursor(0, 1);
  lcd.print(" ");
  }
  if(Botao == Botao2){ 
  lcd.setCursor(0, 1);
  lcd.print(">      ");
  lcd.setCursor(0, 0);
  lcd.print("  ");
    
  }
    
    
  
}
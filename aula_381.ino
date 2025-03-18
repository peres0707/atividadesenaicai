#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

/*exercicios 
Autor:Gabriel Peres
Data:17/03/2025
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
  
  
}

void loop()    
{
  int Botao = analogRead(A0);
  
  if(Botao == 0){
  lcd.setCursor(0, 0);
  lcd.print("Botao 1 Ligado       ");
  }
  if(Botao >= Botao2 * 0.9 && Botao <= Botao2 * 1.1){
  lcd.setCursor(0, 0);
  lcd.print("Botao 2 Ligado       ");
    
  }if(Botao >= Botao3 * 0.9 && Botao <= Botao3 * 1.1){
  lcd.setCursor(0, 0);
  lcd.print("Botao 3 Ligado       ");
    
  }if(Botao >= Botao4 * 0.9 && Botao <= Botao4 * 1.1){
  lcd.setCursor(0, 0);
  lcd.print("Botao 4 Ligado       ");
    
  }if(Botao >= Botao5 * 0.9 && Botao <= Botao5 * 1.1){
  lcd.setCursor(0, 0);
  lcd.print("Botao 5 Ligado       ");
    
  }if(Botao == 1023){
  lcd.setCursor(0, 0);
  lcd.print("Botao Desligado");
  }
    
 
    
    
  
}

/*exercicios 
Autor:Gabriel Peres
Data:11/03/2025
*/
#define pinLedVermelho 12
#define Botao 13
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int estadoAnterior = 0;
int estadoLed = 0;
int estadoBotao = 0;

void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(Botao, INPUT);
  pinMode(pinLedVermelho, OUTPUT); 
  
}

void loop()
{
  

 int estadoAtual = digitalRead(Botao);
  
  if (estadoAtual == 1 && estadoAnterior == 0){
    estadoLed = !estadoLed;
    digitalWrite(pinLedVermelho, estadoLed);
    if(estadoLed == 1){
    lcd.setCursor(0,0);
    lcd.print("LIGAR LED        ");
    
  }else{
    lcd.setCursor(0,0);  
    lcd.print("LED DESLIGADO"); 
      
  }
  }
  
  estadoAnterior  = estadoBotao;

}

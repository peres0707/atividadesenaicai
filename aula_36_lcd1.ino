
/*exercicios 
Autor:Gabriel Peres
Data:11/03/2025
*/

#define Botao 13
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int estadoAnterior = 0;
int estadoAtual = 1;

void setup() 
{
  lcd.init();
  lcd.backlight();
 pinMode(Botao, INPUT);
   
  
}

void loop()
{
  int estadoBotao = digitalRead(Botao);
  if (estadoBotao == 1 && estadoAnterior == 0){
     lcd.print(estadoAtual);
  estadoAtual++;
  if (estadoAtual == 10)
    estadoAtual = 0;
  
 }
  estadoAnterior = estadoBotao;
}

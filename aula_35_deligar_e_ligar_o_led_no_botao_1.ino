/*exercicios ligar e desligar quando aperta o botao
Autor:Gabriel Peres
Data:11/03/2025
*/

#define LedVermelho 8
#define pinBotao 12

int estadoAnterior = 0;
int estadoAtual = 0;
int estadoLed = 0;



void setup()
{

  pinMode(pinBotao, INPUT);
  pinMode(LedVermelho, OUTPUT);
  
}

void loop()
{
  int estadoBotao = digitalRead(pinBotao);
  
  
  if(estadoBotao == 1 && estadoAnterior){
    estadoAtual++;
    estadoLed = !estadoLed;
    digitalWrite(LedVermelho, estadoLed);
  }
  estadoAnterior = estadoBotao;  
}
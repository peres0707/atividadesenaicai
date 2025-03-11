/*exercicios do botao
Autor:Gabriel Peres
Data:7/03/2025
*/

#define LedVermelho 8
#define Botao 12

bool estadoLed = 0;
unsigned long tempoInicial = 0;

void setup()
{
  pinMode(Botao, INPUT);
  pinMode(LedVermelho, OUTPUT);
  
}

void loop()
{
 bool estadoBotao = digitalRead(Botao);
  
  unsigned long tempoAtual = millis();
  
  if(estadoBotao){
    
    if(tempoAtual - tempoInicial >= 300) {
      estadoLed = !estadoLed;
      digitalWrite(LedVermelho, estadoLed);
      tempoInicial = tempoAtual;
    }
  }else{
    digitalWrite(LedVermelho, LOW);
  }
  
}
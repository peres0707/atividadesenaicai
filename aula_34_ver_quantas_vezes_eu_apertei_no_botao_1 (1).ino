/*exercicios quantas vezes eu apertei no botao
Autor:Gabriel Peres
Data:11/03/2025
*/

#define pinBotao 13

int estadoAnterior = 1;
int estadoBotao = 0;


void setup ()
{
  Serial.begin(9600);
  
  pinMode(pinBotao, INPUT);
  
  
}
void loop()
{
  int estadoAtual = digitalRead(pinBotao);
  if (estadoAtual == 1 && estadoAnterior == 0){
   estadoBotao ++;
    Serial.print("cliq botao: ");
    Serial.println(estadoBotao);
    
  }
  estadoAnterior = estadoAtual;
  
}
  
 
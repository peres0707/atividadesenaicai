/*exercicios analongRead temperatura
Autor:Gabriel Peres
Data:14/03/2025
*/
void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  int valor = analogRead(A0);
   if (valor <= 200){
    Serial.println("Friozinho");
   
  }else if(valor >= 200 && valor <= 500){
    Serial.println("Frio");
   
  }else if (valor >= 500 && valor <= 800){
    Serial.println("Clima Agradavel");
     
   }else if (valor >= 800 && valor <= 900){
    Serial.println("Calor");
     
  }else{
    Serial.println("Calor");
  }
 
}
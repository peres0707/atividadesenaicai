
void setup()
{
  Serial.begin (9600);
}

void loop()
{
  int valor = analogRead(A0);
  int resultado = map(valor, 0, 1023, 0, 100);
  Serial.println(resultado);
  
}
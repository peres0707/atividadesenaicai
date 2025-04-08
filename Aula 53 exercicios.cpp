#include <Arduino.h>
#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pinBotaoA 19
#define pinBotaoB 18
#define pinBotaoC 5
#define pinLed1 15
#define pinLed2 2
#define pinLed3 4
#define pinLed4 23

Bounce botaoA = Bounce();
Bounce botaoB = Bounce();
Bounce botaoC = Bounce();

void setup()
{
    Serial.begin(9600);
    
    pinMode(5, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(23, OUTPUT);

    botaoA.attach(pinBotaoA, INPUT_PULLUP);
    botaoB.attach(pinBotaoB, INPUT_PULLUP);
    botaoC.attach(pinBotaoC, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();
    lcd.setCursor(1, 0);
    lcd.print(">ligar LED 1   0%");
    lcd.setCursor(1, 1);
    lcd.print(" ligar LED 2   0%");
    lcd.setCursor(1, 2);
    lcd.print(" ligar LED 3   0%");
    lcd.setCursor(1, 3);
    lcd.print(" ligar LED 4   0%");
}

void loop()
{

    botaoA.update();
    botaoB.update();
    botaoC.update();


    static int posicao = 0;
    static int intensidadeLed1 = 0;
    static int intensidadeLed2 = 0;
    static int intensidadeLed3 = 0;
    static int intensidadeLed4 = 0;
    static bool modoSelecao = 0;
   
    if (botaoA.fell())
    {
        posicao++;

        if (posicao > 3)
        {
            posicao = 0;
        }
    }

    if (botaoB.fell())
    {
        posicao--;

        if (posicao < 0)
        {
            posicao = 3;
        }
    }
    
    if (botaoC.fell())
    {
        modoSelecao = !modoSelecao;
    }

    if (botaoA.fell() && modoSelecao == 0)
    {
        if (posicao == 0 && intensidadeLed1 < 100)
        {
            intensidadeLed1 += 10;
        }

        if (posicao == 1 && intensidadeLed2 < 100)
        {
            intensidadeLed2 += 10;
        }

        if (posicao == 0 && intensidadeLed3 < 100)
        {
            intensidadeLed3 += 10;
        }

        if (posicao == 0 && intensidadeLed4 < 100)
        {
            intensidadeLed4 += 10;
        }
    }

    if (botaoB.fell() && modoSelecao == 0)
    {
        if (posicao == 0 && intensidadeLed4 < 0)
        {
            intensidadeLed1 -= 10;
        }

        if (posicao == 0 && intensidadeLed4 < 0)
        {
            intensidadeLed2 -= 10;
        }

        if (posicao == 0 && intensidadeLed4 < 0)
        {
            intensidadeLed3 -= 10;
        }

        if (posicao == 0 && intensidadeLed4 < 0)
        {
            intensidadeLed4 -= 10;
        }
    }

    if (posicao == 0)
    {
        lcd.setCursor(1, 0);
        lcd.print(">");
        lcd.setCursor(1, 1);
        lcd.print(" ");
        lcd.setCursor(1, 3);
        lcd.print(" ");
    }
    if (posicao == 1)
    {
        lcd.setCursor(1, 1);
        lcd.print(">");
        lcd.setCursor(1, 0);
        lcd.print(" ");
        lcd.setCursor(1, 2);
        lcd.print(" ");
    }
    if (posicao == 2)
    {
        lcd.setCursor(1, 2);
        lcd.print(">");
        lcd.setCursor(1, 3);
        lcd.print(" ");
        lcd.setCursor(1, 1);
        lcd.print(" ");
    }
    if (posicao == 3)
    {
        lcd.setCursor(1, 3);
        lcd.print(">");
        lcd.setCursor(1, 2);
        lcd.print(" ");
        lcd.setCursor(1, 0);
        lcd.print(" ");     
    }
} 
// FIZ ATE A AULA 8
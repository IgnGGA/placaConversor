//________________LIBRERIAS___________________________________________________________________________________________
#include <LiquidCrystal.h>
//________________COMUNICACIÓN_PC_____________________________________________________________________________________
String informacionEntrada;                                                                    // Informacion que viene desde el programa Detector.py
String informacionSalida;                                                                     // Informacion que sale hacia el programa Detector.py
String sincronizadorUno = "$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr"; // Palabra que es enviada al programa Detector.py para comparar
String BancoDePruebasOK = "Banco De Pruebas Activado";                                        // Palabra enviada para confirmar condición de palra recivida
char sincronizadorDos = '2';
int testLed = 13; // pin13 del arduino
int lecturaSenal = A0;
//_________________SEÑAL_HACIA_TARJETA_SMA____________________________________________________________________________
int PWM1P = 10;
int PWM1M = 11; // PWM 1 corresponde a los IGBT v3/v4
int PWM3P = 3;
int PWM3M = 9; // PWM 3 corresponde a los IGBT v4/v6
int PWM5P = 6;
int PWM5M = 5; // PWM 5 corresponde a los IGBT v1 y v2 activandose uno a uno en cada semiciclo
int tiempo = 800;
//__________________PANTALLA_LCD_______________________________________________________________________________________
LiquidCrystal lcd(12, 13, A0, A1, A2, A3);

void setup()
{
  //__________________COMUNICACIÓN_PC____________________________________________________________________________________
  Serial.begin(9600);
  Serial.setTimeout(50);
  informacionSalida.reserve(50);
  informacionEntrada.reserve(50);
  pinMode(testLed, OUTPUT);
  //_________________SEÑAL_SMA___________________________________________________________________________________________
  pinMode(PWM1P, OUTPUT); //|
  pinMode(PWM1M, OUTPUT); //|
  pinMode(PWM3P, OUTPUT); //>>Generacion de pulsos para banco de pruebas, NO MANIPULAR
  pinMode(PWM3M, OUTPUT); //|
  pinMode(PWM5P, OUTPUT); //|
  pinMode(PWM5M, OUTPUT); //|
                          //_________________LCD_________________________________________________________________________________________________
  lcd.begin(16, 2);
  lcd.print("BCO PRUEBAS SMA");
}

void loop()
{
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Espere");
  enviandoInformacion();
  delay(1000);
  char informacionEntrada = Serial.read();
  while (informacionEntrada == sincronizadorDos)
  { // comparacion de palabra recivida
    // int i;
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("PC OK");
    delay(2000);
    Serial.println(BancoDePruebasOK);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Enviando Señal");
    // for(i=0;i<10;i++){
    //   testing();
    // }
    // informacionSalida="";
    ciclon();
    break;
  }
}

void enviandoInformacion()
{
  informacionSalida = Serial.println(sincronizadorUno);
}

void testing()
{ // codigo de prueba funcionamiento
  digitalWrite(testLed, 1);
  delay(500);
  digitalWrite(testLed, 0);
  delay(500);
}

void ciclon()
{ // NO MANIPULAR, SEÑAL CONSTRUCTORA DE SEÑAL TOTAL
  lcd.setCursor(0, 0);
  lcd.print("Prueba iniciada");
  for (;;)
  {
    TodosUno();
    SCUPU();
    SCUPD();
    TodosUno();
    SCDPU();
    SCDPD();
  }
}

void TodosUno()
{                         // NO MANIPULAR, FUNCION CONSTRUCTORA DE SEÑALES PARTE 1
  digitalWrite(PWM1P, 1); // 1
  digitalWrite(PWM3P, 1); // 1
  digitalWrite(PWM5P, 1); // 1
  digitalWrite(PWM1M, 0);
  digitalWrite(PWM3M, 0);
  digitalWrite(PWM5M, 0);
  delayMicroseconds(tiempo / 18);
}
// funciones primer semiciclo
void SCUPU()
{                         // SemiCiclo Uno Parte Dos; NO MANIPULAR, FUNCION CONSTRUCTORA PARTE 2
  digitalWrite(PWM1P, 1); // 1
  digitalWrite(PWM3M, 1); // 0
  digitalWrite(PWM5P, 1); // 1
  digitalWrite(PWM1M, 0);
  digitalWrite(PWM3P, 0);
  digitalWrite(PWM5M, 0);
  delayMicroseconds(5 * tiempo / 18);
}
void SCUPD()
{                         // NO MANIPULAR, SEÑAL CONSTRUCTORA PARTE 3
  digitalWrite(PWM1P, 1); // 1
  digitalWrite(PWM3M, 1); // 0
  digitalWrite(PWM5M, 1); // 0
  digitalWrite(PWM1M, 0);
  digitalWrite(PWM3P, 0);
  digitalWrite(PWM5P, 0);
  delayMicroseconds(tiempo / 6);
}
void SCDPU()
{                         // SemiCiclo Uno Parte Uno, NO MANIPULAR, SEÑAL CONSTRUCTORA PARTE 4
  digitalWrite(PWM1M, 1); // 0
  digitalWrite(PWM3P, 1); // 1
  digitalWrite(PWM5P, 1); // 1
  digitalWrite(PWM1P, 0);
  digitalWrite(PWM3M, 0);
  digitalWrite(PWM5M, 0);
  delayMicroseconds(5 * tiempo / 18);
}
void SCDPD()
{                         // NO MANIPULAR, SEÑAL CONSTRUCTORA PARTE 5
  digitalWrite(PWM1M, 1); // 0
  digitalWrite(PWM3P, 1); // 1
  digitalWrite(PWM5M, 1); // 0
  digitalWrite(PWM1P, 0);
  digitalWrite(PWM3M, 0);
  digitalWrite(PWM5P, 0);
  delayMicroseconds(tiempo / 6);
}
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// int testLed = 13; //pin13 del arduino
// participacion generacion PWM
int PWM1P = 10;
int PWM1M = 11; // PWM 1 corresponde a los IGBT v3/v4
int PWM3P = 3;
int PWM3M = 9; // PWM 3 corresponde a los IGBT v4/v6
int PWM5P = 6;
int PWM5M = 5; // PWM 5 corresponde a los IGBT v1 y v2 activandose uno a uno en cada semiciclo
int tiempo = 800;
// INTERRUPCION IGBT
int HSS1 = 13;
int HSS2 = 12;
int WR1 = 8;
int WR2 = 7;
int WR3 = 4;
int WR4 = 2;
LiquidCrystal_I2C lcd(0x27, 20, 4);
int opA = A0;
int opB = A1;

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.println("BANCO DE PRUEBAS SMA");
  pinMode(PWM1P, OUTPUT);
  pinMode(PWM1M, OUTPUT);
  pinMode(PWM3P, OUTPUT);
  pinMode(PWM3M, OUTPUT);
  pinMode(PWM5P, OUTPUT);
  pinMode(PWM5M, OUTPUT);
  pinMode(HSS1, OUTPUT);
  pinMode(HSS2, OUTPUT);
  pinMode(WR1, OUTPUT);
  pinMode(WR2, OUTPUT);
  pinMode(WR3, OUTPUT);
  pinMode(WR4, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Banco De Pruebas SMA");
  pinMode(opA, INPUT);
  pinMode(opB, INPUT);
}

void loop()
{
  mensajeSerial("Iniciando programa");
  mInicio(25, 25, 25);
  seleccion();
}

void seleccion()
{
  do
  {
    bool lecA = digitalRead(opA);
    bool lecB = digitalRead(opB);
    if (lecA == 1 and lecA != lecB)
    {
      mensajeSerial("Prueba Automatica.\n\tFrecuencia: 1KHz");
      Serial.println(lecA, lecB);
      bool lecA = digitalRead(opA);
      bool lecB = digitalRead(opB);
      imprimirMensajes(0, 1, 2, 3, "Prueba automatica."; "Confirmar: A)", "Regresar: B)", "");
      if (lecA == 1 and lecA != lecB !)
      {
        imprimirMensajes(0, 1, 2, 3, "Prueba Modo:", "Oscilacion Constante", "Frecuencia:", "  1KHz");
        ciclon();
        finPrueba();
        break;
      }
      else if (lecB == 1 and lecA != lecB)
      {
        seleccion();
        break;
      }
    }
    else if (lecB == 1 and lecA != lecB)
    {
      Serial.println(lecA, lecB);
      bool lecA = digitalRead(opA);
      bool lecB = digitalRead(opB);
      imprimirMensajes(0, 1, 2, 3, "Prueba Interrupcion."; "Confirmar: A)", "Regresar: B)", "");
      if (lecA == 1 and lecA != lecB !)
      {
        mensajeSerial("Prueba Modo:\n\tInterrupcion de IGBT\nFrecuencia 1KHz");
        interrupcionIGBT();
        finPrueba();
        break;
      }
      else if (lecB==1 and lecA!=lecB)
      {
        seleccion();
        break;
      }
      
    }
    else if (lecA == lecB)
    {
      mensajeSerial("Esperando...");
      Serial.println(lecA, lecB);
      imprimirMensajes(0, 1, 2, 3, "Banco de", "Pruebas SMA", "A)OSC. CTE. 1KHz", "B)Interrupcion IGBT");
      delay(1000);
    }
  } while (true);
}

void ciclon()
{ // NO MANIPULAR, SEÑAL CONSTRUCTORA DE SEÑAL TOTAL
  for (;;)
  {
    ciclo();
  }
}
void ciclo()
{
  TodosUno();
  SCUPU();
  SCUPD();
  TodosUno();
  SCDPU();
  SCDPD();
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
{                         // NO PAMIPULAR, SEÑAL CONSTRUCTORA PARTE 5
  digitalWrite(PWM1M, 1); // 0
  digitalWrite(PWM3P, 1); // 1
  digitalWrite(PWM5M, 1); // 0
  digitalWrite(PWM1P, 0);
  digitalWrite(PWM3M, 0);
  digitalWrite(PWM5P, 0);
  delayMicroseconds(tiempo / 6);
}
void mInicio(int a, int b, int c)
{
  delay(a * 100);
  mensajeSerial("Iniciando, favor esperar");
  imprimirMensajes(0, 1, , 2, 3 "Iniciando.", "Espere...", "", "");
  delay(b * 100);
  mensajeSerial("Esperando Seleccion:\n\tA)Auto\n\tB)Manual");
  imprimirMensajes(0, 1, 2, 3, "Seleecione Prueba:", "", "A) Auto", "B) Manual");
  delay(c * 100);
}
void imprimirMensajes(int a, int b, int c, int d, String e, String f, String g, String h)
{
  lcd.clear();
  lcd.setCursor(0, a);
  lcd.print(e);
  lcd.setCursor(0, b);
  lcd.print(f);
  lcd.setCursor(0, c);
  lcd.print(g);
  lcd.setCursor(0, d);
  lcd.print(h);
}

void mensajeSerial(String a)
{
  Serial.println(a);
}

void pruebaErrores(char a)
{
  imprimirMensajes(0, 1, 2, 3, "Prueba Modo:", "Interrupcion IGBT", "Probando:", (String)a);
  Serial.println("Interrumpiendo señal IGBT: " + a);
  digitalWrite(a, 1);
  int i = 0;
  for (i = 0; i < tiempo * 10; i++)
  {
    ciclo();
  }
  digitalWrite(a, 0);
}
void interrupcionIGBT()
{
  pruebaErrores(HSS1);
  delay(1000);
  pruebaErrores(HSS2);
  delay(1000);
  pruebaErrores(WR1);
  delay(1000);
  pruebaErrores(WR2);
  delay(1000);
  pruebaErrores(WR3);
  delay(1000);
  pruebaErrores(WR4);
  delay(1000);
}

void finPrueba(){
  imprimirMensajes(0,1,2,3,"Prueba finalizada.","","Volviendo a ","Selector");
  seleccion();
  break;
}
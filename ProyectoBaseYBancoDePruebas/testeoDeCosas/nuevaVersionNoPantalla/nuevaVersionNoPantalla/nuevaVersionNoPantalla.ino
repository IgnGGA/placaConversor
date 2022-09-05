#include <LiquidCrystal.h>
//int testLed = 13; //pin13 del arduino
//participacion generacion PWM
int PWM1P = 10;
int PWM1M = 11; //PWM 1 corresponde a los IGBT v3/v4
int PWM3P = 3;
int PWM3M = 9; //PWM 3 corresponde a los IGBT v4/v6
int PWM5P = 6;
int PWM5M = 5; //PWM 5 corresponde a los IGBT v1 y v2 activandose uno a uno en cada semiciclo
int tiempo = 800;
//INTERRUPCION IGBT
int cutHSS1 = 13;
int cutHSS2 = 12;
int cutWR1 = 8;
int cutWR2 = 7;
int cutWR3 = 4;
int cutWR4 = 2;
//LiquidCrystal lcd(12, 13, A1, A2, A3, A4);
int opA = A0;
int opB = A1;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.println("BANCO DE PRUEBAS SMA");
  //  pinMode(testLed, OUTPUT);
  pinMode(PWM1P, OUTPUT); //|
  pinMode(PWM1M, OUTPUT); //|
  pinMode(PWM3P, OUTPUT); //>>Generacion de pulsos para banco de pruebas, NO MANIPULAR
  pinMode(PWM3M, OUTPUT); //|
  pinMode(PWM5P, OUTPUT); //|
  pinMode(PWM5M, OUTPUT); //|
  pinMode(cutHSS1, OUTPUT);
  pinMode(cutHSS2, OUTPUT);
  pinMode(cutWR1, OUTPUT);
  pinMode(cutWR2, OUTPUT);
  pinMode(cutWR3, OUTPUT);
  pinMode(cutWR4, OUTPUT);
  //lcd.begin(16, 2);
  //lcd.print("\n\n\n\t\t\t\tBCO PRUEBAS SMA");
  pinMode(opA, INPUT);
  pinMode(opB, INPUT);
}

void loop() {
  //mensajeSerial("Iniciando programa");
  //mInicio(25,25,25);
  do {
    bool lecA = digitalRead(opA);
    bool lecB = digitalRead(opB);
    if (lecA == 1 and lecA != lecB) {
      mensajeSerial("Prueba Automatica.\n\tFrecuencia: 1KHz");
      Serial.println(lecA, lecB);
      //imprimirMensajes(0, 1, "Modo Auto", "Frecuencia: 1KHz");
      ciclon();
      break;
    }
    else if (lecB == 1 and lecA != lecB) {
      mensajeSerial("Prueba Manual.\nEstamso en eso...");
      Serial.println(lecA, lecB);
      pruebaErrores(cutHSS1);
      delay(1000);
      pruebaErrores(cutHSS2);
      delay(1000);
      pruebaErrores(cutWR1);
      delay(1000);
      pruebaErrores(cutWR2);
      delay(1000);
      pruebaErrores(cutWR3);
      delay(1000);
      pruebaErrores(cutWR4);
      delay(1000);
      break;
    }
    else if (lecA == lecB) {
      mensajeSerial("Esperando...");
      Serial.println(lecA, lecB);
      //imprimirMensajes(0, 1, "Esperando", "........");
      delay(1000);
    }
  }
  while (true);
}

//void testing() { //codigo de prueba funcionamiento
//  digitalWrite(testLed, 1);
//  delay(500);
//  digitalWrite(testLed, 0);
//  delay(500);
//}

void ciclon() { //NO MANIPULAR, SEÑAL CONSTRUCTORA DE SEÑAL TOTAL
  for (;;) {
    TodosUno();
    SCUPU();
    SCUPD();
    TodosUno();
    SCDPU();
    SCDPD();
  }
}
void ciclo() {
  TodosUno();
  SCUPU();
  SCUPD();
  TodosUno();
  SCDPU();
  SCDPD();
}

void TodosUno() { //NO MANIPULAR, FUNCION CONSTRUCTORA DE SEÑALES PARTE 1
  digitalWrite(PWM1P, 1); //1
  digitalWrite(PWM3P, 1); //1
  digitalWrite(PWM5P, 1); //1
  digitalWrite(PWM1M, 0);
  digitalWrite(PWM3M, 0);
  digitalWrite(PWM5M, 0);
  delayMicroseconds(tiempo / 18);
}
//funciones primer semiciclo
void SCUPU() { //SemiCiclo Uno Parte Dos; NO MANIPULAR, FUNCION CONSTRUCTORA PARTE 2
  digitalWrite(PWM1P, 1); //1
  digitalWrite(PWM3M, 1); //0
  digitalWrite(PWM5P, 1); //1
  digitalWrite(PWM1M, 0);
  digitalWrite(PWM3P, 0);
  digitalWrite(PWM5M, 0);
  delayMicroseconds(5 * tiempo / 18);
}
void SCUPD() { //NO MANIPULAR, SEÑAL CONSTRUCTORA PARTE 3
  digitalWrite(PWM1P, 1); //1
  digitalWrite(PWM3M, 1); //0
  digitalWrite(PWM5M, 1); //0
  digitalWrite(PWM1M, 0);
  digitalWrite(PWM3P, 0);
  digitalWrite(PWM5P, 0);
  delayMicroseconds(tiempo / 6);
}
void SCDPU() { //SemiCiclo Uno Parte Uno, NO MANIPULAR, SEÑAL CONSTRUCTORA PARTE 4
  digitalWrite(PWM1M, 1); //0
  digitalWrite(PWM3P, 1); //1
  digitalWrite(PWM5P, 1); //1
  digitalWrite(PWM1P, 0);
  digitalWrite(PWM3M, 0);
  digitalWrite(PWM5M, 0);
  delayMicroseconds(5 * tiempo / 18);
}
void SCDPD() { //NO PAMIPULAR, SEÑAL CONSTRUCTORA PARTE 5
  digitalWrite(PWM1M, 1); //0
  digitalWrite(PWM3P, 1); //1
  digitalWrite(PWM5M, 1); //0
  digitalWrite(PWM1P, 0);
  digitalWrite(PWM3M, 0);
  digitalWrite(PWM5P, 0);
  delayMicroseconds(tiempo / 6);
}
void mInicio(int a, int b, int c) {
  delay(a * 100);
  mensajeSerial("Iniciando, favor esperar");
  //imprimirMensajes(0, 1, "Iniciando.", "Espere...");
  delay(b * 100);
  mensajeSerial("Esperando Seleccion:\n\tA)Auto\n\tB)Manual");
  //imprimirMensajes(0, 1, "Seleecione Prueba", "A)Auto - B)Manual");
  delay(c * 100);
}
//void imprimirMensajes(int a, int b, String c, String d) {
//  lcd.clear();
//  lcd.setCursor(0, a);
//  lcd.print (c);
//  lcd.setCursor(0, b);
//  lcd.print (d);
//}

void mensajeSerial(String a) {
  Serial.println(a);
}

void pruebaErrores(char a) {
  digitalWrite(a, HIGH);
  int i = 0;
  for (i = 0; i < 100; i++) {
    ciclo();
  }
  digitalWrite(a, LOW);
}

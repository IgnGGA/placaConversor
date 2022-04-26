int PWM1P = 11; //Esta ligado al PIN 1 del conector de la placa.
int PWM1M = 10; //Esta ligado al PIN 9 del conector de la placa.
int PWM5P = 9;  //Esta ligado al PIN 4 del conector de la placa.
int PWM5M = 3;  //Esta ligado al PIN 12 del conector de la placa.
int PWM3P = 6;  //Esta ligado al PIN 6 del conector de la placa.
int PWM3M = 5;  //Esta ligado al PIN 13 del conector de la placa.
int pot1  = A0; //potencionemtro de 100K regula procentaje activo de PWM1
int pot2  = A1; //potencionemtro de 100K regula procentaje activo de PWM3
int pot3  = A2; //potencionemtro de 100K regula procentaje activo de PWM5
int valorPot1;
int valorPot2;
int valorPot3;
int transPot1;
int transPot2;
int transPot3;

void setup() {
  pinMode (PWM1P,  OUTPUT);
  pinMode (PWM3P,  OUTPUT);
  pinMode (PWM5P,  OUTPUT);
  pinMode (PWM1M,  OUTPUT);
  pinMode (PWM3M,  OUTPUT);
  pinMode (PWM5M,  OUTPUT);
}

void loop() {
  lecturas();
  senalesParte1();
}

void lecturas(){
  valorPot1 = analogRead  (pot1);
  valorPot2 = analogRead  (pot2);
  valorPot3 = analogRead  (pot3);
  transPot1 = map(valorPot1, 0, 1023, 0, 255);
  transPot2 = map(valorPot2, 0, 1023, 0, 255);
  transPot3 = map(valorPot3, 0, 1023, 0, 255);
}

void senalesParte1(){
  analogWrite (PWM1P, transPot1);
  analogWrite (PWM3P, transPot2);
  analogWrite (PWM5P, transPot3);
  analogWrite (PWM1M, transPot1);
  analogWrite (PWM3M, transPot2);
  analogWrite (PWM5M, transPot3);
}

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
int tiempo=100;
int calculoPot1A;
int calculoPot1B;

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
  transPot1 = map(valorPot1, 0, 1023, 1, 90);
  transPot2 = map(valorPot2, 0, 1023, 1, 90);
  transPot3 = map(valorPot3, 0, 1023, 1, 90);
  calculoPot1A  = (tiempo*(transPot1/100));
  calculoPot1B  = (tiempo-calculoPot1A);
}

void senalesParte1(){
  for(;;){
    PWM1On();
    delay(calculoPot1A);
    PWM1Off();
    delay(calculoPot1B);
  }
}

void  PWM1Off(){
  digitalWrite  (PWM1P, 0);
  digitalWrite  (PWM1M, 1);
}
void PWM1On(){
  digitalWrite  (PWM1P, 1);
  digitalWrite  (PWM1M, 0);
}
void  PWM3Off(){
  digitalWrite  (PWM3P, 0);
  digitalWrite  (PWM3M, 1);
}
void PWM3On(){
  digitalWrite  (PWM3P, 1);
  digitalWrite  (PWM3M, 0);
}
void  PWM5Off(){
  digitalWrite  (PWM5P, 0);
  digitalWrite  (PWM5M, 1);
}
void PWM5On(){
  digitalWrite  (PWM5P, 1);
  digitalWrite  (PWM5M, 0);
}
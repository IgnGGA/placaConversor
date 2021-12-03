int P_pwm1 = 3;
int P_pwm3 = 5;
int P_pwm5 = 6;
int M_pwm1 = 2;
int M_pwm3 = 4;
int M_pwm5 = 7;
int const frecuencia = 1;
const float periodo = (1 / frecuencia);
const float timer = (periodo * 1000) / 2;

void setup()
{
  Serial.begin(9600);
  pinMode(P_pwm1, OUTPUT);
  pinMode(P_pwm3, OUTPUT);
  pinMode(P_pwm5, OUTPUT);
  pinMode(M_pwm1, OUTPUT);
  pinMode(M_pwm3, OUTPUT);
  pinMode(M_pwm5, OUTPUT);
}

void pwm1On() {
  digitalWrite(P_pwm1, 1);
  digitalWrite(M_pwm1, 0);
}
void pwm1Off() {
  digitalWrite(P_pwm1, 0);
  digitalWrite(M_pwm1, 1);
}
void pwm3On() {
  digitalWrite(P_pwm3, 1);
  digitalWrite(M_pwm3, 0);
}
void pwm3Off() {
  digitalWrite(P_pwm3, 0);
  digitalWrite(M_pwm3, 1);
}
void pwm5On() {
  digitalWrite(P_pwm5, 1);
  digitalWrite(M_pwm5, 0);
}
void pwm5Off() {
  digitalWrite(P_pwm5, 0);
  digitalWrite(M_pwm5, 1);
}
//=======================================
//PWM1 y PWM5 siempre han de ser OPUESTOS
//O complementarios entre si
//-------------------
void signalMed1() { //|
  pwm1On();       //|
  pwm5Off();      //|
}                 //|
void signalMed2() { //|
  pwm1Off();    //|
  pwm5On();     //|
}                 //|
//-------------------
//=======================================
//señal 3 igual a señal 1, 1 y 5 opuestas
void signalForward() {
  for (;;) {
    signalMed1();
    pwm3On();
    delay(timer);
    signalMed2();
    pwm3Off();
    delay(timer);
  }
}
//========================================
//señal 3 igual a señal 5, 1 y 5 opuestas
void signalReverse() {
  for (;;) {
    signalMed1();
    pwm3Off();
    delay(timer);
    signalMed2();
    pwm3On();
    delay(timer);
  }
}
//========================================
//señal 3 siempre en alto, 1 y 5 opuestas
void signalOut() {
  pwm3On();
  for (;;) {
    signalMed1();
    delay(timer);
    signalMed2();
    delay(timer);
  }
}
void signalsAllEqual() {
  for (;;) {
    pwm1On();
    pwm3On();
    pwm5On();
    delay(timer);
    pwm1Off();
    pwm3Off();
    pwm5Off();
    delay(timer);
  }
}
void signals15Equal3cte(){
  pwm3On();
  for(;;){
    pwm1On();
    pwm5On();
    delay(timer);
    pwm1Off();
    pwm5Off();
    delay(timer);
  }
}
//========================================
//PWM1==>Controla OPTO 2
//PWM3==>Controla OPTO 1
//PWM5==>Controla OPTO 3
void loop() {
  pwm1Off();
  pwm3Off();
  pwm5Off();
  do {
    if (Serial.available() > 0) {
      int comando = Serial.read();
      switch (comando) {
        case '1':
          do {
            Serial.println("Señal 1:\tOK");
            signalForward();
          }
          while (true);
          break;
        case '2':
          do {
            Serial.println("Señal 2:\tOK");
            signalReverse();
          }
          while (true);
          break;
        case '3':
          do {
            Serial.println("Señal 3:\tOK");
            signalOut();
          }
          while (true);
          break;
        case '4':
          do {
            Serial.println("Señal 4:\tOK");
            signalsAllEqual();
          }
          while (true);
          break;
        case '5':
          do {
            Serial.println("Señal 5:\tOK");
            signals15Equal3cte();
          }
          while (true);
          break;
        case '0':
          do {
            Serial.println("Señal 0:\tOK");
            exit(0);
          }
          while (true);
          break;
      }
    }
  }
  while (true);
}

int PWM1P=10;
int PWM1M=11;//PWM 1 corresponde a los IGBT v3/v4
int PWM3P=3;
int PWM3M=9;//PWM 3 corresponde a los IGBT v4/v6
int PWM5P=6;
int PWM5M=5;//PWM 5 corresponde a los IGBT v1 y v2 activandose uno a uno en cada semiciclo


void setup() {
  pinMode(PWM1P,OUTPUT);
  pinMode(PWM1M,OUTPUT);
  pinMode(PWM3P,OUTPUT);
  pinMode(PWM3M,OUTPUT);
  pinMode(PWM5P,OUTPUT);
  pinMode(PWM5M,OUTPUT);
}

void loop() {
  for(;;)
  {
    digitalWrite(PWM1P,HIGH);
    digitalWrite(PWM1M,!PWM1P);
    digitalWrite(PWM3P,HIGH);
    digitalWrite(PWM3M,!PWM3P);
    digitalWrite(PWM5P,HIGH);
    digitalWrite(PWM5M,!PWM5P);
    delayMicroseconds(139);
    digitalWrite(PWM1P,HIGH);
    digitalWrite(PWM1M,!PWM1P);
    digitalWrite(PWM3P,LOW);
    digitalWrite(PWM3M,!PWM3P);
    digitalWrite(PWM5P,HIGH);
    digitalWrite(PWM5M,!PWM5P);
    delayMicroseconds(324);
    digitalWrite(PWM1P,HIGH);
    digitalWrite(PWM1M,!PWM1P);
    digitalWrite(PWM3P,LOW);
    digitalWrite(PWM3M,!PWM3P);
    digitalWrite(PWM5P,LOW);
    digitalWrite(PWM5M,!PWM5P);
    delayMicroseconds(231);
    //______________________CAMBIO_DE_SEMICICLO_________________________________
    digitalWrite(PWM1P,HIGH);
    digitalWrite(PWM1M,!PWM1P);
    digitalWrite(PWM3P,HIGH);
    digitalWrite(PWM3M,!PWM3P);
    digitalWrite(PWM5P,HIGH);
    digitalWrite(PWM5M,!PWM5P);
    delayMicroseconds(139);
    digitalWrite(PWM1P,LOW);
    digitalWrite(PWM1M,!PWM1P);
    digitalWrite(PWM3P,HIGH);
    digitalWrite(PWM3M,!PWM3P);
    digitalWrite(PWM5P,HIGH);
    digitalWrite(PWM5M,!PWM5P);
    delayMicroseconds(324);
    digitalWrite(PWM1P,LOW);
    digitalWrite(PWM1M,!PWM1P);
    digitalWrite(PWM3P,HIGH);
    digitalWrite(PWM3M,!PWM3P);
    digitalWrite(PWM5P,LOW);
    digitalWrite(PWM5M,!PWM5P);
    delayMicroseconds(231);
  }
}

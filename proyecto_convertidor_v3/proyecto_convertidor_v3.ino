int P_pwm1 = 3;
int P_pwm3 = 5;
int P_pwm5 = 6;
int M_pwm1 = 2;
int M_pwm3 = 4;
int M_pwm5 = 7;
int const frecuencia = 1;
const float periodo = (1/frecuencia);
const float timer = periodo*1000;

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

void loop()
{ 
  for (;;){
    s1On();
    s3On();
    s5On();
    delay(timer);
    s1Off();
    s3Off();
    s5Off();
    delay(timer);
    //signal001();
    //signal002();
    //signal003();
    //signal004();
  }
}
void s1On(){
  digitalWrite(P_pwm3, 1);
  digitalWrite(M_pwm3, 0);
}
void s1Off(){
  digitalWrite(P_pwm3, 0);
  digitalWrite(M_pwm3, 1);
}
void s3On(){
  digitalWrite(P_pwm1, 1);
  digitalWrite(M_pwm1, 0);
}
void s3Off(){
  digitalWrite(P_pwm1, 0);
  digitalWrite(M_pwm1, 1);
}
void s5On(){
  digitalWrite(P_pwm5, 1);
  digitalWrite(M_pwm5, 0);
}
void s5Off(){
  digitalWrite(P_pwm5, 0);
  digitalWrite(M_pwm5, 1);
}
void signal001(){//señal s3=(s5^-1) && s1=cte
  s3On();
  s5Off();
  s1On();
  delay (timer);
  s3Off();
  s5On();
  s1On();
  delay (timer);
}
void signal002(){//señal s3=(s5^-1) && s1=s3
  s3On();
  s5Off();
  s1On();
  delay (timer);
  s3Off();
  s5On();
  s1Off();
  delay (timer);
}
void signal003(){//señal s3=(s5^-1) && s1=s5
  s3On();
  s5Off();
  s1Off();
  delay (timer);
  s3Off();
  s5On();
  s1On();
  delay (timer);
}
void signal004(){//generar 10 veces cada pulso de manera aislada
  int a=0;
  int b=0;
  int c=0;
  digitalWrite(P_pwm1, 0);
  digitalWrite(P_pwm5, 0);
  digitalWrite(P_pwm3, 0);
  digitalWrite(M_pwm1, 0);
  digitalWrite(M_pwm5, 0);
  digitalWrite(M_pwm3, 0);
  for(a=0;a<10;a++){
    pulseOnlyS1();
  }
  for(b=0;b<10;b++){
    pulseOnlyS3();
  }
    for(c=0;c<10;c++){
    pulseOnlyS5();
  }

}
void pulseOnlyS1(){
    s1On();
    delay(timer);
    s1Off();
    delay(timer);
}
void pulseOnlyS3(){
    s3On();
    delay(timer);
    s3Off();
    delay(timer);
}
void pulseOnlyS5(){
    s5On();
    delay(timer);
    s5Off();
    delay(timer);
}

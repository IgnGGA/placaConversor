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
    s3On();
    s5Off();
    s1On();
    delay (timer);
    s3Off();
    s5On();
    s1On();
    delay (timer);

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

int PWM1P=10;
int PWM1M=11;//PWM 1 corresponde a los IGBT v3/v4
int PWM3P=3;
int PWM3M=9;//PWM 3 corresponde a los IGBT v4/v6
int PWM5P=6;
int PWM5M=5;//PWM 5 corresponde a los IGBT v1 y v2 activandose uno a uno en cada semiciclo
int tiempo=800;

void setup() {
  pinMode(PWM1P,OUTPUT);
  pinMode(PWM1M,OUTPUT);
  pinMode(PWM3P,OUTPUT);
  pinMode(PWM3M,OUTPUT);
  pinMode(PWM5P,OUTPUT);
  pinMode(PWM5M,OUTPUT);
}


void loop(){
  ciclon();
}

void ciclon(){
  for(;;){
    TodosUno();
    SCUPU();
    SCUPD();
    TodosUno();
    SCDPU();
    SCDPD();
  }
}

void TodosUno(){
  digitalWrite(PWM1P,1);//1
  digitalWrite(PWM3P,1);//1
  digitalWrite(PWM5P,1);//1
  digitalWrite(PWM1M,0);
  digitalWrite(PWM3M,0);
  digitalWrite(PWM5M,0);
  delayMicroseconds(tiempo/18);
}
//funciones primer semiciclo
void SCUPU(){//SemiCiclo Uno Parte Dos
  digitalWrite(PWM1P,1);//1
  digitalWrite(PWM3M,1);//0
  digitalWrite(PWM5P,1);//1
  digitalWrite(PWM1M,0);
  digitalWrite(PWM3P,0);
  digitalWrite(PWM5M,0);
  delayMicroseconds(5*tiempo/18);
}
void SCUPD(){
  digitalWrite(PWM1P,1);//1
  digitalWrite(PWM3M,1);//0
  digitalWrite(PWM5M,1);//0
  digitalWrite(PWM1M,0);
  digitalWrite(PWM3P,0);
  digitalWrite(PWM5P,0);
  delayMicroseconds(tiempo/6);
}
void SCDPU(){//SemiCiclo Uno Parte Uno
  digitalWrite(PWM1M,1);//0
  digitalWrite(PWM3P,1);//1
  digitalWrite(PWM5P,1);//1
  digitalWrite(PWM1P,0);
  digitalWrite(PWM3M,0);
  digitalWrite(PWM5M,0);
  delayMicroseconds(5*tiempo/18);
}
void SCDPD(){
  digitalWrite(PWM1M,1);//0
  digitalWrite(PWM3P,1);//1
  digitalWrite(PWM5M,1);//0
  digitalWrite(PWM1P,0);
  digitalWrite(PWM3M,0);
  digitalWrite(PWM5P,0);
  delayMicroseconds(tiempo/6);
}
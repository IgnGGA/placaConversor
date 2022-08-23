int s1M=10; //señal 1 pwmM en pin 1 conector placa
int s1P=11; //señal 1 pwmP en pin 9 conector placa
int s3P=6;  //señal 3 pwmM en pin 6 conector placa
int s3M=5;  //señal 3 pwmP en pin 13 conector placa 
int s5M=9;  //señal 5 pwmP en pin 4 conector placa
int s5P=3;  //señal 5 pwmM en pin 12 conector placa
int fault0=A0; // señal de error 0
int fault1=A1; // señal de error 1
int errorFault0=0;
int errorFault1=0;

void setup() {
  Serial.begin(9600);
  pinMode(s1P, OUTPUT);
  pinMode(s1M, OUTPUT);
  pinMode(s3P, OUTPUT);
  pinMode(s3M, OUTPUT);
  pinMode(s5P, OUTPUT);
  pinMode(s5M, OUTPUT);
}

void loop() {
  readerSignals();
  //for(;;){
    //signalPWM();}  
}

void signalPWM(){
  for(;;){
    startFun();
    funMed();
    s1On();//1
    s3Off();//0
    s5On();//1
    funMed();
  }
}
void startFun(){
  s1Off();//0
  s3Off();//0
  s5Off();//0
}
void funMed(){
  delayMicroseconds(4629);
  s1On();//1
  s3Off();//0
  s5Off();//0
  delayMicroseconds(1736);
  s1On();//1
  s3On();//1
  s5Off();//0
  delayMicroseconds(578);
}

//_||ENCENDIDOS_Y_APAGADOS_FUNCIONES||
void s1Off(){
  digitalWrite(s1P,0);
  digitalWrite(s1M,1);
}
void s1On(){
  digitalWrite(s1P,1);
  digitalWrite(s1M,0);
}
void s3Off(){
  digitalWrite(s3P,0);
  digitalWrite(s3M,1);
}
void s3On(){
  digitalWrite(s3P,1);
  digitalWrite(s3M,0);
}
void s5Off(){
  digitalWrite(s5P,0);
  digitalWrite(s5M,1);
}
void s5On(){
  digitalWrite(s5P,1);
  digitalWrite(s5M,0);
}
void readerSignals(){
  do{
    errorFault0=analogRead(fault0);
    errorFault1=analogRead(fault1);
    Serial.println(errorFault0);
    Serial.println(errorFault1);
  }
   while (true);
}

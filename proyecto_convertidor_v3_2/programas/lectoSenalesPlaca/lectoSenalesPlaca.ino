int fault0=A0; // señal de error 0
int fault1=A1; // señal de error 1
int verificacion01=A4;
int verificacion02=A5;
int errorFault0=0;
int errorFault1=0;

void setup() {
  Serial.begin(9600);
  pinMode(verificacion01,OUTPUT);
  pinMode(verificacion02,OUTPUT);
}

void loop() {
  readerSignals();  
}
void readerSignals(){
  do{
    errorFault0=analogRead(fault0);
    errorFault1=analogRead(fault1);
    analogWrite(verificacion01,errorFault0);
    analogWrite(verificacion02,errorFault1);
    Serial.print(";error Fault0 :");
    Serial.print(";");
    Serial.print(errorFault0);
    Serial.print(";error Fault1: ");
    Serial.print(";");
    Serial.print(errorFault1);
  }
   while (true);
}

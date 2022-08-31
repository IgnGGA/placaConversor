String informacionSalida;
String informacionEntrada;
String sincronizadorUno="$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr";
String sincronizadorDos="666";
String BancoDePruebasOK="Banco De Pruebas Activado";
int testLed=13;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  informacionSalida.reserve(50);
  informacionEntrada.reserve(50);
  informacionEntrada=(char)Serial.read();
  pinMode(testLed,OUTPUT);
}

void loop() {
  enviandoInformacion();
  delay(2000);
  while(informacionEntrada==sincronizadorDos){
    int i;
    informacionSalida=(char)Serial.println(BancoDePruebasOK);
    for(i=0;i<10;i++){
      testing();
    }
  }
}

void enviandoInformacion(){
  informacionSalida=Serial.println(sincronizadorUno);
}
void testing(){
  digitalWrite(testLed,1);
  delay(500);
  digitalWrite(testLed,0);
  delay(500); 
}

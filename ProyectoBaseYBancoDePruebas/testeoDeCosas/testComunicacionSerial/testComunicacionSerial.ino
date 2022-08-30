String informacionSalida;
String informacionEntrada;
String sincronizadorUno="$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr";
String sincronizadorDos="p!!-lf5yotizOQaGODekistIdeg0c6lWRuCEB&4HEYuZujoGewop!V=t-3Ib6thl";
String BancoDePruebasOK="Banco De Pruebas Activado";
int testLed=13;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  informacionSalida.reserve(50);
  informacionEntrada.reserve(50);
  pinMode(testLed,OUTPUT);
}

void loop() {
  enviandoInformacion();
  informacionEntrada=(char)Serial.println(sincronizadorDos);
  while(informacionEntrada==sincronizadorDos){
    int i;
    informacionSalida=(char)Serial.println(BancoDePruebasOK);
    for(i=0;i<10;i++){
      testing();
    }
  }
}

void enviandoInformacion(){
  informacionSalida=(char)Serial.println(sincronizadorUno);
}
void testing(){
  digitalWrite(testLed,1);
  delay(500);
  digitalWrite(testLed,0);
  delay(500); 
}

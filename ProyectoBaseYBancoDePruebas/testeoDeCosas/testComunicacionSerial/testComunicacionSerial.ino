String informacionEntrada;
String informacionSalida;
String sincronizadorUno="$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr";
String sincronizadorDos="p!!-lf5yotizOQaGODekistIdeg0c6lWRuCEB&4HEYuZujoGewop!V=t-3Ib6thl";
String BancoDePruebasOK="Banco De Pruebas Activado";

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  informacionEntrada.reserve(50);
  informacionSalida.reserve(50);
}

void loop() {
  enviandoInformacion();
  delay(1000);
  reciviendoInformacion();
}

void enviandoInformacion(){
  informacionSalida=(char)Serial.println(sincronizadorUno);
}

void reciviendoInformacion(){
  char informacion=(char)Serial.read();
  informacionEntrada+=informacion;
  delay(1000);
  if (informacionEntrada==sincronizadorDos){
    informacionSalida="";
    informacionSalida=(char)Serial.println(BancoDePruebasOK);
    delay(1000);
  }
}

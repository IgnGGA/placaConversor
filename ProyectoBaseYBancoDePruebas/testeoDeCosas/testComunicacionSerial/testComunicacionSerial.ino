String informacionEntrada;//Informacion que viene desde el programa Detector.py
String informacionSalida;//Informacion que sale hacia el programa Detector.py
String sincronizadorUno="$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr";//Palabra que es enviada al programa Detector.py para comparar
String BancoDePruebasOK="Banco De Pruebas Activado";//Palabra enviada para confirmar condición de palra recivida
int testLed=13;//pin13 del arduino

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  informacionSalida.reserve(50);
  informacionEntrada.reserve(50);
  pinMode(testLed,OUTPUT);
}

void loop() {
  delay(1000);
  enviandoInformacion();
  delay(1000);
  char informacionEntrada=Serial.read();
  while(informacionEntrada=='2'){
    int i;
    delay(2000);
    Serial.println(BancoDePruebasOK);
    for(i=0;i<10;i++){
      testing();
    }
    informacionSalida="";
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

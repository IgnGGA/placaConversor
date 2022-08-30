String respuesta;
String sincronizador="01000010 01100001 01101110 01100011 01101111 01000100 01100101 01010000 01110010 01110101 01100101 01100010 01100001 01110011 01010011 01001101 01000001 ";

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  Serial.println("$ag#3l!h@spuprajek@&uWu5ls_ab_woHeyi4&asutro?=3cr9&a?_7c9e6@1afr");
  delay(1000);
  respuesta=(String)Serial.read();
  if (respuesta==sincronizador){
    Serial.println("Banco De Pruebas SMA: INICIADO");
    delay(1000);
  }
  respuesta="";
}

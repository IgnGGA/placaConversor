int PWM1P = 11; //Esta ligado al PIN 1 del conector de la placa.
int PWM1M = 10; //Esta ligado al PIN 9 del conector de la placa.
int PWM5P = 9;  //Esta ligado al PIN 4 del conector de la placa.
int PWM5M = 3;  //Esta ligado al PIN 12 del conector de la placa.
int PWM3P = 6;  //Esta ligado al PIN 6 del conector de la placa.
int PWM3M = 5;  //Esta ligado al PIN 13 del conector de la placa.

void setup() {
  Serial.begin(9600);
  pinMode (PWM1P,  OUTPUT);
  pinMode (PWM1M,  OUTPUT);
  pinMode (PWM3P,  OUTPUT);
  pinMode (PWM3M,  OUTPUT);
  pinMode (PWM5P,  OUTPUT);
  pinMode (PWM5M,  OUTPUT);
}

void loop() {
  juegoDeSenales();
}
void juegoDeSenales(){
  analogWrite (PWM1P, 170); //oscilacion al (2/3)% de la señal. Con 490Hz.
  analogWrite (PWM5P, 85);  //oscilacion al (1/3)% de la señal. Con 490Hz.
  analogWrite (PWM3P, 13);  //oscilacion al 5% de la señal. Con 980Hz.
  analogWrite (PWM1M, 170); //oscilacion al (2/3)% de la señal. Con 490Hz.
  analogWrite (PWM5M, 85);  //oscilacion al (1/3)% de la señal. Con 490Hz.
  analogWrite (PWM3M, 13);  //oscilacion al 5% de la señal. Con 980Hz.
}

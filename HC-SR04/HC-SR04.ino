#include <LiquidCrystal.h>

#define PIN_RS 2 
#define PIN_EN 3 
#define PIN_D4 4 
#define PIN_D5 5 
#define PIN_D6 6 
#define PIN_D7 7

const int pinEcho = 8;
const int pinTrig = 9;
int tiempo;
int distancia;

LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7); 

void setup() {
  //Inicio del Serial Port para imprimir los datos del sensor
  Serial.begin(9600);
  
  //Configuración LCD
  lcd.begin(16,2);
  lcd.clear();
  
  lcd.print("Programa medidas");
  lcd.setCursor(1,1);
  lcd.print("sensor HC-SR04");
  
  //Configuración Sensor HC-SR04
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}

void loop() {
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(1);
  digitalWrite(pinTrig,LOW);
  tiempo = pulseIn(pinEcho,HIGH);
  distancia = tiempo/58.2;
  Serial.println(distancia);
  delay(200);
}

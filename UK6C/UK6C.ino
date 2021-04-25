#include <LiquidCrystal.h>

#define PIN_RS 12 
#define PIN_EN 13 
#define PIN_D4 4 
#define PIN_D5 5 
#define PIN_D6 6 
#define PIN_D7 7

const int pinSen = A0;
const float resist = 250.0; //resistencia que se coloca para medir el voltaje de entrada analógico 

const int pinButt = 2;

volatile bool buttonPressed = false;

const int _DRef[] = {5,10,20,30,40,50,60,70,80}; 

int tiempo;     // Guarda el tiempo de vuelo
int distancia;  // Guarda la distancia al objeto
int _m = 0;     // Contabiliza numero de muestras 
float corriente;  // Corriente de la señal analógica que envía el sensor
float  vin;      // Tensión de la señal analógica filtrada que envía el sensor

LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7); 

void setup() {
  //Inicio del Serial Port para imprimir los datos del sensor
  Serial.begin(9600);
  Serial.println("Num,DReferencia,Pulso,DMedida");

  //Configuración Boton
  pinMode(pinButt, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinButt), funcion_ISR, RISING);
    
  //Configuración Sensor HC-SR04
  pinMode(pinSen, INPUT);
  
  
  //Configuración LCD
  lcd.begin(16,2);
  lcd.clear();  
  lcd.print("Programa medidas");
  lcd.setCursor(1,1);
  lcd.print("sensor UK6C/H2‐0EUL");
}

void loop() {
  if(buttonPressed){        //Entra cuando se pulse el botón
    buttonPressed = false;  //Se reestablece el estado del boton, para 
                            //cuando se vuelva a pulsar
        
    for(int i=0;i<2;i++){   //Se hace 2 series (2 objetos)
      for(int j=0;j<9;j++){ //9 medidas, 9 distancias por serie
        while(!buttonPressed){ /*Espera mientras la distancia varia*/}
        for(int n=0;n<5;n++){  //Cada medida se va a tomar 5 veces
          _m++; //Numero de la muestra que se esta tomando
          
          vin = (analogRead(pinSen)*5000)/1023; //Medimos la entrada analógica en mv 
          corriente = vin/resist*1000;        //La pasamos a corriente en mA
          
          
          if(corriente>20 or corriente<4{  //Filtramos la corriente. Si no
            corriente = 0;                            //cumple un rango, se descarta
            distancia = 0;                            //distancia a cero por estar fuera de rango
          }                          
          else{  
            distancia = (corriente-(5/2))*4;//Se calcula la distancia en cm
                                             //mediante la ecuación de la recta que pasa por 2 puntos
                                             //ya que conocemos el rango de medidas y su distribución lineal
                                             
            //distancia = -1*(corriente - (788/37))*(37/8)  // Por si acaso la pendiente de calibracion 
                                                            //Es negativa                                   
                                                            
          }
          //Los siguientes comandos imprimen los datos en un formato .csv
          Serial.print(_m);         Serial.print(",");
          Serial.print(_DRef[j]);   Serial.print(",");
          Serial.print(corriente);     Serial.print(",");
          Serial.println(distancia);

          //Se imprime en la LCD
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("ID:" + String(i));
          lcd.setCursor(5,0);
          lcd.print("Med:" + String(_m));
          lcd.setCursor(0,1);
          lcd.print("Distancia:" + String(distancia) + " cm");

          delay(500);
        }
        buttonPressed = false;
      }
    }
  }
}

//Función para la interrupción
void funcion_ISR(){
  buttonPressed = true;
}

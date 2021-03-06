//***********************Inicio codigo************************//

#include <Arduino.h>
#include <Servo.h>
#include <Autuino.h>
#include <UltraSonido.h>

using namespace std;

//*******************Inicio declaraciones*********************//

// Pines de los motores
const int Pin_Motor_A1 = 6;
const int Pin_Motor_A2 = 5;
const int Pin_Motor_B1 = A0;
const int Pin_Motor_B2 = A1;


// Pines del sensor ultrasonido
int trigPin = A4;
int echoPin = A5;

//Pines del Servo
int Pin_Servo = 3;

// Variables del ultrasonido
unsigned int duracion, distancia_frontal, distancia_izq, distancia_der, distancia;

// Movimientos
const int Tiempo_de_giro = 600; //ms
const int Angulo_izq = 180; //grados
const int Angulo_der = 70;  //grados
const int Angulo_cen = 125;  //grados
const int distancia_para_giro = 15; //cm

//*********************Fin declaraciones**********************//


//*******************************Setup********************************//


// Iniciando la librería Autuino
Autuino motor(Pin_Motor_A1, Pin_Motor_A2, Pin_Motor_B1, Pin_Motor_B2);

// Iniciando la librería Servo
Servo servo;

// Iniciando la librería UltraSonido
UltraSonido ultrasonido(echoPin, trigPin);

void setup(){

        //Se agrega el Servo
        servo.attach(Pin_Servo);

        // Iniciando serial
        Serial.begin(9600);

        motor.writeMotor('B', 225);
        motor.writeMotor('A', 225);

        // Declaración sobre E/S de los pines
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);

        //Moviendo el Servo a la posición inicial
        servo.write(Angulo_cen);

        //Mensaje de bienvenida
        Serial.println("AOK");

}



void loop(){

        //Iniciamos por defecto los motores en la velocidad maxima y dirección frontal
        motor.writeMotor('B', 225);
        motor.writeMotor('A', 225);

        // Medimos que tan lejos esta el auto de llegar a un objeto
        distancia_frontal = ultrasonido.Mirar();


        // Cuando el auto se acerque a un objeto:
        if (distancia_frontal < distancia_para_giro) {

                // Anunciamos por serial la proximidad
                Serial.println ();
                Serial.println ( "-----------------------------------------------------");
                Serial.print ("Obstaculo detectedo a " );
                Serial.print (distancia_frontal);
                Serial.println ( " centimetros.");
                Serial.println ( "Deteniendo motores");

                motor.Freno();

                Serial.println ( "Revisando a que lado voy:");


                // Giramos el servo del ultrasonido hacia la derecha para medir la distancia
                servo.write(Angulo_der);
                delay(500);
                distancia_der = ultrasonido.Mirar();


                // Giramos el servo del ultrasonido hacia la izquierda para medir la distancia
                servo.write(Angulo_izq);
                delay(500);
                distancia_izq = ultrasonido.Mirar();


                // Devolvemos el servo al centro
                delay(500);
                servo.write(Angulo_cen);

                if(distancia_der>distancia_izq) {

                        Serial.print ( "El lado derecho esta mas despejado, girando. (");
                        Serial.print (distancia_der);
                        Serial.println ( " centimetros).");

                        // Hacemos funcionar solo uno de los motores para girar
                        motor.writeMotor('B',0);
                        motor.writeMotor('A',255);

                        // Le damos tiempo para que gire
                        delay(Tiempo_de_giro);

                        // Reiniciamos los valores
                        distancia_der = 0;
                        distancia_izq = 0;
                }

                if(distancia_der<distancia_izq) {

                        Serial.print ( "El lado izquierdo esta mas despejado, girando. (");
                        Serial.print (distancia_izq);
                        Serial.println ( " centimetros).");

                        // Hacemos funcionar solo uno de los motores para girar
                        motor.writeMotor('A',0);
                        motor.writeMotor('B',255);

                        // Le damos tiempo para que gire
                        delay(Tiempo_de_giro);

                        // Reiniciamos los valores
                        distancia_der = 0;
                        distancia_izq = 0;
                }

                Serial.println ( "-----------------------------------------------------");

        }

}


//************************Fin codigo**************************//

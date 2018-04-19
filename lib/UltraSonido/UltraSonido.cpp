//***********************Inicio codigo************************//

#include <Arduino.h>
#include <UltraSonido.h>

//Iniciamos la clase principal de la libreria
UltraSonido::UltraSonido(int echoPin, int trigPin):

//Remplazamos los valores globales por los privados (Inicialización de lista)
_echoPin(echoPin),
_trigPin(trigPin)
{
  //Iniciamos los pines por si todavía no se hace en main
  pinMode(_echoPin, INPUT);
  pinMode(_trigPin, INPUT);

int UltraSonido::UltraSonido(){

  digitalWrite(trigPin, LOW);

  // Se detiene el sensor por 0.002 segundos
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  // Se detiene el sensor por 0.01 segundos
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);

  //Ecuación para calcular la distancia en centimetros
  distancia = (duracion/2) / 29.1;

  return distancia;
}

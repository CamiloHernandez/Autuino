#ifndef UltraSonido_h
#define UltraSonido_h

#include "Arduino.h"

class UltraSonido
{
  public:
    UltraSonido(int echoPin, int trigPin);
    int Mirar();

  private:
     int _echoPin;
     int _trigPin;
     float duracion;
     float distancia;
};


#endif

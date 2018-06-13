#ifndef Autuino_h
#define Autuino_h

#include "Arduino.h"

class Autuino
{
public:
Autuino(int Pin_Motor_A1, int Pin_Motor_A2,  int Pin_Motor_B1, int Pin_Motor_B2);
void writeMotor(char Motor, int Velocidad);
void Freno();
private:
int _Pin_Motor_A1;
int _Pin_Motor_A2;
int _Pin_Motor_B1;
int _Pin_Motor_B2;
char _Motor;
int _Velocidad;
bool Sentido;
int _PinSalida;
int _PinApagado;

};


#endif

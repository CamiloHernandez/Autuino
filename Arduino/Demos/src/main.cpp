#include <Arduino.h>

unsigned int foto1;
unsigned int foto2;
unsigned int foto3;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A10, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  foto1 = analogRead(A0);
  foto2 = analogRead(A1);
  foto3 = analogRead(A2);

  Serial.print("Foto 1: ");
  Serial.print(foto1);
  Serial.print("\t Foto 2: ");
  Serial.print(foto2);
  Serial.print("\t Foto 3: ");
  Serial.print(foto3);
  Serial.println();

  analogWrite(A8, foto1);
  analogWrite(A9, foto2);
  analogWrite(A10, foto3);

  delay(500);
}

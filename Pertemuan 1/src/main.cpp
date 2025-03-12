#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
int LED1 = D0;
int LED2 = D3;
int LED3 = D7;


void setup() {
  pinMode(LED1, OUTPUT); // Set pin sebagai output dimana Output berarti pin tersebut dapat mengeluarkan tegangan
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH); // Higj adalah kondisi dimana pin dinyalakan, dengan menyalakan pin maka akan mengeluarkan tegangan dengan sebesar 5V
  delay(800); // Delay adalah jeda waktu dalam milisecond
  digitalWrite(LED1, LOW); // Low adalah kondisi dimana pin dimatikan
  digitalWrite(LED2, HIGH);
  delay(500);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  delay(500);
  digitalWrite(LED3, LOW);
}
 

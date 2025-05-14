#include <Arduino.h>
#include <Servo.h>

// Nama : Muhamad Galih
// NIM : H1D022052
// Mata Kuliah : Pemrograman Sistem Tertanam
// Shift : h

// Pin LED

int LEDred = D7;
int LEDgreen = D8;

// Pin Sensor Ultrasonic

int trigPin = D2;
int echoPin = D1;

// Pin Servo Motor
Servo MyServo;
int pinServo = D3;

// Variabel Sensor Ultrasonic
long durasi;
int jarak;

void setup() {

  // Setup Serial Monitor
  Serial.begin(9600);

  // Setup LED
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgreen, OUTPUT);

  // Serial Monitor Led
  Serial.println("LED Siap digunakan");

  // Setup Sensor Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Serial Monitor Ultrasonic
  Serial.println("Ultrasonic Siap digunakan");
  
  // Setup Servo Motor
  MyServo.attach(pinServo);

  // Serial Monitor Servo
  Serial.println("Servo Motor Siap digunakan");
}

void loop() {
  // Mengirim sinyal trigger ke sensor ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Membaca durasi pantulan sinyal dari echo
  durasi = pulseIn(echoPin, HIGH);

  // Menghitung jarak (dalam cm)
  jarak = durasi * 0.034 / 2;

  // Menampilkan hasil jarak di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  if (jarak>0 && jarak<=150) {
    digitalWrite(LEDred, LOW);
    digitalWrite(LEDgreen, HIGH);
    MyServo.write(180);
    delay(500);
  } else {
    digitalWrite(LEDred, HIGH);
    digitalWrite(LEDgreen, LOW);
    MyServo.write(0);
    delay(500);
  }
  delay(100);
}

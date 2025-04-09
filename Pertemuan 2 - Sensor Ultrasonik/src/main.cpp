#include <Arduino.h>

// Pin yang digunakan untuk sensor dan LED
const int trigPin = D1; // Trigger pin HC-SR04
const int echoPin = D0; // Echo pin HC-SR04

const int ledMerah = D2;  // LED Merah (jarak dekat)
const int ledKuning = D3; // LED Kuning (jarak sedang)
const int ledHijau = D4;  // LED Hijau (jarak jauh)

// Variabel untuk menyimpan waktu dan jarak
long durasi;
int jarak;

void setup() {
  // Setup pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledMerah, OUTPUT);
  pinMode(ledKuning, OUTPUT);
  pinMode(ledHijau, OUTPUT);

  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Informasi awal
  Serial.println("Sensor Ultrasonik HC-SR04 Siap!");
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

  // Logika nyala lampu indikator
  if (jarak > 0 && jarak <= 10) {
    // Sangat dekat, nyalakan LED merah dengan efek fading
    for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(ledMerah, brightness);
      delay(10);
    }
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  } else if (jarak > 10 && jarak <= 20) {
    // Jarak sedang, nyalakan LED kuning dengan efek fading
    for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(ledKuning, brightness);
      delay(10);
    }
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledHijau, LOW);
  } else if (jarak > 20 && jarak <= 30) {
    // Jarak aman, nyalakan LED hijau dengan efek fading
    for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(ledHijau, brightness);
      delay(10);
    }
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
  } else {
    // Di luar jangkauan, semua LED mati
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledHijau, LOW);
  }

  // Delay sebelum pembacaan berikutnya
  delay(500); // Lebih responsif dari 1000 ms
}

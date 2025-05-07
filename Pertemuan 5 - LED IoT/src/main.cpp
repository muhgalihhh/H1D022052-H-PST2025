#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "galih"; // Nama SSID WiFi atau nama wi-fi
const char* password = "galih123"; // Password WiFi atau password wi-fi 

ESP8266WebServer server(80); // Membuat objek server pada port 80
String webpage;

void setup(){
  Serial.begin(9600);
  delay(10);

  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);

  // Connect to Wifi
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid, password);

  // Cek koneksi
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("Connected to WiFi");

  // Membuat halaman web
  webpage += "<html><body>";
  webpage += "<h1>ESP8266 Web Control</h1>";
  webpage += "<h2>Muhamad Galih (H1D022052)</h2>";
  webpage += "<p>LED 1</p>";
  webpage += "<p><a href= \"LED1ON\"\"><button>LED ON</button></a><a href= \"LED1OFF\"\"><button>LED OFF</button></a></p><br>";
  webpage += "<p>LED 2</p>";
  webpage += "<p><a href= \"LED2ON\"\"><button>LED ON</button></a><a href= \"LED2OFF\"\"><button>LED OFF</button></a></p><br>";
  webpage += "<p>LED 3</p>";
  webpage += "<p><a href= \"LED3ON\"\"><button>LED ON</button></a><a href= \"LED3OFF\"\"><button>LED OFF</button></a></p><br>";

  // Membuat tampilan halaman web d

  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  // Menangani permintaan untuk LED 1
  server.on("/LED1ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, HIGH);
    Serial.println("LED 1 ON");
    delay(1000);
  });

  server.on("/LED1OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, LOW);
    Serial.println("LED 1 OFF");
    delay(1000);
  });

  // Menangani permintaan untuk LED 2

  server.on("/LED2ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, HIGH);
    Serial.println("LED 2 ON");
    delay(1000);
  });

  server.on("/LED2OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, LOW);
    Serial.println("LED 2 OFF");
    delay(1000);
  });

  // Menangani permintaan untuk LED 3

  server.on("/LED3ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D4, HIGH);
    Serial.println("LED 3 ON");
    delay(1000);
  });

  server.on("/LED3OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D4, LOW);
    Serial.println("LED 3 OFF");
    delay(1000);
  });
  
  server.begin();
  Serial.println("Web server started");
}


void loop(){
  server.handleClient();
}

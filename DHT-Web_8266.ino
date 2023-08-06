// Including the ESP8266 WiFi library
#include <ESP8266WiFi.h>
#include "SimpleDHT.h"

// Replace with your network details
const char* ssid = "";
const char* password = "";

byte temperature = 0;
byte humidity = 0;

// Web Server on port 80
WiFiServer server(80);

// DHT Sensor
const int dht_pin = 13;
// Initialize DHT sensor.
SimpleDHT11 dht11;


// only runs once on boot
void setup() {
  // Initializing serial port for debugging purposes
  Serial.begin(9600);
  delay(10);

  // Connecting to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Starting the web server
  server.begin();
  Serial.println("Web server running. Waiting for the ESP IP...");
  delay(5000);

  // Printing the ESP IP address
  Serial.println(WiFi.localIP());
}

// runs over and over again
void loop() {
  

  dht11.read(dht_pin, &temperature, &humidity, NULL);
  // Listenning for new clients
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New client");
    // bolean to locate when the http request ends
    boolean blank_line = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        if (c == '\n' && blank_line) {
          if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
          }
          else {
            // You can delete the following Serial.print's, it's just for debugging purposes
            Serial.print("Humidity: ");
            Serial.print(humidity);
            Serial.print(" %\t Temperature: ");
            Serial.print(temperature);
            Serial.print(" *C ");
          }
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          // your actual web page that displays temperature and humidity
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.println("<head></head><body><h1>ESP8266 - Temperature and Humidity</h1><h3>Temperature in Celsius: ");
          client.println(temperature);
          client.println("*C</h3><h3>");
          client.println("</h3><h3>Humidity: ");
          client.println(humidity);
          client.println("%</h3><h3>");
          client.println("</body></html>");
          break;
        }
        if (c == '\n') {
          // when starts reading a new line
          blank_line = true;
        }
        else if (c != '\r') {
          // when finds a character on the current line
          blank_line = false;
        }
      }
    }
    // closing the client connection
    delay(1);
    client.stop();
    Serial.println("Client disconnected.");
  }
}

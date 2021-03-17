#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

int pinDHT11 = 2; //Pin D4 on NodeMCU
SimpleDHT11 dht11(pinDHT11);
byte temperature = 0;
byte humidity = 0;
int err;
char auth[] = "oJY9ls3pQuck-AdmG-jJwDFqqc2h383Z";
char ssid[] = "Tenda_A32520";
char pass[] = "28032562";

BlynkTimer timer;

void sendData() {
    dht11.read(&temperature, &humidity, NULL);
    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
    Serial.print(temperature); Serial.print("  "); Serial.println(humidity);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(5000, sendData);
  Blynk.connect();
}

void loop() {
  Blynk.run();
  timer.run();
}

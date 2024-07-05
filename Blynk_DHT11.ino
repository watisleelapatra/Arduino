/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL6E6ndG0Zd"   //<----- ข้อมูลจาก template ที่สร้างขึ้น
#define BLYNK_TEMPLATE_NAME         "DHT11"           //<----- ข้อมูลจาก template ที่สร้างขึ้น
#define BLYNK_AUTH_TOKEN            "C0IwDPX7YJag-e5KqGUMBd69FXFnxqwK"    //<----- ข้อมูลจาก device ที่สร้างขึ้น

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "mate9";
char pass[] = "0816621438";

#define DHTPIN 14          // D5

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

SimpleDHT11 dht;
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  byte h = 0; 
  byte t = 0; 

  dht.read(DHTPIN, &t, &h, NULL);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print(t);
  Serial.print(" ");
  Serial.println(h);
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
  // Setup a function to be called every second
  timer.setInterval(5000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}

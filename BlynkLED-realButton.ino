/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "IVpSpGh4Md_vvnY_cXu4sloC0vZBJKOK";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tenda_A32520";
char pass[] = "28032562";

unsigned char btn = 1;
WidgetLED led1(V0);
BlynkTimer timer;

void myTimerEvent()
{
  if(btn == 1)
    led1.off();
  else
    led1.on();
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(0, INPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  Blynk.connect();
}

void loop()
{
  btn = digitalRead(0); //Pin D3 on NodeMCU
  Blynk.run();
  timer.run();
  
}

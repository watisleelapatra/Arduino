#define BLYNK_TEMPLATE_ID "TMPL6ds59DpMN"   //<--- เปลี่ยนบรรทัดนี้ตามหน้า Blynk Console
#define BLYNK_TEMPLATE_NAME "LED Template"  //<--- เปลี่ยนบรรทัดนี้ตามหน้า Blynk Console
#define BLYNK_AUTH_TOKEN "es5qocSbceF9pMAqRuNN_mIhlu4RGtuO" //<--- เปลี่ยนบรรทัดนี้ตามหน้า Blynk Console
#define BLYNK_PRINT Serial
#define D1 5
#define D2 4
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "mate9";
char pass[] = "0816621438";
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0){
  int value = param.asInt();
  if(value == 1){
    digitalWrite(D1, HIGH);
     Serial.println('1');
  }else{
   digitalWrite(D1, LOW);
    Serial.println('0');
  }
  }
BLYNK_WRITE(V1){
    int value = param.asInt();
  if(value == 1){
    digitalWrite(D2, HIGH);
     Serial.println('1');
  }else{
   digitalWrite(D2, LOW);
    Serial.println('0');
  }
  }
void setup(){
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}
void loop(){
  Blynk.run();
}

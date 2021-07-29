#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleDHT.h>

#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง 
 
// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int dht_pin = 2;
SimpleDHT11 dht11;
byte temperature = 0;
byte humidity = 0;

void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
 
void loop() {
  dht11.read(dht_pin, &temperature, &humidity, NULL);
  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK); //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println("Temp: "); // แสดงผลข้อความ ALL
  OLED.setCursor(60, 0);
  OLED.println(temperature);
  
  OLED.setCursor(0, 20);
  OLED.println("RH: ");
  OLED.setCursor(60, 20);
  OLED.println(humidity);
 
  OLED.display(); // สั่งให้จอแสดงผล
  delay(1000);
}

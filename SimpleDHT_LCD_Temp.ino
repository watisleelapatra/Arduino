#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SimpleDHT11 dht11;
const int dht_pin = 2; //GPIO2 = D4
byte humidity;
byte temperature;

void setup()
{
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
}
void loop() {
  dht11.read(dht_pin, &temperature, &humidity, NULL);
  Serial.print(temperature); Serial.print(" "); Serial.println(humidity);
  lcd.setCursor(0, 0);
  lcd.print("hum:     ");
  lcd.setCursor(4, 0);
  lcd.print(humidity);
  lcd.setCursor(9, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Tem:     ");
  lcd.setCursor(4, 1);
  lcd.print(temperature);
  lcd.setCursor(9, 1);
  lcd.print("C");
  delay(1000);

}

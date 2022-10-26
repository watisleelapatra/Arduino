#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EduIntro.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int dht_pin = 2; //GPIO2 = D4
byte humidity;
byte temperature;
DHT11 dht11(dht_pin);

void setup()
{
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
}
void loop() {
  dht11.update();
  temperature = dht11.readCelsius();
  humidity = dht11.readHumidity();
  //dht11.read(dht_pin, &temperature, &humidity, NULL);
  Serial.print(temperature); Serial.print(" "); Serial.println(humidity);
  /*
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
  */
  delay(2000);

}

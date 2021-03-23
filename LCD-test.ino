#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); 
//LiquidCrystal_I2C lcd(0x3F, 16, 2); 
void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0); //column 0 line 0
  lcd.print("Hello, world!"); 
  lcd.setCursor(2, 1); //column 2 line 1
  lcd.print("@#$%^&*|\/?1234"); 
}
void loop() {
  delay(2000);
  lcd.noBacklight();
  delay(2000);
  lcd.backlight();
}

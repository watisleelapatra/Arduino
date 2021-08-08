int pinTone = 5;
void setup() {
  pinMode(pinTone, OUTPUT);  
}

void loop() {
  tone(pinTone, 1000);
  delay(1000);
  tone(pinTone, 2000);
  delay(1000);
}

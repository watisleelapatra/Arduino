byte R = 9;
byte G = 10;
byte B = 11;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}
void loop() {
  // All off
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);
  delay(500);
  // Red ON
  analogWrite(R, 255);
  analogWrite(G, 0);
  analogWrite(B, 0);
  delay(500);
  // Green ON
  analogWrite(R, 0);
  analogWrite(G, 0255);
  analogWrite(B, 0);
  delay(500);
  // Blue ON
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 255);
  delay(500);
  // All ON
  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 255);
  delay(500);
}

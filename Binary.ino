byte n;
void setup() {
     Serial.begin(9600);
    for(n = 0; n < 100; n++) {
        Serial.print(n); Serial.print(" = ");
        Serial.println(n, BIN);
        delay(500);
    }
}

void loop() {
}

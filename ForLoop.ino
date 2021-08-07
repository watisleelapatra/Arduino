int i;
void setup() {
    Serial.begin(9600);
    Serial.println();
    for(i = 1; i <= 12; i++) {
        Serial.print(i); Serial.print("  "); Serial.println(i*2);
    }
}
void loop() {
}

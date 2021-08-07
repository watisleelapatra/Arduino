float C, F;

void setup() {
      Serial.begin(9600);
      Serial.println();
      Serial.println("---------------------");
      Serial.println("   C         F  ");
      Serial.println("---------------------");
      for(C = -10; C <= 40; C++) {
          //  C/5 = (F-32)/9
          F = (9.0/5.0)*C + 32.0;
          Serial.print(C,2); Serial.print("  "); Serial.println(F,2);
      }
}
void loop() {
}

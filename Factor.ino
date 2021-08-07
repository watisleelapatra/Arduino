int i;
int n = 13; 

void setup() {
    Serial.begin(9600);
      Serial.println();
      i = 1;
      while(i*n < 100) {
          Serial.println(i*n);
          i = i+1;
      }
      Serial.print("There are "); Serial.print(i-1); Serial.println(" numbers");
}
void loop() {
}

int k;
int n = 7; 
int nfact = 1;
void setup() {
    Serial.begin(9600);
    Serial.println();
    for(k = 1; k <= n; k++) {
      nfact = nfact*k;
      }
    Serial.print(n); Serial.print("! = "); Serial.print(nfact);
}
void loop() {
}

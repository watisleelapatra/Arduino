int Level;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Level = analogRead(A0);
  Serial.print("Level = ");
  Serial.print(Level);
  
  if (Level < 100) 
    Serial.print(" :No water");
  else if (Level >= 100 && Level < 300)
    Serial.print(" :Low water");
  else if (Level >= 300 && Level < 500)
    Serial.print(" :Medium water");  
  else if (Level >= 500 && Level < 800)
    Serial.print(" :High water");
  else if (Level >= 800)
    Serial.print(" :Very high water");  
    
  Serial.println();
  delay(1000);
}

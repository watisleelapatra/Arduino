const int strobe = 7;
const int clock = 9;
const int data = 8;

void sendCommand(uint8_t value)
{
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, value);
  digitalWrite(strobe, HIGH);
}

void reset()
{
  sendCommand(0x40); // set auto increment mode
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0xc0);   // set starting address to 0
  for(uint8_t i = 0; i < 16; i++)
  {
    shiftOut(data, clock, LSBFIRST, 0x00);
  }
  digitalWrite(strobe, HIGH);
}

void setup()
{
  pinMode(strobe, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);

  sendCommand(0x8f);  // activate
  reset();

  
  sendCommand(0x44);  // set single address
                         /*0*/ /*1*/ /*2*/ /*3*/ /*4*/ /*5*/ /*6*/ /*7*/ /*8*/ /*9*/
  //uint8_t digits[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
  /*
  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0xc0); // 1st digit
  shiftOut(data, clock, LSBFIRST, 0x3f);
  digitalWrite(strobe, HIGH);

  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0xc5); // 3rd LED
  shiftOut(data, clock, LSBFIRST, 0x01);
  digitalWrite(strobe, HIGH);

  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0xcb); // 3rd LED
  shiftOut(data, clock, LSBFIRST, 0x01);
  digitalWrite(strobe, HIGH);

  digitalWrite(strobe, LOW);
  shiftOut(data, clock, LSBFIRST, 0xce); // last digit
  shiftOut(data, clock, LSBFIRST, 0x06);
  digitalWrite(strobe, HIGH);
  */
}

void loop()
{
  unsigned int i;
  
  for(i = 0xc1; i <= 0xcf; i+=2) {
    digitalWrite(strobe, LOW);
    shiftOut(data, clock, LSBFIRST, i); // 3rd LED
    shiftOut(data, clock, LSBFIRST, 0x01);
    digitalWrite(strobe, HIGH);  
    delay(500);
    digitalWrite(strobe, LOW);
    shiftOut(data, clock, LSBFIRST, i); // 3rd LED
    shiftOut(data, clock, LSBFIRST, 0x00);
    digitalWrite(strobe, HIGH);  
  }
  delay(500); 
}

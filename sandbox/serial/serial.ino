char c;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(2400);
  delay(500);
}

void loop()
{
  if (Serial.available()) {
    c = Serial.read();
    if (c !=-1) {
      Serial.print(c);
    }
  }
  Serial.println("");
}

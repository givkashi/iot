
int ledPin = 4;
int pirPin = 2;
int lastState = LOW;
void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
   Serial.println(digitalRead(pirPin));
  if (digitalRead(pirPin))
  {
    digitalWrite(ledPin, HIGH);
    if (!lastState)
    {
      Serial.println("Somebody is here!");
      lastState = !lastState;
    }
  }
  else
  {
    digitalWrite(ledPin, LOW);
    if (lastState)
    {
      Serial.println("Went away!");
      lastState = !lastState;
    }
  }
  delay(10000);
}

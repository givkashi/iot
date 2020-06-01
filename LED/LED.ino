
int led =4; //pin D4 in arduino board 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  digitalWrite(led,HIGH);
  delay(40000);
  digitalWrite(led, LOW);
  delay(20000);
}

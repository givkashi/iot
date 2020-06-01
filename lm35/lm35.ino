
int s1=A0;

int reading;


void setup() {
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  pinMode(2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  reading=analogRead(s1)/4;  //0-1023  --> 0-255
  Serial.print("temp is:");
  Serial.println(reading);
  delay(3000);

}

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "zyqb0mXjJHiRydxRfA6v8jmDWduyVfj8";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HUAWEI-P30-lite";
char pass[] = "b013333bd424";

int LED = 2; // Define LED as an Integer (whole numbers) and pin D8 on Wemos D1 
WidgetLCD lcd(V6);

void setup()
{
  // Debug console
  Serial.begin(115200);
 pinMode(LED, OUTPUT); //Set the LED (D2) as an output
  Blynk.begin(auth, ssid, pass);
   randomSeed(analogRead(0));

  //Blynk.begin(auth, ssid, pass,IPAddress(188,166,206,43), 8080);
}

void loop()
{
  Blynk.run();
  lcd.clear();
   lcd.print(0,0,"Hello");
   delay(1000);
   lcd.clear();
   lcd.print(0,0,"World!");
    delay(1000);

}
 
// This function will be called every time button Widget
// in Blynk app writes values to the Virtual Pin V3
BLYNK_WRITE(V3) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(LED, HIGH); // Turn LED on.
  } else {
    digitalWrite(LED, LOW); // Turn LED off.
 }
}

BLYNK_READ(V5) // Widget in the app READs Virtal Pin V5 with the certain frequency
{
  // This command writes Arduino's uptime in seconds to Virtual Pin V5
  Blynk.virtualWrite(5, random(0, 100));
 
}

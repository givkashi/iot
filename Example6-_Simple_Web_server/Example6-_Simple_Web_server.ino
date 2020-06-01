#include <ESP8266WiFi.h>
const char* ssid = "HTC";
const char* password = "123456giv";
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}
void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }
  String req = client.readStringUntil('\r');
  Serial.println(req);
 // client.flush();
  String s;
s+= "<!DOCTYPE html>";
s+= "<html>";
s+=   "<body>";
s+=     "<h1>My First Heading</h1>";
s+=     "<p>My first paragraph.</p>";
s+=   "</body>";
s+=  "</html>";
  client.print(s);
  delay(1);
  Serial.println("Client disconnected");
}

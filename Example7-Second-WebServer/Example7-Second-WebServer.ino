#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


const char* ssid = "HTC";
const char* password = "123456789giv";

ESP8266WebServer server(80);

char temperatureString[6];
float getTemperature() {
  float temp=random(0,100);
  return temp;
}

void setup(void){
  randomSeed(analogRead(0));
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    float temperature = getTemperature();
    dtostrf(temperature, 2, 2, temperatureString);
  
    String title = "Temperature";
    String cssClass = "mediumhot";
  
    if (temperature < 20)
      cssClass = "cold";
    else if (temperature > 20)
      cssClass = "hot";
  
    String message = "<!DOCTYPE html><html><head><title>" + title + "</title><meta charset=\"utf-8\" /><meta name=\"viewport\" content=\"width=device-width\" /><link href='https://fonts.googleapis.com/css?family=Advent+Pro' rel=\"stylesheet\" type=\"text/css\"><style>\n";
    message += "html {height: 100%;}";
    message += "div {color: #fff;font-family: 'Advent Pro';font-weight: 400;left: 50%;position: absolute;text-align: center;top: 50%;transform: translateX(-50%) translateY(-50%);}";
    message += "h2 {font-size: 90px;font-weight: 400; margin: 0}";
    message += "body {height: 100%;}";
    message += ".cold {background: linear-gradient(to bottom, #7abcff, #0665e0 );}";
    message += ".mediumhot {background: linear-gradient(to bottom, #81ef85,#057003);}";
    message += ".hot {background: linear-gradient(to bottom, #fcdb88,#d32106);}";
    message += "</style></head><body class=\"" + cssClass + "\"><div><h1>" + title +  "</h1><h2>" + temperatureString + "&nbsp;<small>&deg;C</small></h2></div></body></html>";
    
    server.send(200, "text/html", message);
  });

  server.begin();
  
  Serial.println("Temperature web server started!");
}

void loop(void){
  server.handleClient();
}

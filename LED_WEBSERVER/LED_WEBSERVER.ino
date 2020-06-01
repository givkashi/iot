#include <SPI.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "HTC";
const char* password = "123456789giv";


int led = 2;
 
WiFiServer server(80);
  
String readString;
void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
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
  server.begin();
  Serial.println(WiFi.localIP());

}
void loop() {
    WiFiClient client = server.available();
    if (client) {
      while (client.connected()) {   
        if (client.available()) {
          char c = client.read();
          //read char by char HTTP request
          if (readString.length() < 100) {
              //store characters to string
              readString += c;
          }
          //if HTTP request has ended
          if (c == '\n') {          
              Serial.println(readString); //print to serial monitor for debuging
              client.println("HTTP/1.1 200 OK"); //send new page
              client.println("Content-Type: text/html");
              client.println();     
              client.println("<HTML>");
              client.println("<HEAD>");
              client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
              client.println("<TITLE>My Tiny Web Server</TITLE>");
              client.println("</HEAD>");
              client.println("<BODY>");
              client.println("<H1>freeterminal.ir Tutorials Project</H1>");
              client.println("<hr />");
              client.println("<br />");  
              client.println("<H2>ESP8266</H2>");
              client.println("<br />");  
              client.println("<a href=\"/?button1on\"\">Turn On LED</a>");
              client.println("<a href=\"/?button1off\"\">Turn Off LED</a><br />");   
              client.println("<br />");     
              client.println("<br />"); 
              client.println("<p>Created by freeterminal.ir. Visit http://freeterminal.ir for more projects!</p>");  
              client.println("<br />"); 
              client.println("</BODY>");
              client.println("</HTML>");
              delay(1);
              client.stop();
              if (readString.indexOf("?button1on") >0){
                  digitalWrite(led, HIGH);
              }
              if (readString.indexOf("?button1off") >0){
                  digitalWrite(led, LOW);
              }
              readString="";  
              }
        }
      }
    }
 }

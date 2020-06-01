/*
 Hello World Thinger.io -Blink-

 This code is under public domain.
 Dani No www.esploradores.com
 */

#include <ESP8266WiFi.h>       //ESP8266 WiFi connection library
#include <ThingerESP8266.h>    //THINGER.IO library

// Thinger.io connection parameters
#define user "Salman"
#define device_Id "IoTTest"
#define device_credentials "s!%8DVUrjgw#"
ThingerESP8266 thing(user, device_Id, device_credentials);
// WiFi connection parameters
const char WiFi_ssid[]="HUAWEI-P30-lite";      //WiFi SSID
const char WiFi_password[]="b013333bd424";  //WiFi password
// Global variable
int led = 2;       // GPIO02 - D4 
void setup() {
   thing.add_wifi(WiFi_ssid, WiFi_password);
 randomSeed(analogRead(0));
  }
void loop() {
  thing["TempHum"] >> [](pson &out){
  out["temperature"] =  random(0, 100);
  out["humadity"] =  random(0, 100); 
  }; 
  thing.handle();
  thing.stream("TempHum");
  if(random(0, 100)>30)
     thing.write_bucket("FromWriteCall", "TempHum");
  }

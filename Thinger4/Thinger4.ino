/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#include <ESP8266WiFi.h>       //ESP8266 WiFi connection library
#include <ThingerESP8266.h>    //THINGER.IO library

// Thinger.io connection parameters
#define user "mohammad1998"
#define device_Id "esp8266"
#define device_credentials "l!EM@5n#RFzY"
ThingerESP8266 thing(user, device_Id, device_credentials);

// WiFi connection parameters
const char WiFi_ssid[]="HTC";      //WiFi SSID
const char WiFi_password[]="123456giv";  //WiFi password
// Global variable
int led = 2;       // GPIO02 - D4

void setup() {

 // Initialization of the WiFi connection with THINGER.IO
   thing.add_wifi(WiFi_ssid, WiFi_password);

      randomSeed(analogRead(0));//chon sensor nadarim in raneveshtim ke adad motafavet bashad
   // port 0be jaei vasl nist va noiz mishavad 

   pinMode(led, OUTPUT);

  thing["LED"] << [] (pson & in){
    if(in.is_empty()){
      in = (bool) digitalRead(led);
    }
    else{
      digitalWrite(led, in ? HIGH : LOW);
    }
  };
   
 }


void loop() {
  
  thing["TempHum"] >> [] (pson & out){//& yani format va khoroji bodan an ast
    out["temperature"] = random(0,100);;
    out["humadity"] = random(0, 100);;
  };
  thing.handle();
  thing.stream("TempHum");                //har bar dar loop temphum ra miferestad be abr
//balaei hamishe dar bucket mirize
  if(random(0,100) > 30){
    thing.write_bucket("FromWriteCall" , "TempHum");
  }
  }

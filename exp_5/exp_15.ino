#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#define led 2
#define red 15
#define green 12
#define blue 13

WiFiClient client;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
  WiFi.softAP("JagrutiBhoyar", "Jagruti@123");
  Serial.println("WittyBoard started");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  client=server.available();
   if(client == 1){
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledON/ HTTP/1.1")
      digitalWrite(green, HIGH);
    if(request == "GET /ledOFF/ HTTP/1.1")
      digitalWrite(green, LOW);
  }  

}

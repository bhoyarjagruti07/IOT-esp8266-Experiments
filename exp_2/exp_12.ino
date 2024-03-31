#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("JagrutiBhoyar","Jagruti@123");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print('.');
    delay(200);
  }
  Serial.println();
  Serial.println("Witty board connected!");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}

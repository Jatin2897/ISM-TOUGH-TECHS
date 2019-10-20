
//#include <WiFiClient.h>
//#include <WiFiServer.h>
#include <ESP8266WiFi.h>

const char*ssid="OnePlus6t";
const char*password="kanpur12";
const int ledPin=2;
WiFiServer server(1337);
void printWiFistatus();


void setup(void) {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  // configure GP102 as output
  pinMode(ledPin,OUTPUT);
  //start tcp server.
  server.begin();

}

void loop(void) {
  if(WiFi.status() !=WL_CONNECTED){
    while(WiFi.status() !=WL_CONNECTED){
      delay(500);
    }
  }
  // print the new ip to serial
 
 printWiFiStatus();
  
 WiFiClient client=server.available();
 if(client){
   Serial.println("client connected.");
   while(client.connected()){
     if(client.available()){
       char command=client.read();
       if(command=='H'){
         digitalWrite(ledPin,HIGH);
         Serial.println("LED is now on.");
       }
       else if (command=='L'){
         digitalWrite(ledPin,LOW);
         Serial.println("LED is now off.");
       }
     }
   }
   Serial.println("Client disconnected.");
   client.stop();
 }
}
 
void printWiFiStatus(){
  Serial.println("");
  Serial.print("connected to OnePlus6t");
  Serial.println(ssid);
  Serial.print("IP address:");
  Serial.println(WiFi.localIP());
}

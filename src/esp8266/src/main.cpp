
#include <Arduino.h>
#include "wifiConfig.h"
#include <ESP8266WiFi.h>
#include <interface.h>

WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  WiFi.begin(SSID, PASS);
  Serial.println("starting server");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  
  server.begin();
  // put your setup code here, to run once:
}

void loop()
{
  WiFiClient client = server.available();
  String header = "";

  if (client)
  {

    while (client.connected())
    {
      if (client.available())
      {

        char c = client.read();
        header += c;

        if (c == '\n')
        {
          Serial.printf("IP: %s\n", WiFi.localIP().toString().c_str());
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println("Connection: close");
          client.println();
          if (header.indexOf("GET /"))
          {

            header = "";
          }
          else if (header.indexOf("GET /left" > 0))
          {

            Serial.println("LEFT");
            header = "";
          }
          else if (header.indexOf("GET /right" > 0))
          {

            Serial.println("RIGHT");
            header = "";
          }
          client.println( interface);
          client.println();
          header = "";
          break;
        }
      }
    }
  }
}
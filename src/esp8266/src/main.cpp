
#include <Arduino.h>
#include "wifiConfig.h"
#include <ESP8266WiFi.h>
#include <interface.h>

WiFiServer server(80);

void setup()
{
  Serial.begin(115200)
  WiFi.begin(SSID, PASS);
  Serial.println("starting server");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.printf("ip: %s", WiFi.localIP().toString().c_str());
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

            Serial.println("left");
            header = "";
          }
          else if (header.indexOf("GET /right" > 0))
          {

            Serial.println("right");
            header = "";
          }
          client.printf("%s", interface);
        }
      }
    }
  }
}
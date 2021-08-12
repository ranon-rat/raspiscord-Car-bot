#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
String ip = "";
//SoftwareSerial esp(19,18);// RX, TX
LiquidCrystal_I2C lcd(0x27, 20, 4);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  //esp.begin(9600);
  Serial.println("test");
  

}

void loop()
{

  if (Serial.available())
  {
    
    lcd.clear();
    String out = "";
    while (Serial.available())
    {
      String out = Serial.readString();
      Serial.println(out);
      //lcd.print(out);
      //delay(1000);
      //lcd.clear();

     /* if (out.indexOf("IP"))
        ip = out;
      else if(out.indexOf("LEFT"))
      {
        lcd.setCursor(0, 0);
        lcd.print(ip);
        lcd.setCursor(0, 1);
        lcd.print(out);
        

        
      }else if(out.indexOf("RIGHT")){
        lcd.setCursor(0, 0);
        lcd.print(ip);
        lcd.setCursor(0, 1);
        lcd.print(out);
      }*/

    }

   
  }

  
}
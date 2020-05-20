#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

RF24 radio(7,8); // CNS, CE

const byte address[6] = "00001";

void setup()
{
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop()
{
  if(radio.available())
  {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    lcd.print(text);
    delay(1000);
    lcd.clear();
  }
}

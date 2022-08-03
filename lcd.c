/*
gnd > gnd
vcc > 5v
sda > A4
scl > A5
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  delay(5000);
  lcd.clear();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Hello, world 2");
  delay(5000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Hello, world 3");
  delay(5000);
}

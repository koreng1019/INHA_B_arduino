#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(16, 0);
  lcd.print("Hello, World!");
  lcd.setCursor(16, 1);
  lcd.print("Welcome INHA!");
  
  for (int position = 0; position < 32; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  
  for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
}


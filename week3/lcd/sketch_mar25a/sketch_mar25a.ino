#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Serial.println("I2C Scanner Runnning...");
}

void loop() {
  Serial.println("Scanning...");

  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C 장치 발견: 0x");
      Serial.println(address, HEX);
      delay(500);
    }
  }

  Serial.println("Scan Complete! Retrying in % seonds...\n");
  delay(5000);
}

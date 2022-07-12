#include <Wire.h>
#include "LiquidCrystal_I2C.h"


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init(); // lcd 시작
  lcd.backlight(); // lcd 백라이트 on
  Serial.begin(9600); // 속도 9600bps로 시리얼 통신시작
  Serial.println("LCD통신 시작"); // 시리얼 통신 시작 문자 출력
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}

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
  // 커서 설정(열,행) 0부터 시작
  lcd.setCursor(0, 0);
  lcd.print("Hello");  // LCD에 출력

  lcd.setCursor(0, 1);
  lcd.print("KSOP World");  // LCD에 출력

}

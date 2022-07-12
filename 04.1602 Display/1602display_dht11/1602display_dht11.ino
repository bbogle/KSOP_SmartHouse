#include <Wire.h>
#include "LiquidCrystal_I2C.h"  // I2C LCD 라이브러리
#include "DHT.h"            // 온습도센서 라이브러리
#include "Emoticon.h"            // 특수문자 라이브러리

#define DHTPIN 6
#define DHTTYPE DHT11       //DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

char str2[10];                        //습도 값
char str3[10];                        //온도 값

void setup()
{
  Serial.begin(9600); // 속도 9600bps로 시리얼 통신시작
  Serial.println("LCD통신 시작"); // 시리얼 통신 시작 문자 출력
  lcd.init(); // lcd 시작
  lcd.clear();
  lcd.noBacklight();
  delay(500);
  lcd.backlight(); // lcd 백라이트 on
  delay(500);
  // 커서 설정(열,행) 0부터 시작
  lcd.setCursor(0, 0);
  lcd.print("Hello");  // LCD에 출력
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("KSOP World");  // LCD에 출력
  delay(1000);
  lcd.clear();

  // 특수 문자 선언
  lcd.createChar(0, ug1);
  lcd.createChar(1, ug2);
  lcd.createChar(2, temp);
  lcd.createChar(3, C);
  lcd.createChar(4, humi);
  lcd.createChar(5, per);

  Serial.println("Display SETTING INIT OVER");
}

void loop() {
  update_lcd1602();
  delay(300);
}

void update_lcd1602() {
  static int cnt = 0;
  cnt++;
  if (cnt >= 10) {    // 업데이트 간격 (delay 300 인경우, 10회 * 0.3초 = 3초)
    cnt = 0;
    unsigned char t = dht.readTemperature();
    unsigned char h = dht.readHumidity();    
    lcd.setCursor(0, 1);
    lcd.write(2);   // 온도계 이모티콘
    lcd.print("  ");
    sprintf(str2, "%02d", t);
    lcd.print(str2);
    lcd.write(3);   // 섭씨표시
    lcd.print("  ");
    lcd.write(4);   // 습도 이모티콘
    lcd.print("  ");
    sprintf(str3, "%02d", h);
    lcd.print(str3);
    lcd.write(5);   // 퍼센트(%) 표시
    lcd.setCursor(0, 0);
    lcd.print("KSOP SMART HOUSE");
  }
}

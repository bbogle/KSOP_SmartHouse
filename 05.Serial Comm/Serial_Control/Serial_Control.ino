#include "Setting.h"   // 핀 설정
#include <Wire.h>
#include "LiquidCrystal_I2C.h"  // I2C LCD 라이브러리
#include <SoftwareSerial.h>     // 블루투스 통신 라이브러리
#include "DHT.h"                // 온습도센서 라이브러리
#include "Emoticon.h"           // 특수문자 라이브러리

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

char str2[10];                        //습도 값
char str3[10];                        //온도 값
char data;                            //데이터값

int ON = 1;
int OFF = 0;
int dim = 0;  

// 현재 LED의 상태를 저장하는 배열. 0일경우 OFF, 1일 경우 ON
byte sensor[] = {0, 0, 0};

boolean TV = ON;

void setup()
{
  Serial.begin(9600); // 속도 9600bps로 시리얼 통신시작
  Serial.println("LCD통신 시작"); // 시리얼 통신 시작 문자 출력
  lcd.init(); // lcd 시작
  lcd.clear();
  lcd.noBacklight();
  delay(200);
  lcd.backlight(); // lcd 백라이트 on
  delay(200);
  // 커서 설정(열,행) 0부터 시작
  lcd.setCursor(0, 0);
  lcd.print("Hello");  // LCD에 출력
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("KSOP World");  // LCD에 출력
  delay(1000);
  lcd.clear();

  // 핀모드 출력 선언
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // 특수 문자 선언
  lcd.createChar(0, ug1);
  lcd.createChar(1, ug2);
  lcd.createChar(2, temp);
  lcd.createChar(3, C);
  lcd.createChar(4, humi);
  lcd.createChar(5, per);

  Serial.println("Display SETTING INIT OvER");
}

void loop() {
  if(Serial.available()) {
    data = Serial.read();

    // LED 제어
    if(data == '1')         // 거실 등 ON/OFF
      setToggle(led1, sensor[0]);
    else if (data == '2')   // 방1 등 ON/OFF
      setToggle(led2, sensor[1]);
    else if (data == '3')   // 방2 등 ON/OFF
      setToggle(led3, sensor[2]);

    // 에어컨 제어
    else if(data == '4')      // 에어컨 ON/OFF
      setAircon();

    // TV ON/OFF
    else if(data == '5')
      tvControl();

   // All ON/OFF
    else if(data == '6')
      allOff(); 
  }

  if(TV == ON){
    update_lcd1602();
    delay(200);
  }
}

// lcd 업데이트
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

//LED 토글함수
void setToggle(int PIN, byte& stat) {
  if (stat == OFF) {
    digitalWrite(PIN, HIGH);
    stat = ON;
  }
  else {
    digitalWrite(PIN, LOW);
    stat = OFF;
  }
}

//에어컨 제어함수
void setAircon() {
  if(dim == 0){
    analogWrite(motor, 120);
    dim = 1;
  } else if(dim ==1) {
    analogWrite(motor, 180);
    dim = 2;
  } else if(dim ==2) {
    analogWrite(motor, 250);
    dim = 3;
  } else {
    analogWrite(motor, 0);
    dim = 0;
  }
}


// TV 제어함수
void tvControl(){
  if(TV == OFF){
    lcd.backlight();
    TV = ON;
  } else {
    lcd.clear();
    lcd.noBacklight();
    TV = OFF;
  }
}

// 전체 전원끄기
void allOff() {
  byte sensor2[] = {1, 1, 1};
  setToggle(led1, sensor2[0]);
  setToggle(led2, sensor2[1]);
  setToggle(led3, sensor2[2]);
  sensor[0] = sensor[1] = sensor[2] = 0;
  dim = 3;  
  setAircon();
  TV = ON;
  tvControl();
}

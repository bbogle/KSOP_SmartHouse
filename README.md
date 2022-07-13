# KSOP_SmartHouse

소스코드 파일 목록

#01. LED
* LED - led 껐다 켰다 하는 코드
* LED_LIGHT - led 순차적으로 밝기 fadeOn, fadeOff 코드

#02. FAN
* FAN_test	- DC모터를 1초간격으로 켰다 껐다 반복하는 코드
* FAN_speed_test - DC모터를 3초간격으로 속도를 다르게 하면서 테스트 하는 코드

#03. Temperature and Humidity sensor
* DHT11 - 온습도계 테스트 (시리얼 모니터) 

#04. 1602 Display
* 1602display - 디스플레이 출력
* 1602display_dht11 - 디스플레이에 온습도 출력
* 1602SerialDisplay - 시리얼모니터로 입력된 문자열을 Display에 출력

#05. Serial Comm
* Serial_Control - 시리얼통신으로 제어하는 하우스 

#06. Bluetooth Comm
* Bluetooth_Control - 블루투스 어플로 제어하는 하우스
* Bluetooth_TempHumi - 블루투스 어플로 온습도 출력
  
#[App]KSOP_Smart_House 
* 앱인벤터 프로젝트 파일 - KSOP 스마트 하우스


#CH341SER.zip
* CH340을 사용한 SMD 타입 아두이노 보드인 경우 필수적으로 설치해야 하는 USB드라이버

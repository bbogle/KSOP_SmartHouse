#include <SoftwareSerial.h>
#include "DHT.h";
#define DHTPIN 6     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial BTSerial(2,3); //(RX,TX)

float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()  { 
  Serial.begin(9600);
  BTSerial.begin(9600);
  dht.begin();
  delay(2000);
}

void loop()  {
  hum = dht.readHumidity();//온도 읽기
  temp= dht.readTemperature();//습도 읽기

  Serial.print("999");
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(hum);
  Serial.print(",");
  Serial.println("888");

  BTSerial.print("999");
  BTSerial.print(",");
  BTSerial.print(temp, 1);
  BTSerial.print(",");
  BTSerial.print(hum, 0);
  BTSerial.print(",");
  BTSerial.println("888");
  delay(2000);// 샘플링 간격 2초 부여
}

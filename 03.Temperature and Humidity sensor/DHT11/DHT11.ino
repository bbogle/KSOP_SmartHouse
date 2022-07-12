#include "DHT.h"

#define DHTPIN 6    //put the sensor in the digital pin 6  

#define DHTTYPE DHT11 //DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()  {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop()  {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("℃ ");
  Serial.print(f);
  Serial.print("℉\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print("℃ ");
  Serial.print(hif);
  Serial.println("℉");
}

#include <LiquidCrystal.h>
#include <Adafruit_BMP085.h>
#include "DHT.h"
#define DHTPIN 2 //Arduino PIN
#define DHTTYPE DHT11 // DHT11 Type
 
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;
 
void setup() {
  Serial.begin(9600);
  Serial.println("Connected");
  bmp.begin();
  dht.begin();
}
 
void loop() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  float y = bmp.readPressure();
  float presMb = presPa * 1013.25 / 101325;
  Serial.print(h);
  Serial.print(t);
  Serial.print(y);
}

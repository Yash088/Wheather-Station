#include <DHT.h> 

#include <SFE_BMP180.h>
#include <Wire.h>
SFE_BMP180 pressure;
float temperature;
#define ALTITUDE 216.0 // Altitude
#define DHTPIN 16     // what pin we're connected to
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  
  Serial.begin(9600);
  Serial.println("Connected");

  dht.begin();
  pressure.begin();
}


void loop{
float humidity, pressure;
 humidity = dht.readHumidity();/reading dht HUmidity

 pressure = readPressureAndTemperature();//function object
delay(2000);

  
Serial.print("T:")
Serial.print( temperature)


Serial.println("P:")
Serial.println(pressure)

Serial.println("H:")
Serial.println(humidity)

 
//function defination
float readPressureAndTemperature()

{

  char status;

  double T,P,p0,a;


  status = pressure.startTemperature();

  if (status != 0)

  {

    delay(status);

    status = pressure.getTemperature(T);

    if (status != 0)

    {

      temperature = T;

      status = pressure.startPressure(3);

      if (status != 0)

      {

        delay(status);

        status = pressure.getPressure(P,T);

        if (status != 0)

        {

          p0 = pressure.sealevel(P,ALTITUDE);      

          return p0;

        }

      }

    }

  }

}

#include <DHT.h> 
#include <LiquidCrystal.h>
#include <SFE_BMP180.h>
#include <Wire.h>
SFE_BMP180 pressure;
float temperature;
#define ALTITUDE 216.0 // Altitude
#define DHTPIN 16     // what pin we're connected to
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8,9,4,5,6,7);//en rs 4 data pins


void setup(void) {
  lcd.begin(16, 2);
  lcd.print("Reading sensors");
  dht.begin();
  pressure.begin();
}

void loop() {

 float humidity, pressure;
 humidity = dht.readHumidity();/reading dht HUmidity

 pressure = readPressureAndTemperature();//function object
delay(2000);

 lcd.clear();//clearing the lcd

 char tempF[12];

 char humF[15];

 char pressF[7];

 
//converting the values to display as float values
 dtostrf(temperature, 5, 1, tempF);

 dtostrf(humidity, 1, 0, humF);

 dtostrf(pressure, 7, 2, pressF);


 //Printing Temperature

 lcd.print("T:");

 lcd.print(tempF);

 lcd.print((char)223);

 lcd.print("C

 ");

 

 //Printing Humidity

 lcd.print("H:");

 lcd.print(humF);

 lcd.print("%");

  //Printing Pressure

 lcd.setCursor(0,1);

 lcd.print("P: ");

 lcd.print(pressF);

 lcd.print(" hPa");

}

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

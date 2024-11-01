#include <DS18B20.h>

#include <Wire.h>
#include "SparkFunBME280.h"

int DS18B20_Pin = 9; //DS18S20 Signal pin on digital 9

//Create DS18B20, BME280 objects
DS18B20 ds(DS18B20_Pin);
BME280 bmeSensor;

void setup() {
  // put your setup code here, to run once:
//ds.readSensor();

Serial.begin(9600);
Serial.println("Weather Station DS18B20, BME280 Sensor Test");
Serial.println("DE Temp \tBME Temp\tHumidity\tPressure");

Wire.begin();

if (bmeSensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//ds.readSensor();

//Serial.print(ds.getTempC()); Serial.print(" *C\t");
Serial.print(ds.getTempF()); Serial.print(" *F\t");
Serial.print(bmeSensor.readTempF(), 2); Serial.print(" *F\t");
Serial.print(bmeSensor.readFloatHumidity(), 0); Serial.print(" %\t");
Serial.print(bmeSensor.readFloatPressure(), 0); Serial.println(" mb");

// Add a 2 second delay
delay(2000);
}

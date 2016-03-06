/* Team Quaar   *
 * sensor_driver */

/* This is the driver for our sensor codes */

/* Program Libraries */
#include "sensors.h"

/* Libraries */
#include <OneWire.h>
#include <SHT1x.h>
#include <Wire.h>

/* Global Function */

void temp(void);
void pressure(void);
void humidity(void);
void irradiance(void);

void setup(){
 Serial.begin(9600);
 if (!bmp.begin()) {
 while(1) {}
 }
 }

void loop() {
 /* Print out tempature values */
 Serial.print("Temperature = ");
 Serial.print(celsius);
 Serial.print(fahrenheit);
 Serial.println(" Fahrenheit");

 /* Print out humidity value */
  Serial.print("Humidity: ");
  Serial.print(humidityper);
  Serial.println("%");
 
 /* Print out pressure values */
  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

 /* Print out irradiance value */
  Serial.print("Irradiance = ");
  Serial.print(irradiancemV);
  Serial.println(" mV)";

 /* Sets how frequent you want your data */
  delay(1000);

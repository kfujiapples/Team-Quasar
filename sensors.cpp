/* Team Quaser *
 * sensors.cpp */

/* Libraries used */

#include "sensors.h"
#include "config.h"

/* Set Pins */
Adafruit_BMP085 bmp;
SHT1x sht1x(HUMID_DATA, HUMID_CLK);
OneWire ds(ROOF_TEMP);

/* Function intializer */

void init1(void){
   bmp.begin();
}

/*----------------*/
/*------Temp------*/
/*----------------*/

int16_t temp(void)
 {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  int16_t celsius, fahrenheit;
    
  if (!ds.search(addr)) {
      Serial.println();
      ds.reset_search();
  }

 if (OneWire::crc8(addr, 7) != addr[7]) {
 Serial.println("No Temp Address");

 }
 ds.reset();
 ds.select(addr);
 ds.write(0x44, 1);

 present = ds.reset();
 ds.select(addr);    
 ds.write(0xBE);

 for ( i = 0; i < 9; i++) {           // we need 9 bytes
     data[i] = ds.read();
     }

/* Convert the data to actual temperature */
 int16_t raw = (data[1] << 8) | data[0];
 if (type_s) {
/* 9 bit resolution default */
 raw = raw << 3;
/* gives full12 bit resolution */
 if (data[7] == 0x10) {
 raw = (raw & 0xFFF0) + 12 - data[6];
 }

} else {
      byte cfg = (data[4] & 0x60);
 /* At lower res, the low bits are undefined, so let's zero them */
  if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
  else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
  else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
 }

/* Returns data */

celsius = (int16_t)raw / 16.0;
//fahrenheit = celsius * 1.8 + 32.0;

/* Debug Temp */
//Serial.print("Temp");
//Serial.println(celsius);
 
return celsius;
//return fahrenheit;
}

/*-----------------*/
/*----Humidity-----*/
/*-----------------*/

uint16_t humidity(void){
uint16_t humidityper = sht1x.readHumidity();

/* Debug Humidity */
//Serial.print("Humidity");
//Serial.println(humidityper);
 
return humidityper;
}

/*----------------*/
/*----Pressure----*/
/*----------------*/

int32_t pressure(void){
int32_t pressurePa = bmp.readPressure();

/* Debug Pressure */
//Serial.print("Pressure");
//Serial.println(pressurePa);

return pressurePa;
}

/*----------------*/
/*---Irradiance---*/
/*----------------*/

uint16_t irradiance(void){
uint16_t irradiancemV = analogRead(APOGEE_SOLAR)*5000.0/1023;

/* Debug Irradiance */
//Serial.print("Solar Irradiance");
//Serial.println(irradiancemV);

return irradiancemV;
}

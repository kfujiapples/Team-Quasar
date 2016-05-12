/* Team Quasar *
 * sensors.cpp */

/* Libraries used */

#include "sensors.h"
#include "config.h"
#include <SoftwareSerial.h>

/* Sensor object variables */
Adafruit_BMP085 bmp;
SHT1x sht1x(HUMID_DATA, HUMID_CLK);
OneWire onewire(ROOF_TEMP);
DallasTemperature roof_temp(&onewire);

/* Function intializer */
void init1(void){
   bmp.begin(); //Pressure initialization
}

/*----------------*/
/*------Battery------*/
/*----------------*/
uint16_t battery(void)
{
    int16_t battery;
    
    battery = analogRead(BATTERY)*5000.0/1023;

    /* Debug Battery */
    Serial.print("Battery");
    Serial.println(battery);
    
    return battery;
}

/*----------------*/
/*------Panel------*/
/*----------------*/
uint16_t panel(void)
{
    int16_t panel;
    
    panel = 2*analogRead(PANEL)*5000.0/1023;
    
    /* Debug Panel */
    Serial.print("Panel");
    Serial.println(panel);
    return panel;
}

/*----------------*/
/*------Temp------*/
/*----------------*/

int16_t temp(void)
{   int16_t celsius = 0;

    //celsius =  bmp.readTemperature(); //bmp085 pressure sensor temp reading
    
    roof_temp.requestTemperatures();
    celsius = roof_temp.getTempCByIndex(0);

    /* Debug Temp */
    Serial.print("Temp");
    Serial.println(celsius);
    return celsius;
}

/*-----------------*/
/*----Humidity-----*/
/*-----------------*/

uint16_t humidity(void){
    uint16_t humidityper = sht1x.readHumidity();

    /* Debug Humidity */
    Serial.print("Humidity");
    Serial.println(humidityper);
 
return humidityper;
}

/*----------------*/
/*----Pressure----*/
/*----------------*/

uint32_t pressure(void){
    uint32_t pressurePa = bmp.readPressure();

    /* Debug Pressure */
    Serial.print("Pressure");
    Serial.println(pressurePa);

    return pressurePa;
}

/*----------------*/
/*---Irradiance---*/
/*----------------*/

uint16_t irradiance(void){
    uint16_t irradiancemV = analogRead(APOGEE_SOLAR)*5000.0/1023;

    /* Debug Irradiance */
    Serial.print("Solar Irradiance");
    Serial.println(irradiancemV);

    return irradiancemV;
}

/* Team: Team Quasar *
 * File: sensors.h   */

/* Check for previous includes */
#ifndef sensors_h
#define sensors_h

/* External libraries */

#include <OneWire.h>
#include <SHT1x.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

/* Pin configuration */

#define dataPin  11
#define clockPin 12
#define Temp 10
#define apogee A0

/* Theses are the functions for our code */

void temp(void);
void pressure(void);
void humidty (void);
void irradiance(void);

#endif

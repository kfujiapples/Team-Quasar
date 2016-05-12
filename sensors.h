/* Team: Team Quasar *
 * File: sensors.h   */

/* Check for previous includes */
#ifndef SENSORS_H
#define SENSORS_H

/* External libraries */
#include <OneWire.h>
#include <SHT1x.h>
#include <Adafruit_BMP085.h>
#include <DallasTemperature.h>

/* Included header files */
#include "config.h"

/* Sensor object variables */
extern Adafruit_BMP085 bmp;
extern SHT1x sht1x;
extern OneWire R_temp;
extern DallasTemperature roof_temp;

/* Initialization function */
void init1(void);

/* Sensor functions */
uint16_t battery(void);
uint16_t panel(void);
int16_t temp(void);
uint32_t pressure(void);
uint16_t humidity (void);
uint16_t irradiance(void);

#endif

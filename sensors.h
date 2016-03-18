/* Team: Team Quasar *
 * File: sensors.h   */

/* Check for previous includes */
#ifndef SENSORS_H
#define SENSORS_H

/* External libraries */
#include <OneWire.h>
#include <SHT1x.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>

/* Included header files */
#include "config.h"

/* Pin configuration */

/*#define dataPin  11
#define clockPin 12
#define Temp 3
#define apogee A2*/

/* These are the functions for our code */
void init1(void);
int16_t temp(void);
int32_t pressure(void);
uint16_t humidity (void);
uint16_t irradiance(void);

#endif

/* schema.h */

/* External Libraries */
#include <stdint.h> //standard integer type library

/* Check for previous includes */
#ifndef SCHEMA_H
#define SCHEMA_H

/* Struct for Binary packet transfer */
typedef struct {
    
    /* Identification information */
    uint16_t schema_ID;      //Schema ID number
    uint16_t address;     //Arduino Address
    
    /* Overflow flags */
    uint8_t overflow_num;  //Number of times function millis() overflow

    /* Data variables */
    //uint16_t batt[15];   //Battery voltage (millivolts)
    //uint16_t panel[15];  //Panel voltage (millivolts)
    uint8_t n;       //Number of data points in packet (0...30)
    int16_t temp;   //Temperature value (celsius)
    uint16_t humidity; //Humidity value (centi-pascals)
    uint16_t irradiance[60];    //Solar Irradiance (millivolts)
    uint32_t uptime;    //Time since the start of program
    uint32_t pressure;  //Pressure value (pascals)

} schema;


/* Struct for Health Check */
typedef struct {
  
  /* Identification information */
  uint16_t schema;  //Schema ID number
  uint16_t address; //ADdress of Arduino
  
  /* Data variables */
  uint32_t uptime_health; //Time since the start of program
  uint16_t batt; //Battery voltage (millivolts)

} schema_5;

typedef schema_5 schema_health;
#endif

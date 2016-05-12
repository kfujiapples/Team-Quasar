/* schema.h */

/* External Libraries */
#include <stdint.h> //standard integer type library

/* Check for previous includes */
#ifndef SCHEMA_H
#define SCHEMA_H

typedef struct {
    uint16_t schema;      //Schema ID number
    uint16_t address;     //Arduino Address
    uint32_t uptime_ms;    //Time since the start of program
    uint16_t batt_mv[6];   //Battery voltage (millivolts)
    uint16_t panel_mv[6];  //Panel voltage (millivolts)
    uint32_t bmp185_press_pa;  //Pressure value (pascals)
    int16_t bmp185_temp_decic;   //Temperature value (celsius)
    uint16_t humidity_centi_pct; //Humidity value (centi-pascals)
    uint16_t solar_irr_w_m2[20];    //Solar Irradiance (millivolts)
} schema_296_full;

#endif

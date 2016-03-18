/* config.h */
/* Team: Team Quasar */
/* config.h
 * Pin configuration for ATMEGA 328P
 */

#ifndef CONFIG_H
#define CONFIG_H

//pin declarations
//Arduino Pins
//Solar Irradiance
#define APOGEE_SOLAR A2

//Receiver/Transmitter
#define PIN_RX 0
#define PIN_TX 1

//XBee
#define XBEE_TX 0
#define XBEE_RX 1
#define XBEE_SLEEP 13

//Temp
#define ROOF_TEMP 3

//Humidity
#define HUMID_CLK 7
#define HUMID_DATA 8

#endif

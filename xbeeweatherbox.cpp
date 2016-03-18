/* xbee weatherbox */

/* Program Libraries */
#include "config.h"
#include "sensors.h"
#include "transmit.h"
#include "schema.h"

/* Libraries */
/* Arudino Libraries */
#include <Wire.h> //Temp library
#include <EEPROM.h>

/* External Libraries */
#include <SHT1x.h> //SHT11 Humidity
#include <OneWire.h> //DS18B20 Temperature
#include <Adafruit_BMP085.h>  //BMP-180 Pressure
#include <XBee.h> //XBee

/* Global Variables */
schema G_packet;
//schema_health G_health;
int count;

/* Initialize objects */
void setup()
{
  /* Variable Initialization */
  count = 0;

  /* Create XBee Object */
  XBee xbee = XBee();

  /* Initialization */
  init1(); //initialize sensors
  Serial.begin(9600);
  xbee.begin(Serial);
  //Serial.println("Main"); //debug main
  // initHealthSamples();
}

/* Health Check */
void loop() {

  /* Packet Initialization */
  Clear_Packet();
  Construct_Packet();
  Transmit_Packet();

  /* Delay for configuration settings */
  delay(500);

  /*//Check health & run appropriate routine
    if(chkHealth() == NORMAL || chkHealth() == GOOD_SOLAR){

      // Voltages are at a good level to operate normally
      Normal_Routine(&count);
    }
    else{

      // Voltages are not at a good level, operate in PowerSave
      PowerSave_Routine();
    }*/
}

/* Team: Team Quasar */
/* transmit.h */

/* Program Libraries */
#include "schema.h"
#include "config.h"
#include "sensors.h"
#include "util.h"

#define MAX_SIZE 80

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>

/* Check for previous includes */
#ifndef TRANSMIT_H
#define TRANSMIT_H

/* Global Variables */
extern schema_296_full G_packet;

/* Clear Packet */
void Clear_Packet(void);

/* Construct Packet */
void Construct_Packet(void);

/* Transmission Code */
void Transmit_Packet(void);

/* XBee Sleep */
void XbeeSleep(void);

#endif

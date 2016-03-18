/* Team: Team Quasar */
/* transmit.h */

/* Program Libraries */
#include "schema.h"
#include "config.h"
#include "sensors.h"
#include "util.h"

#define MAX_SIZE 100

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>

/* Check for previous includes */
#ifndef TRANSMIT_H
#define TRANSMIT_H

/* Global Variable for Packet */
extern schema G_packet;

/* Clear Packet */
void Clear_Packet(void);

/* Construct Packet */
void Construct_Packet(void);

/* Transmission Code */
void Transmit_Packet(void);

#endif

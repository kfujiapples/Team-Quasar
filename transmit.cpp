/* Team: Team Quasar */
/* transmit.h */

/* Program Libraries */
#include "transmit.h"
#include "util.h"

/* External Libraries */
#include <EEPROM.h>
#include <XBee.h>

/* Clear Packet */
void Clear_Packet(void)
{
    //Set how much to fill packet
    int i, b, c;

    //Initialize packet values
    G_packet.address = (EEPROM.read(3) << 8); //EEPROM address
    G_packet.uptime = 0;
    G_packet.n = 0;
    G_packet.pressure = 0;
    G_packet.temp = 0;
    G_packet.humidity = 0;
    
    //Serial.println("clear packet variable initialization");

    //clear packet
    for(i = 1; i < 60; i++)
    {
        //set index
        b = i/10;
        c = i/3;

        //poll 10 times
        //G_packet.batt[b] = 0;
        //G_packet.panel[b] = 0;

        //poll 3 times
        G_packet.irradiance[c] = 0;
    }

    //Serial.println("clear packet bottom");
}

/* Construct Packet */
void Construct_Packet(void)
{
    //Serial.println("construct packet top");

  //Variable for Index
  int n = G_packet.n;

  //Variable Sensor Readings
  //long Battery = 0;
  long SolarIrr = 0;
  long Humidity = 0;
  long Panel = 0;
  long Pressure = 0;
  long Temp = 0;
  unsigned long uptime;

  //Sensor Samples

  //Update data
  uptime = millis();
  
  //Overflow
//G_packet.overflow_num = packet.overflow_num + chk_overflow(uptime, packet.uptime_ms);

  //Save uptime
  G_packet.uptime = uptime;

  //Sensor data
  //G_packet.batt[n/10] = Battery;
  //G_packet.panel[n/10] = Panel;
  G_packet.pressure = pressure();
  G_packet.temp = temp();
  G_packet.humidity = humidity();
  G_packet.irradiance[n/3] = irradiance();
  
  //Serial.println("construct packet sensor data set");
    
  /* Increment index */
  n += 1;
}

/* Transmission Code */
void Transmit_Packet(void)
{
    /* Create Xbee object */
    XBee xbee = XBee();

    /* Variable length */
    int len = 0;

    /* Obtain address of receiving end */
    XBeeAddress64 addr64 = XBeeAddress64(0x0, 0x0);
    ZBTxStatusResponse txStatus = ZBTxStatusResponse();
    
    /* Packet to be transmitted */
    uint8_t payload[MAX_SIZE];

    /* Clear the payload */
    memset(payload, '\0', sizeof(payload));

    /* Obtain length of the packet */
    len = sizeof(G_packet);

    /* Debug packet length */
    Serial.println(F("BIN Length is: "));
    Serial.print(len);

    /* Transfer information into payload */
    memcpy(payload, &G_packet, len);

    /* Checks to see if the data was transferred correctly */
    /* Can check any data value in struct schema defined in schema.h */
    //Serial.println(((schema)payload)->batt[1]);

    /* Transfer the payload */
    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);
    xbee.send(zbTx); //!!Prints packet to serial monitor

    /* Debug payload */
    if (txStatus.getDeliveryStatus() == SUCCESS)
    {
      // success time to celebrate
      Serial.print("yes");
      Serial.println("Received Data:");
    }
}

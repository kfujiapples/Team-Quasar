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
    G_packet.schema = 0;
    G_packet.address = (EEPROM.read(3) << 8); //EEPROM address
    G_packet.uptime_ms = 0;
    //G_packet.n = 0;
    G_packet.bmp185_press_pa = 0;
    G_packet.bmp185_temp_decic = 0;
    G_packet.humidity_centi_pct = 0;
    
    //Serial.println("clear packet variable initialization");

    //clear packet
    for(i = 1; i < 60; i++)
    {
        //set index
        b = i/10;
        c = i/3;

        //poll 10 times
        G_packet.batt_mv[b] = 0;
        G_packet.panel_mv[b] = 0;

        //poll 3 times
        G_packet.solar_irr_w_m2[c] = 0;
    }

    //Serial.println("clear packet bottom");
}

/* Construct Packet */
void Construct_Packet(void)
{
  //Serial.println("construct packet top");

  //Variable for Index and uptime
  unsigned long uptime_ms;

  //Put schema number in packet
  G_packet.schema = 297;

  //Update data
  uptime_ms = millis();

  //Put uptime in packet
  G_packet.uptime_ms = uptime_ms;

  //Poll and put battery and panel data in packet
  for(int p = 0; p < 6; p++)
  { G_packet.batt_mv[p] = battery();
    G_packet.panel_mv[p] = panel();
    delay(400);
  }
  
  //Poll and put panel data in packet
  /*for(int p = 0; p < 6; p++)
  { G_packet.panel_mv[p] = panel();
    delay(400);
  }*/
  
  G_packet.bmp185_press_pa = pressure();
  G_packet.bmp185_temp_decic = temp();
  G_packet.humidity_centi_pct = humidity();

  //Poll and put irradiance data in packet
  for(int i = 0; i < 20; i++)
  { G_packet.solar_irr_w_m2[i] = irradiance();
    delay(300);
  }
  
  /*//Hardcoded Test Packet
  G_packet.uptime_ms = 1;
  for(int p = 0; p <= 4; p++)
  { G_packet.batt_mv[p] = 1;
    Serial.print("Battery");
    Serial.println(G_packet.batt_mv[p]);
    delay(400);
  }
  for(int p = 0; p <= 4; p++)
  { G_packet.panel_mv[p] = 2;
    Serial.print("Panel");
    Serial.println(G_packet.panel_mv[p]);
    delay(400);
  }
  
  G_packet.bmp185_press_pa = 3;
  Serial.print("Pressure");
  Serial.println(G_packet.bmp185_press_pa);
  G_packet.bmp185_temp_decic = 4;
  Serial.print("Temp");
  Serial.println(G_packet.bmp185_temp_decic);
  G_packet.humidity_centi_pct = 5;
  Serial.print("Humidity");
  Serial.println(G_packet.humidity_centi_pct);
  for(int i = 0; i <= 14; i++)
  { G_packet.solar_irr_w_m2[i] = 6;
    Serial.print("Solar");
    Serial.println(G_packet.solar_irr_w_m2[i]);
    delay(1000);
  }*/
}

/* Transmission Code */
void Transmit_Packet(void)
{   
    /* Create Xbee object */
    XBee xbee = XBee();

    /* Packet to be transmitted */
    uint8_t payload[MAX_SIZE];

    /* Obtain address of receiving end */
    XBeeAddress64 addr64 = XBeeAddress64(0x0, 0x0);
    ZBTxStatusResponse txStatus = ZBTxStatusResponse();

    /* Clear the payload */
    memset(payload, '\0', sizeof(payload));

    /* Debug Packet */
    //payload[0] = '1';
    //payload[1] = '5';

    /* Transfer information into payload */
    memcpy(payload, &G_packet, sizeof(payload));

    for(int i = 0; i < MAX_SIZE; i++)
    { Serial.write(payload[i]);}

    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, sizeof(payload));
  
    /* Transfer the payload */
    xbee.send(zbTx); //!!Prints packet to serial monitor

    /* delay */
    delay(1000);
}

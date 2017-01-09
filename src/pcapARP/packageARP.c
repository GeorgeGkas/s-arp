/**
 * The s-arp project v0.5 - An ARP spoofing tool for your LAN.
 * Copyright (C) 2017  George G. Gkasdrogkas
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact with the author at <georgegkas@gmail.com>.
 *
 */
#include "pcapARP.h"

void packageARP(unsigned char *buffer, etherHeader *frameHeader, arpIPv4packet *ARPData, size_t *ARPBufferLength) {
  unsigned char *cp;
  size_t packet_size;

  cp = buffer;

  packet_size = sizeof(frameHeader->destMAC) 
                + sizeof(frameHeader->srcMAC)  
                + sizeof(frameHeader->type)
                + sizeof(ARPData->htype)       
                + sizeof(ARPData->ptype)    
                + sizeof(ARPData->hlen)        
                + sizeof(ARPData->plen)       
                + sizeof(ARPData->op)        
                + sizeof(ARPData->sha)        
                + sizeof(ARPData->spa)         
                + sizeof(ARPData->tha)        
                + sizeof(ARPData->tpa);
  /*
   *  Copy the Ethernet frame header to the buffer.
   */
  memcpy(cp, &(frameHeader->destMAC), sizeof(frameHeader->destMAC));
  cp += sizeof(frameHeader->destMAC);

  memcpy(cp, &(frameHeader->srcMAC), sizeof(frameHeader->srcMAC));
  cp += sizeof(frameHeader->srcMAC);

  /* Normal Ethernet-II framing */
  memcpy(cp, &(frameHeader->type), sizeof(frameHeader->type));
  cp += sizeof(frameHeader->type);


  /*
   *  Add the ARP data.
   */
  memcpy(cp, &(ARPData->htype), sizeof(ARPData->htype));
  cp += sizeof(ARPData->htype);

  memcpy(cp, &(ARPData->ptype), sizeof(ARPData->ptype));
  cp += sizeof(ARPData->ptype);

  memcpy(cp, &(ARPData->hlen), sizeof(ARPData->hlen));
  cp += sizeof(ARPData->hlen);

  memcpy(cp, &(ARPData->plen), sizeof(ARPData->plen));
  cp += sizeof(ARPData->plen);

  memcpy(cp, &(ARPData->op), sizeof(ARPData->op));
  cp += sizeof(ARPData->op);

  memcpy(cp, &(ARPData->sha), sizeof(ARPData->sha));
  cp += sizeof(ARPData->sha);

  memcpy(cp, &(ARPData->spa), sizeof(ARPData->spa));
  cp += sizeof(ARPData->spa);

  memcpy(cp, &(ARPData->tha), sizeof(ARPData->tha));
  cp += sizeof(ARPData->tha);
  
  memcpy(cp, &(ARPData->tpa), sizeof(ARPData->tpa));
  cp += sizeof(ARPData->tpa);

  *ARPBufferLength = packet_size;
}
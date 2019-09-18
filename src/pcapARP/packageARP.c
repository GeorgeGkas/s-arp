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

#include "pcapARP.h"

void unpackageARP(const unsigned char *buffer, size_t bufferSize, etherHeader *frameHeader, arpIPv4packet *ARPData, unsigned char *extraData, size_t *extraDataLength, int *vlanID) {
  const unsigned char *cp;

  cp = buffer;
  /*
   *  Extract the Ethernet frame header data
   */
  memcpy(&(frameHeader->destMAC), cp, sizeof(frameHeader->destMAC));
  cp += sizeof(frameHeader->destMAC);
  memcpy(&(frameHeader->srcMAC), cp, sizeof(frameHeader->srcMAC));
  cp += sizeof(frameHeader->srcMAC);
  /*
   *  Check for 802.1Q VLAN tagging, indicated by a type code of
   *  0x8100 (TPID).
   */
  if (*cp == 0x81 && *(cp + 1) == 0x00) {
    uint16_t tci;
    cp += 2;  /* Skip TPID */
    memcpy(&tci, cp, sizeof(tci));
    cp += 2;  /* Skip TCI */
    *vlanID = ntohs(tci);
    *vlanID &= 0x0fff; /* Mask off PRI and CFI */
  } else {
    *vlanID = -1;
  }
  memcpy(&(frameHeader->type), cp, sizeof(frameHeader->type));
  cp += sizeof(frameHeader->type);
  /*
   *  Check for an LLC header with SNAP. If this is present, the 802.2 LLC
   *  header will contain DSAP=0xAA, SSAP=0xAA, Control=0x03.
   *  If this 802.2 LLC header is present, skip it and the SNAP header
   */
  if (*cp == 0xAA && *(cp + 1) == 0xAA && *(cp + 2) == 0x03) {
    cp += 8;  /* Skip eight bytes */
  }
  /*
   *  Extract the ARP packet data
   */
  memcpy(&(ARPData->htype), cp, sizeof(ARPData->htype));
  cp += sizeof(ARPData->htype);
  memcpy(&(ARPData->ptype), cp, sizeof(ARPData->ptype));
  cp += sizeof(ARPData->ptype);
  memcpy(&(ARPData->hlen), cp, sizeof(ARPData->hlen));
  cp += sizeof(ARPData->hlen);
  memcpy(&(ARPData->plen), cp, sizeof(ARPData->plen));
  cp += sizeof(ARPData->plen);
  memcpy(&(ARPData->op), cp, sizeof(ARPData->op));
  cp += sizeof(ARPData->op);
  memcpy(&(ARPData->sha), cp, sizeof(ARPData->sha));
  cp += sizeof(ARPData->sha);
  memcpy(&(ARPData->spa), cp, sizeof(ARPData->spa));
  cp += sizeof(ARPData->spa);
  memcpy(&(ARPData->tha), cp, sizeof(ARPData->tha));
  cp += sizeof(ARPData->tha);
  memcpy(&(ARPData->tpa), cp, sizeof(ARPData->tpa));
  cp += sizeof(ARPData->tpa);

  if (extraData != NULL) {
    int length;

    length = bufferSize - (cp - buffer);
    if (length > 0) {   /* Extra data after ARP packet */
      memcpy(extraData, cp, length);
    }
    *extraDataLength = length;
  }
}

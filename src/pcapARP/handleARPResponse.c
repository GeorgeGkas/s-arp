#include "pcapARP.h"

void handleARPResponse(
  u_char *args, 
  const struct pcap_pkthdr *header, 
  const u_char *devicesListHead
) {
  int n = header->caplen;
  if (n < ETHER_HEADER_SIZE + ARP_PACKET_SIZE) {
    /**
     * Byte packet too short to decode.
     */
    return;
  }

  arpIPv4packet ARPData;
  etherHeader frameHeader;
  netDevices *currentDevice;
  unsigned char extraData[MAX_FRAME];
  size_t extraDataLength;
  int vlanID;

  unpackageARP(devicesListHead, n, &frameHeader, &ARPData, extraData, &extraDataLength, &vlanID);

  currentDevice = findDeviceByAddress((netDevices *)args, ARPData.spa);
  if (currentDevice) {
    currentDevice->isLive = true;
    memcpy(&(currentDevice->MAC), &(ARPData.sha), ETH_ALEN);
  }
  
  return;
}

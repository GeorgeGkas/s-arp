#include "pcapARPHandler.h"

void pcapSetARPHandlerFilter(const unsigned char *MAC, const bpf_u_int32 subnetMask) {
  struct bpf_program filter;
  char *filterStr;
  filterStr = makeMessage("ether dst %.2x:%.2x:%.2x:%.2x:%.2x:%.2x and "
                          "(arp or (ether[14:4]=0xaaaa0300 and "
                          "ether[20:2]=0x0806) or (ether[12:2]=0x8100 "
                          "and ether[16:2]=0x0806) or "
                          "(ether[12:2]=0x8100 and "
                          "ether[18:4]=0xaaaa0300 and "
                          "ether[24:2]=0x0806))",
                          MAC[0], MAC[1], MAC[2], MAC[3], MAC[4], MAC[5]);

  if ((pcap_compile(pcapARPHandler, &filter, filterStr, OPTIMISE, subnetMask)) < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_ARP_COMPILE);
  }
  if ((pcap_setfilter(pcapARPHandler, &filter)) < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_ARP_SET_FILTER);
  }
}

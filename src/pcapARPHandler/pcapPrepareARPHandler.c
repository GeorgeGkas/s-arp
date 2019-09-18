#include "pcapARPHandler.h"

void pcapPrepareARPHandler(const char *deviceName) {
  char errorBuffer[PCAP_ERRBUF_SIZE];

  if (!(pcapARPHandler = pcap_create(deviceName, errorBuffer))) {
    throwErrorScreen(errorBuffer, PCAP_ARP_HANDLER_CREATE);
  }
  if ((pcap_set_snaplen(pcapARPHandler, SNAPLEN)) < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_ARP_HANDLER_SET_SNAPLEN);
  }
  if ((pcap_set_promisc(pcapARPHandler, PROMISC)) < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_ARP_HANDLER_SET_PROMISC);
  }
  if ((pcap_set_timeout(pcapARPHandler, TO_MS)) < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_ARP_HANDLER_SET_TIMEOUT);
  }
  if ((pcap_activate(pcapARPHandler)) < 0) {
    throwErrorScreen(pcap_geterr(pcapARPHandler), PCAP_ARP_HANDLER_ACTIVATE);
  }
}

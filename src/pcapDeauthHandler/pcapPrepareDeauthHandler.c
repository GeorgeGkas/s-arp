#include "pcapDeauthHandler.h"

void pcapPrepareDeauthHandler(const char *deviceName) {
  char errorBuffer[PCAP_ERRBUF_SIZE];

  if (!(pcapDeauthHandler = pcap_create(deviceName, errorBuffer))) {
    throwErrorScreen(errorBuffer, PCAP_DEAUTH_HANDLER_CREATE);
  }
  if ((pcap_set_snaplen(pcapDeauthHandler, SNAPLEN)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_SNAPLEN);
  }
  if ((pcap_set_promisc(pcapDeauthHandler, PROMISC)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_PROMISC);
  }
  if ((pcap_set_timeout(pcapDeauthHandler, TO_MS)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_TIMEOUT);
  }
  if (!pcap_can_set_rfmon(pcapDeauthHandler)) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_TIMEOUT);
  }
  if ((pcap_activate(pcapDeauthHandler)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_ACTIVATE);
  }
}

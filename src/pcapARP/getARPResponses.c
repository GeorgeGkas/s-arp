#include "pcapARP.h"


void getARPResponses(netDevices **devicesListHead) {
  alarm(ARP_ALARM_TIMEOUT);
  signal(SIGALRM, pcapAlarmARPHandler);
  pcap_loop(pcapARPHandler, 0, handleARPResponse, (u_char*)*devicesListHead);
}

#include "pcapARPHandler.h"

void pcapAlarmARPHandler() {
  pcap_breakloop(pcapARPHandler);
}

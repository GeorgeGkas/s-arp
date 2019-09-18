#include "pcapARPHandler.h"

void pcapCloseARPHandler() {
  pcap_close(pcapARPHandler);
}

#ifndef pcapARPHandler_H
#define pcapARPHandler_H

#include <pcap.h>
#include "../TUI/TUI.h"
#include "../utils/error.h"
 #include "../utils/utils.h"

#define SNAPLEN 64
#define PROMISC 1
#define TO_MS 100
#define OPTIMISE 1

pcap_t *pcapARPHandler;

void pcapPrepareARPHandler(const char *deviceName);
void pcapSetARPHandlerFilter(const unsigned char *MAC, const bpf_u_int32 subnetMask);
void pcapAlarmARPHandler();
void pcapCloseARPHandler();

#endif

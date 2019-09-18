#ifndef pcapDeauthHandler_H
#define pcapDeauthHandler_H

#define SNAPLEN 64
#define PROMISC 1
#define TO_MS 100
#define OPTIMISE 1

#include <pcap.h>
#include "../TUI/TUI.h"
#include "../utils/error.h"

pcap_t *pcapDeauthHandler;

void pcapPrepareDeauthHandler(const char *deviceName);
void pcapCloseDeauthHandler();

#endif

#ifndef wirelessInterfaceMonitor_H
#define wirelessInterfaceMonitor_H

#include <errno.h>
#include <net/if.h>
#include "../TUI/TUI.h"
#include "../utils/error.h"
#define ETH_ALEN 6

typedef struct {
  char deviceName[IFNAMSIZ]; /* Wireless interface name for monitor mode. */
  unsigned char MAC[ETH_ALEN]; /* Wireless interface MAC address for monitor mode.. */
} wirelessInterfaceMonitor;

void addWIMonitor(wirelessInterfaceMonitor *WIMonitor, const char *deviceName, const unsigned char *MAC);
void registerWIMonitor(const char *deviceName);
void delWIMonitor(wirelessInterfaceMonitor *WIMonitor);

#endif

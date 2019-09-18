#ifndef wirelessInterfaceMonitor_H
#define wirelessInterfaceMonitor_H

#include <errno.h>
#include <net/if.h>
#include "../TUI/TUI.h"
#include "../utils/error.h"
#define ETH_ALEN 6

typedef struct {
  /**
   * Wireless interface name for monitor mode.
   */
  char deviceName[IFNAMSIZ];

  /**
   * Wireless interface MAC address for monitor mode.
   */
  unsigned char MAC[ETH_ALEN];
} wirelessInterfaceMonitor;

void addWIMonitor(
  wirelessInterfaceMonitor *WIMonitor, 
  const char *deviceName, 
  const unsigned char *MAC
);
void registerWIMonitor(const char *deviceName);
void delWIMonitor(wirelessInterfaceMonitor *WIMonitor);

#endif

#include "wirelessInterfaceMonitor.h"

void addWIMonitor(
  wirelessInterfaceMonitor *WIMonitor, 
  const char *deviceName, 
  const unsigned char *MAC
) {
	registerWIMonitor(deviceName);
	strcpy(WIMonitor->deviceName, deviceName);
	memcpy(WIMonitor->MAC, MAC, ETH_ALEN);
}

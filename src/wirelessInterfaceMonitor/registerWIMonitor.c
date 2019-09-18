#include "wirelessInterfaceMonitor.h"

void registerWIMonitor(const char *deviceName) {
	char cmd [1000] = {0x0};
	FILE *fp;
	sprintf(cmd, "iw phy phy0 interface add %s type monitor", deviceName);
	fp = popen(cmd, "w");
	if (fp == NULL) {
		throwErrorScreen(strerror(errno), REGISTERWIMONITOR);
	}

	sprintf(cmd, "ip link set up dev %s", deviceName);
	fp = popen(cmd, "w");
	if (fp == NULL) {
		throwErrorScreen(strerror(errno), REGISTERWIMONITOR_IPLINKUP);
	}

	pclose(fp);
}

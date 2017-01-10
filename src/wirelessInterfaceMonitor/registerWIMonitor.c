#include "wirelessInterfaceMonitor.h"

void registerWIMonitor(const char *deviceName) {
	char cmd [1000] = {0x0};
	sprintf(cmd, "iw phy phy0 interface add %s type monitor", deviceName);
	FILE* fp = popen(cmd, "w");
	if (fp == NULL) {
		throwErrorScreen(strerror(errno), REGISTERWIMONITOR);
	}
	pclose(fp);
}
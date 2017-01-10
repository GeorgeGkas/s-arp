#include "wirelessInterfaceMonitor.h"

void delWIMonitor(wirelessInterfaceMonitor *WIMonitor) {
	char cmd [1000] = {0x0};
	sprintf(cmd, "iw  %s del", WIMonitor->deviceName);
	FILE* fp = popen(cmd, "w");
	if (fp == NULL) {
		throwErrorScreen(strerror(errno), REGISTERWIMONITOR);
	}
	pclose(fp);
}
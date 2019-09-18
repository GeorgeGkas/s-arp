#ifndef pcapARPSpoof_H
#define pcapARPSpoof_H

#include "../pcapARP/pcapARP.h"

void spoofTargetDevice(netDevices **targetDevice, wirelessInterface *WI);
void unspoofTargetDevice(netDevices **targetDevice, netDevices **routerDevice);
void handleARPSpoof(netDevices **devicesListHead, wirelessInterface *WI, int choice);
#endif


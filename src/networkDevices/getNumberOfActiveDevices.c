#include "networkDevices.h"

void getNumberOfActiveDevices(int *numberOfActiveDevices, netDevices **devicesListHead) {
  netDevices *currentDevice;
  *numberOfActiveDevices = 0;
  for (
    currentDevice = *devicesListHead;
    currentDevice != NULL;
    currentDevice = currentDevice->next
  ) {
    if (currentDevice->isLive) {
      ++(*numberOfActiveDevices);
    }
  }
}

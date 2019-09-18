#include "networkDevices.h"

netDevices *findDeviceBySerialNumber(netDevices **devicesListHead, const int SerialNumber) {
  netDevices *currentDevice;
  int i = 0;
  for (
    currentDevice = *devicesListHead;
    currentDevice != NULL;
    currentDevice = currentDevice->next
  ) {
    if (currentDevice->isLive) {
      if (i < SerialNumber) {
        ++i;
      } else {
        return currentDevice;
      }
    }
  }
}

#include "networkDevices.h"

netDevices *findDeviceByAddress(netDevices *devicesListHead, const bpf_u_int32 testingAddress) {
  netDevices *currentDevice;
  for (
    currentDevice = devicesListHead;
    currentDevice != NULL;
    currentDevice = currentDevice->next
  ) {
    if (currentDevice->address == testingAddress) {
      return currentDevice;
    }
  }

  return NULL;
}

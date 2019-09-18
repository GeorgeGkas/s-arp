#include "networkDevices.h"

void clearDevicesList(netDevices **devicesListHead) {
  netDevices *currentDevice;
  for (
    currentDevice = *devicesListHead;
    currentDevice->next != NULL;
    currentDevice = currentDevice->next
  ) {
    currentDevice = (*devicesListHead)->next;
    free(*devicesListHead);
    *devicesListHead = currentDevice;
  }
  
  (*devicesListHead)->next = NULL;
}

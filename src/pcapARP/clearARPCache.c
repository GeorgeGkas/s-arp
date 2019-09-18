#include "pcapARP.h"

void clearARPCache(netDevices **devicesListHead) {
  netDevices *currentDevice;
  for (
    currentDevice = (*devicesListHead); 
    currentDevice != NULL; 
    currentDevice = currentDevice->next
  ) {
    if (currentDevice->type != HOST) {
      currentDevice->isLive = false;
      currentDevice->state = NORMAL;
    }
  }
}

#include "pcapARP.h"

void startARPRequests(netDevices **devicesListHead, wirelessInterface *WI) {
  netDevices *currentDevice;
  for (currentDevice = *devicesListHead; currentDevice != NULL; currentDevice = currentDevice->next) {
    if (currentDevice->address != WI->localAddress) {
      sendARPRequest(&currentDevice, &WI);
    }
  }
}

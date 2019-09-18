#include "pcapARPSpoof.h"

void handleARPSpoof(netDevices **devicesListHead, wirelessInterface *WI, int choice) {
  int deviceSerialNumber = choice - '0';
  netDevices *targetDevice;
  
  targetDevice = findDeviceBySerialNumber(devicesListHead, deviceSerialNumber);
  if (targetDevice->type == CLIENT) {
    if (targetDevice->state == NORMAL) {
      spoofTargetDevice(&targetDevice, WI);
    } else {
      netDevices *routerDevice;
      routerDevice = findDeviceByAddress(*devicesListHead, WI->gatewayAddress);
      unspoofTargetDevice(&targetDevice, &routerDevice);
    }
  }
}

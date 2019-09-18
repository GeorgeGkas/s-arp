#include "networkDevices.h"


void generateDevicesList(netDevices **devicesListHead, const wirelessInterface *WI) {
  bpf_u_int32 x = WI->subnetMask;

  /**
   * Get the CIDR Prefix.
   */
  int numbits;
  for (numbits = 0; x != 0; x >>= 1) {
    if (x & 0x01) {
      numbits++;
    }
  }

  /**
   * Determine maximum and minimum host values.
   * Exclude the host and the broadcast.
   */
  unsigned long addressBegin;
  unsigned long addressEnd;
  addressBegin = 1;
  addressEnd = (1 << (32 - numbits)) - 1;

  /**
   * Mask off the network.
   */ 
  bpf_u_int32 networkAddress = htonl(WI->localAddressRange & WI->subnetMask);

  /**
   * Calculate all devices addresses in the range.
   */
  for (unsigned i = addressBegin; i < addressEnd; i++) {
    bpf_u_int32 rawIPv4;
    int b1, b2, b3, b4;
    char strIPv4[16];

    rawIPv4 = networkAddress + i;
    b1 = (rawIPv4 & 0xff000000) >> 24;
    b2 = (rawIPv4 & 0x00ff0000) >> 16;
    b3 = (rawIPv4 & 0x0000ff00) >> 8;
    b4 = (rawIPv4 & 0x000000ff);

    snprintf(strIPv4, sizeof(strIPv4), "%d.%d.%d.%d", b1, b2, b3, b4);

    char errorBuffer[ERR_BUFF_SIZE];
    int errorCode = addDevice(&devicesListHead, strIPv4, &WI, errorBuffer);
    if (errorCode == -1) {
      throwErrorScreen(errorBuffer, ADDDEVICE);
    }
  }
}

#include "wirelessInterface.h"

void getWI(wirelessInterface *WI) {
  char deviceName[IFNAMSIZ];
  char errorBuffer[PCAP_ERRBUF_SIZE];

  bpf_u_int32 localAddressRange = 0;
  bpf_u_int32 localAddress = 0;
  bpf_u_int32 gatewayAddress = 0;
  bpf_u_int32 subnetMask = 0;
  unsigned char MAC[ETH_ALEN];

  int errorCode;

  if (findAppropriateWI(deviceName, errorBuffer) == -1) {
    throwErrorScreen(errorBuffer, FINDAPPROPRIATEDEVICE);
  }

  if (deviceName == NULL) {
    throwErrorScreen(errorBuffer, DEVICENAMENULL);
  } else {
    errorCode = pcap_lookupnet(deviceName, &localAddressRange, &subnetMask, errorBuffer);
    if (errorCode == -1) {
      throwErrorScreen(errorBuffer, PCAPLOOKUPNET);
    }

    errorCode = getWILocalAddress(deviceName, &localAddress, errorBuffer);
    if (errorCode == -1) {
      throwErrorScreen(errorBuffer, GETWILOCALADDRESS);
    }

    errorCode = getWIGatewayAddress(deviceName, &gatewayAddress, errorBuffer);
    if (errorCode == -1) {
      throwErrorScreen(errorBuffer, GETWIGATEWAY);
    }

    errorCode = getWIMACAddress(deviceName, MAC, errorBuffer);
    if (errorCode == -1) {
      throwErrorScreen(errorBuffer, GETWIMAC);
    } else if (isEmptyMACAddress(MAC)) {
      sprintf(errorBuffer, "Could not obtain MAC address for interface %s", deviceName);
      throwErrorScreen(errorBuffer, EMPTYMAC);
    }

    addWI(&WI, deviceName, &localAddressRange, &localAddress, &gatewayAddress, &subnetMask, MAC);
  }
}

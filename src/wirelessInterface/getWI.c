/**
 * The s-arp project v0.5 - An ARP spoofing tool for your LAN.
 * Copyright (C) 2017  George G. Gkasdrogkas
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Contact with the author at <georgegkas@gmail.com>.
 *
 */
#include "wirelessInterface.h"

void getWI(wirelessInterface *WI) {
  char *deviceName;
  char errorBuffer[PCAP_ERRBUF_SIZE];

  bpf_u_int32 localAddressRange = 0;
  bpf_u_int32 localAddress = 0;
  bpf_u_int32 gatewayAddress = 0;
  bpf_u_int32 subnetMask = 0;
  unsigned char MAC[ETH_ALEN];

  int errorCode;

  deviceName = pcap_lookupdev(errorBuffer);

  if (deviceName == NULL) {
    throwErrorScreen(errorBuffer, PCAPLOOKUPDEV);
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
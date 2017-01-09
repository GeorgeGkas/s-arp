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
#include "networkDevices.h"


void generateDevicesList(netDevices **devicesListHead, const wirelessInterface *WI) {
  bpf_u_int32 x = WI->subnetMask;
  int numbits; /* Get the CIDR Prefix. */
  for (numbits = 0; x != 0; x >>= 1) {
    if (x & 0x01) {
      numbits++;
    }
  }

  /**
   * Determine maximum and minimum host values.
   * we exclude the host and the broadcast.
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
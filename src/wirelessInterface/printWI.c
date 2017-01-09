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

void printWI(wirelessInterface *WI) {
  struct in_addr address;
  printw("WI Name: %s\n", WI->deviceName);
  address.s_addr = WI->localAddressRange;
  printw("WI IP range: %s\n", inet_ntoa(address));
  address.s_addr = WI->subnetMask;
  printw("WI Subnet Mask: %s\n", inet_ntoa(address));
  address.s_addr = WI->localAddress;
  printw("Local Address: %s\n", inet_ntoa(address));
  address.s_addr = WI->gatewayAddress;
  printw("Gateway Address: %s\n", inet_ntoa(address));
  printw("WI Mac Address: ");
  for (int i = 0; i < ETH_ALEN; ++i) {
    printw("%02X", WI->MAC[i]);
  }
  printw("\n");
  for (int i = 1; i <= 60; ++i) printw("-");
  printw("\n");
  refresh();
  getch();
}
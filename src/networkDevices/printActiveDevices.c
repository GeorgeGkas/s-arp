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

void printActiveDevices(netDevices **devicesListHead) {
  netDevices *currentDevice = NULL;
  int j = 0;

  printw("%-4s\t%-16s  %-17s\t%-10s\t%-10s\n\n", "S/N", "IPv4", "MAC", "TYPE", "STATE");

  for (currentDevice = *devicesListHead; currentDevice != NULL; currentDevice = currentDevice->next) {
    if (currentDevice->isLive) {
      struct in_addr addr;
      addr.s_addr = currentDevice->address;
      printw("[%d]\t%-16s  ", j, inet_ntoa(addr));

      printw("%02X:%02X:%02X:%02X:%02X:%02X", currentDevice->MAC[0], currentDevice->MAC[1], currentDevice->MAC[2], currentDevice->MAC[3], currentDevice->MAC[4], currentDevice->MAC[5]);

      printw("\t%-10s", ((currentDevice->type == ROUTER) ? "ROUTER" : (currentDevice->type == HOST) ? "HOST" : "CLIENT") );
      printw("\t%-10s", currentDevice->state == NORMAL ? "" : "SPOOFED");
      printw("\n");
      ++j;
    }
  }
}
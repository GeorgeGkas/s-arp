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


int addDevice(netDevices ***devicesListHead, const char *strIPv4, const wirelessInterface **WI, char *errorBuffer) {
  struct in_addr addr;
  unsigned char null_mac[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

  int result;
  result = inet_pton(AF_INET, strIPv4, &addr);
  if (result == 0) {
    strcpy(errorBuffer, "String does not contain a valid network address.");
    return -1;
  } else if (result == -1) {
    strcpy(errorBuffer, strerror(errno));
    return -1;
  }

  if (*devicesListHead == NULL) {
    *devicesListHead = malloc(sizeof(netDevices));
    memcpy(&((**devicesListHead)->address), &addr, sizeof(struct in_addr));
    (**devicesListHead)->state = NORMAL;

    if (addr.s_addr == (*WI)->localAddress) {
      (**devicesListHead)->isLive = true;
      (**devicesListHead)->type = HOST;
      memcpy(&((**devicesListHead)->MAC), (*WI)->MAC, ETH_ALEN);
    } else if (addr.s_addr == (*WI)->gatewayAddress) {
      (**devicesListHead)->isLive = false;
      (**devicesListHead)->type = ROUTER;
      memcpy(&((**devicesListHead)->MAC), null_mac, ETH_ALEN);
    } else {
      (**devicesListHead)->isLive = false;
      (**devicesListHead)->type = CLIENT;
      memcpy(&((**devicesListHead)->MAC), null_mac, ETH_ALEN);
    }
  } else {
    netDevices *newDevice;
    newDevice = malloc(sizeof(netDevices));

    memcpy(&(newDevice->address), &addr, sizeof(struct in_addr));
    newDevice->state = NORMAL;

    if (addr.s_addr == (*WI)->localAddress) {
      newDevice->isLive = true;
      newDevice->type = HOST;
      memcpy(&((newDevice)->MAC), (*WI)->MAC, ETH_ALEN);
    } else if (addr.s_addr == (*WI)->gatewayAddress) {
      newDevice->isLive = false;
      newDevice->type = ROUTER;
      memcpy(&((newDevice)->MAC), null_mac, ETH_ALEN);
    } else {
      newDevice->isLive = false;
      newDevice->type = CLIENT;
      memcpy(&((newDevice)->MAC), null_mac, ETH_ALEN);
    }

    newDevice->next = **devicesListHead;
    **devicesListHead = newDevice;
  }
}
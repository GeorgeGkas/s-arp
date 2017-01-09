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
#ifndef networkDevices_H
#define networkDevices_H

#include "../wirelessInterface/wirelessInterface.h"
#include <stdbool.h>

typedef enum {     
  ROUTER, /* Device is a router. */
  HOST,  /* Device is host. (in other words this is our computer) */
  CLIENT  /* Device is a client who is connected to our network. */
} deviceType;

typedef enum {
  NORMAL, /* Device can trasmit and get packets to and from the router. */
  SPOOFED /* Device contains a wrong-spoofed router MAC address. It doesn't accept packets now. */
} deviceState;

typedef struct netDevicesList {
  bpf_u_int32 address;   /* Device IP address. */
  unsigned char MAC[ETH_ALEN]; /* Device MAC address.*/
  bool isLive; /* Is the address associated with a real device?  */
  deviceType type;
  deviceState state;
  struct netDevicesList *next; /* Next device in the list. */
} netDevices;


void generateDevicesList(netDevices **devicesListHead, const wirelessInterface *WI);
int addDevice(netDevices ***devicesListHead, const char *strIPv4, const wirelessInterface **WI, char *errorBuffer);
void printActiveDevices(netDevices **devicesListHead);
void clearDevicesList(netDevices **devicesListHead);
netDevices *findDeviceByAddress(netDevices *devicesListHead, const bpf_u_int32 testingAddress);
void getNumberOfActiveDevices(int *numberOfActive, netDevices **devicesListHead);
netDevices *findDeviceBySerialNumber(netDevices **devicesListHead, const int SerialNumber);
int isChoiceInActiveDevices(int ch, int numberOfActiveDevices);
void printActiveDevices(netDevices **devicesListHead);

#endif
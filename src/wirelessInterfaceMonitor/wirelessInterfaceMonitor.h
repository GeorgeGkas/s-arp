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
#ifndef wirelessInterfaceMonitor_H
#define wirelessInterfaceMonitor_H

#include <errno.h>
#include <net/if.h>
#include "../TUI/TUI.h"
#include "../utils/error.h"
#define ETH_ALEN 6

typedef struct {
  char deviceName[IFNAMSIZ]; /* Wireless interface name for monitor mode. */
  unsigned char MAC[ETH_ALEN]; /* Wireless interface MAC address for monitor mode.. */
} wirelessInterfaceMonitor;

void addWIMonitor(wirelessInterfaceMonitor *WIMonitor, const char *deviceName, const unsigned char *MAC);
void registerWIMonitor(const char *deviceName);
void delWIMonitor(wirelessInterfaceMonitor *WIMonitor);

#endif
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
#include "pcapHandler.h"

void pcapPrepareHandler(const char *deviceName) {
  char errorBuffer[PCAP_ERRBUF_SIZE];

  if (!(pcapHandler = pcap_create(deviceName, errorBuffer))) {
    throwErrorScreen(errorBuffer, PCAP_HANDLER_CREATE);
  }
  if ((pcap_set_snaplen(pcapHandler, SNAPLEN)) < 0) {
    throwErrorScreen(pcap_geterr(pcapHandler), PCAP_HANDLER_SET_SNAPLEN);
  }
  if ((pcap_set_promisc(pcapHandler, PROMISC)) < 0) {
    throwErrorScreen(pcap_geterr(pcapHandler), PCAP_HANDLER_SET_PROMISC);
  }
  if ((pcap_set_timeout(pcapHandler, TO_MS)) < 0) {
    throwErrorScreen(pcap_geterr(pcapHandler), PCAP_HANDLER_SET_TIMEOUT);
  }
  if ((pcap_activate(pcapHandler)) < 0) {
    throwErrorScreen(pcap_geterr(pcapHandler), PCAP_HANDLER_ACTIVATE);
  }
}
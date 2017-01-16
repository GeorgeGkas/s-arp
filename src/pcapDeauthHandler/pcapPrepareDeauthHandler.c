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
#include "pcapDeauthHandler.h"

void pcapPrepareDeauthHandler(const char *deviceName) {
  char errorBuffer[PCAP_ERRBUF_SIZE];

  if (!(pcapDeauthHandler = pcap_create(deviceName, errorBuffer))) {
    throwErrorScreen(errorBuffer, PCAP_DEAUTH_HANDLER_CREATE);
  }
  if ((pcap_set_snaplen(pcapDeauthHandler, SNAPLEN)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_SNAPLEN);
  }
  if ((pcap_set_promisc(pcapDeauthHandler, PROMISC)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_PROMISC);
  }
  if ((pcap_set_timeout(pcapDeauthHandler, TO_MS)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_TIMEOUT);
  }
  if (!pcap_can_set_rfmon(pcapDeauthHandler)) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_SET_TIMEOUT);
  }
  if ((pcap_activate(pcapDeauthHandler)) < 0) {
    throwErrorScreen(pcap_geterr(pcapDeauthHandler), PCAP_DEAUTH_HANDLER_ACTIVATE);
  }
}
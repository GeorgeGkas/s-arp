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

void pcapSetHandlerARPFilter(const unsigned char *MAC, const bpf_u_int32 subnetMask) {
  struct bpf_program filter;
  char *filterStr;
  filterStr = makeMessage("ether dst %.2x:%.2x:%.2x:%.2x:%.2x:%.2x and "
                          "(arp or (ether[14:4]=0xaaaa0300 and "
                          "ether[20:2]=0x0806) or (ether[12:2]=0x8100 "
                          "and ether[16:2]=0x0806) or "
                          "(ether[12:2]=0x8100 and "
                          "ether[18:4]=0xaaaa0300 and "
                          "ether[24:2]=0x0806))",
                          MAC[0], MAC[1], MAC[2], MAC[3], MAC[4], MAC[5]);

  if ((pcap_compile(pcapHandler, &filter, filterStr, OPTIMISE, subnetMask)) < 0) {
    throwErrorScreen(pcap_geterr(pcapHandler), PCAP_COMPILE);
  }
  if ((pcap_setfilter(pcapHandler, &filter)) < 0) {
    throwErrorScreen(pcap_geterr(pcapHandler), PCAP_SET_FILTER);
  }
}
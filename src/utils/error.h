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
#ifndef ERROR_H
#define ERROR_H

#define ERR_BUFF_SIZE 256

#define DEVICENAMENULL 1
#define PCAPLOOKUPNET 2
#define GETWILOCALADDRESS 3
#define GETWIGATEWAY 4
#define GETWIMAC 5
#define EMPTYMAC 6
#define ADDDEVICE 7

#define PCAP_ARP_HANDLER_CREATE 8
#define PCAP_ARP_HANDLER_SET_SNAPLEN 9
#define PCAP_ARP_HANDLER_SET_PROMISC 10
#define PCAP_ARP_HANDLER_SET_TIMEOUT 11
#define PCAP_ARP_HANDLER_ACTIVATE 12

#define PCAP_ARP_COMPILE 13
#define PCAP_ARP_SET_FILTER 14

#define PCAP_SEND_ARP_REQUEST 15
#define PCAP_SEND_SPOOFED_ARP_RESPONSE 16
#define PCAP_SEND_UNSPOOFED_ARP_RESPONSE 17

#define PCAP_DEAUTH_HANDLER_CREATE 18
#define PCAP_DEAUTH_HANDLER_SET_SNAPLEN 19
#define PCAP_DEAUTH_HANDLER_SET_PROMISC 20
#define PCAP_DEAUTH_HANDLER_SET_TIMEOUT 21
#define PCAP_DEAUTH_HANDLER_ACTIVATE 22

#define REGISTERWIMONITOR 23

#define FINDAPPROPRIATEDEVICE 24

#define REGISTERWIMONITOR_IPLINKUP 25

#endif
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
#ifndef pcapARP_H
#define pcapARP_H

#include "../pcapARPHandler/pcapARPHandler.h"
#include "../networkDevices/networkDevices.h"

#include <signal.h>

#define ARP_ALARM_TIMEOUT 2 /* In how much time do we have to stop listen for arp responses.*/

#define ARP_ETHER_PACKET 0x0806 /* Address Resolution packet. */
#define DEFAULT_ETHER_PRO ARP_ETHER_PACKET /* Default Ethernet protocol. */
#define MAX_FRAME 2048  /* Maximum allowed frame size. */

#define ARP_ETHER_HTYPE 1  /* Ethernet ARP type. */
#define DEFAULT_ARP_HTYPE ARP_ETHER_HTYPE /* Default ARP hardware type. */

#define ARP_IPv4_PTYPE 0x0800 /* Internet Protocol packet. */
#define DEFAULT_ARP_PTYPE ARP_IPv4_PTYPE /* Default ARP protocol. */

#define DEFAULT_ARP_HLEN 6 /* Default hardware length. */
#define DEFAULT_ARP_PLEN 4 /* Default protocol length. */

#define ARP_OP_REQUEST 1 /* ARP Request. */
#define ARP_OP_RESPONSE 2 /* ARP Reply. */
#define DEFAULT_ARP_OP ARP_OP_REQUEST /* Default ARP operation. */

#define ETHER_HEADER_SIZE 14   /* Size of Ethernet frame header in bytes. */
#define ARP_PACKET_SIZE 28 /* Size of ARP Packet in bytes. */

/**
 * Ethernet frame header 
 */
typedef struct {
   uint8_t destMAC[ETH_ALEN]; /* Destination hardware address. */
   uint8_t srcMAC[ETH_ALEN];  /* Source hardware address. */
   uint16_t type;   /* Ethernet frame type. */
} etherHeader;

/**
 * Ethernet ARP packet from RFC 826. 
 */
typedef struct {
   uint16_t htype;   /* Format of hardware address. */
   uint16_t ptype;   /* Format of protocol address. */
   uint8_t hlen;    /* Length of hardware address. */
   uint8_t plen;    /* Length of protocol address. */
   uint16_t op;    /* ARP opcode. */
   uint8_t sha[ETH_ALEN];  /* Sender hardware address. */
   uint32_t spa;   /* Sender IP address. */
   uint8_t tha[ETH_ALEN];  /* Target hardware address. */
   uint32_t tpa;   /* Target IP address. */
} __attribute__((packed)) arpIPv4packet;


void startARPRequests(netDevices **devicesListHead, wirelessInterface *WI);
void sendARPRequest(netDevices **currentDevice, wirelessInterface **WI);
void packageARP(unsigned char *buffer, etherHeader *frameHeader, arpIPv4packet *ARPData, size_t *ARPBufferLength);
void unpackageARP(const unsigned char *buffer, size_t bufferSize, etherHeader *frameHeader, arpIPv4packet *ARPData, unsigned char *extraData, size_t *extraDataLength, int *vlanID);
void handleARPResponse(u_char *args, const struct pcap_pkthdr *header, const u_char *devicesListHead);
void getARPResponses(netDevices **devicesListHead);
void clearARPCache(netDevices **devicesListHead);

#endif
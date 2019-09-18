#ifndef pcapARP_H
#define pcapARP_H

#include "../pcapARPHandler/pcapARPHandler.h"
#include "../networkDevices/networkDevices.h"

#include <signal.h>

/**
 * In how much time do we have to stop listen for arp responses.
 */
#define ARP_ALARM_TIMEOUT 2

/**
 * Address Resolution packet.
 */
#define ARP_ETHER_PACKET 0x0806

/**
 * Default Ethernet protocol.
 */
#define DEFAULT_ETHER_PRO ARP_ETHER_PACKET

/**
 * Maximum allowed frame size.
 */
#define MAX_FRAME 2048

/**
 * Ethernet ARP type.
 */
#define ARP_ETHER_HTYPE 1

/**
 * Default ARP hardware type.
 */
#define DEFAULT_ARP_HTYPE ARP_ETHER_HTYPE

/**
 * Internet Protocol packet.
 */
#define ARP_IPv4_PTYPE 0x0800

/**
 * Default ARP protocol.
 */
#define DEFAULT_ARP_PTYPE ARP_IPv4_PTYPE

/**
 * Default hardware length. 
 */
#define DEFAULT_ARP_HLEN 6

/**
 * Default protocol length.
 */
#define DEFAULT_ARP_PLEN 4

/**
 * ARP Request.
 */
#define ARP_OP_REQUEST 1

/**
 * ARP Reply.
 */
#define ARP_OP_RESPONSE 2

/**
 * Default ARP operation.
 */
#define DEFAULT_ARP_OP ARP_OP_REQUEST

/**
 * Size of Ethernet frame header in bytes. 
 */
#define ETHER_HEADER_SIZE 14

/**
 * Size of ARP Packet in bytes.
 */
#define ARP_PACKET_SIZE 28

/**
 * Ethernet frame header.
 */
typedef struct {
  /**
   * Destination hardware address.
   */
  uint8_t destMAC[ETH_ALEN];

  /**
   * Source hardware address.
   */
  uint8_t srcMAC[ETH_ALEN];

  /**
   * Ethernet frame type.
   */
  uint16_t type;
} etherHeader;

/**
 * Ethernet ARP packet from RFC 826. 
 */
typedef struct {
  /** 
   * Format of hardware address.
   */
   uint16_t htype;

   /**
    * Format of protocol address.
    */
   uint16_t ptype;

   /**
    * Length of hardware address.
    */
   uint8_t hlen;

   /** 
    * Length of protocol address.
    */
   uint8_t plen;

   /**
    * ARP opcode.
    */
   uint16_t op;

   /**
    * Sender hardware address.
    */
   uint8_t sha[ETH_ALEN];

   /**
    * Sender IP address.
    */
   uint32_t spa;

   /**
    * Target hardware address.
    */
   uint8_t tha[ETH_ALEN];

   /**
    * Target IP address.
    */
   uint32_t tpa;
} __attribute__((packed)) arpIPv4packet;


void startARPRequests(netDevices **devicesListHead, wirelessInterface *WI);
void sendARPRequest(netDevices **currentDevice, wirelessInterface **WI);
void packageARP(
  unsigned char *buffer, 
  etherHeader *frameHeader, 
  arpIPv4packet *ARPData, 
  size_t *ARPBufferLength
);
void unpackageARP(
  const unsigned char *buffer, 
  size_t bufferSize, 
  etherHeader *frameHeader, 
  arpIPv4packet *ARPData, 
  unsigned char *extraData, 
  size_t *extraDataLength, 
  int *vlanID
);
void handleARPResponse(
  u_char *args, 
  const struct pcap_pkthdr *header, 
  const u_char *devicesListHead
);
void getARPResponses(netDevices **devicesListHead);
void clearARPCache(netDevices **devicesListHead);

#endif

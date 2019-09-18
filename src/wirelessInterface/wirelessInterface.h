#ifndef wirelessInterface_H
#define wirelessInterface_H

#include <pcap.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <sys/socket.h>
#include <linux/wireless.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "../TUI/TUI.h"
#include "../utils/error.h"
#include "../utils/utils.h"

#define ETH_ALEN 6

/**
 * Structure that holds informations associated
 * with our wireless interface card as well as
 * others that correspond to our LAN configurations.
 */
typedef struct {
  char deviceName[IFNAMSIZ]; /* Wireless interface name. */
  bpf_u_int32 localAddressRange; /* IETF IP Protocol Assignment range as described in RFC 6890. */
  bpf_u_int32 localAddress; /* Our computer IPv4 address. */
  bpf_u_int32 gatewayAddress; /* Gateway IPv4 address. */
  bpf_u_int32 subnetMask; /* Our subnet mask. */
  unsigned char MAC[ETH_ALEN]; /* Wireless interface MAC address. */
} wirelessInterface;

typedef struct {
  int fd;    /* Socket file descriptor. */
  struct ifreq ifr;
  struct sockaddr_ll sll;
} link_t;


void getWI(wirelessInterface *WI);
int getWILocalAddress(const char *deviceName, bpf_u_int32 *localAddress, char *errorBuffer);
int getWIGatewayAddress(const char *deviceName, bpf_u_int32 *gatewayAddress, char *errorBuffer);
int getWIMACAddress(const char *deviceName, unsigned char *MAC, char *errorBuffer);
int isEmptyMACAddress(const unsigned char *MAC);
void addWI(wirelessInterface **WI, const char *deviceName, const bpf_u_int32 *localAddressRange, const bpf_u_int32 *localAddress, const bpf_u_int32 *gatewayAddress, const bpf_u_int32 *subnetMask, const unsigned char *MAC);
void printWI(wirelessInterface *WI);
int findAppropriateWI(char *deviceName, char *errorBuffer);

#endif

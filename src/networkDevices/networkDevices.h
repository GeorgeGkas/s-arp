#ifndef networkDevices_H
#define networkDevices_H

#include "../wirelessInterface/wirelessInterface.h"
#include <stdbool.h>

typedef enum {   
  /**
   * Device is a router.
   */  
  ROUTER,

  /**
   * Device is host. (in other words this is our computer)
   */
  HOST,

  /**
   * Device is a client who is connected to our network.
   */
  CLIENT
} deviceType;

typedef enum {
  /**
   * Device can transmit and get packets to and from the router.
   */
  NORMAL,

  /**
   * Device contains a wrong-spoofed router MAC address. It doesn't accept packets now.
   */
  SPOOFED
} deviceState;

typedef struct netDevicesList {
  /**
   * Device IP address.
   */
  bpf_u_int32 address;

  /**
   * Device MAC address.
   */
  unsigned char MAC[ETH_ALEN];

  /**
   * Is the address associated with a real device?
   */
  bool isLive;
  deviceType type;
  deviceState state;

  /**
   * Next device in the list.
   */
  struct netDevicesList *next;
} netDevices;


void generateDevicesList(netDevices **devicesListHead, const wirelessInterface *WI);
int addDevice(
  netDevices ***devicesListHead, 
  const char *strIPv4, 
  const wirelessInterface **WI, 
  char *errorBuffer
);
void printActiveDevices(netDevices **devicesListHead);
void clearDevicesList(netDevices **devicesListHead);
netDevices *findDeviceByAddress(netDevices *devicesListHead, const bpf_u_int32 testingAddress);
void getNumberOfActiveDevices(int *numberOfActive, netDevices **devicesListHead);
netDevices *findDeviceBySerialNumber(netDevices **devicesListHead, const int SerialNumber);
int isChoiceInActiveDevices(int ch, int numberOfActiveDevices);
void printActiveDevices(netDevices **devicesListHead);

#endif

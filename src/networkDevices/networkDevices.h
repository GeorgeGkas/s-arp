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

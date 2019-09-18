#include "wirelessInterface.h"

void printWI(wirelessInterface *WI) {
  struct in_addr address;
  printw("WI Name: %s\n", WI->deviceName);
  address.s_addr = WI->localAddressRange;
  printw("WI IP range: %s\n", inet_ntoa(address));
  address.s_addr = WI->subnetMask;
  printw("WI Subnet Mask: %s\n", inet_ntoa(address));
  address.s_addr = WI->localAddress;
  printw("Local Address: %s\n", inet_ntoa(address));
  address.s_addr = WI->gatewayAddress;
  printw("Gateway Address: %s\n", inet_ntoa(address));
  printw("WI Mac Address: ");
  for (int i = 0; i < ETH_ALEN; ++i) {
    printw("%02X", WI->MAC[i]);
  }
  printw("\n");
  for (int i = 1; i <= 60; ++i) printw("-");
  printw("\n");
  refresh();
  getch();
}

#include "networkDevices.h"

void printActiveDevices(netDevices **devicesListHead) {
  netDevices *currentDevice = NULL;
  int j = 0;

  printw("%-4s\t%-16s  %-17s\t%-10s\t%-10s\n\n", "S/N", "IPv4", "MAC", "TYPE", "STATE");

  for (
    currentDevice = *devicesListHead;
    currentDevice != NULL;
    currentDevice = currentDevice->next
  ) {
    if (currentDevice->isLive) {
      struct in_addr addr;
      addr.s_addr = currentDevice->address;
      printw("[%d]\t%-16s  ", j, inet_ntoa(addr));

      printw(
        "%02X:%02X:%02X:%02X:%02X:%02X",
        currentDevice->MAC[0],
        currentDevice->MAC[1],
        currentDevice->MAC[2],
        currentDevice->MAC[3],
        currentDevice->MAC[4],
        currentDevice->MAC[5]
      );

      printw(
        "\t%-10s",
        (
          (currentDevice->type == ROUTER) 
          ? "ROUTER" 
          : (currentDevice->type == HOST) 
          ? "HOST" 
          : "CLIENT"
        )
      );
      
      printw("\t%-10s", currentDevice->state == NORMAL ? "" : "SPOOFED");
      printw("\n");
      ++j;
    }
  }
}

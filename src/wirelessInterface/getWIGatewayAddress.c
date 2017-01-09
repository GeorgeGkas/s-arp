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
#include "wirelessInterface.h"

int getWIGatewayAddress(const char *deviceName, bpf_u_int32 *gatewayAddress, char *errorBuffer) {
  char gateway[256];
  memset(gateway, '\0', sizeof(gateway));

  char cmd [1000] = {0x0};
  sprintf(cmd, "route -n | grep %s  | grep 'UG[ \t]' | awk '{print $2}'", deviceName);
  FILE* fp = popen(cmd, "r");
  char line[256] = {0x0};

  if (fgets(line, sizeof(line), fp) != NULL) {
    strncpy(gateway, line, strlen(line) - 1);
  }
  pclose(fp);

  struct in_addr addr;
  int result;
  result = inet_pton(AF_INET, gateway, &addr);

  if (result < 0) {
    strcpy(errorBuffer, "inet_pton failed.");
    return -1;
  } else if (result == 0) {
    strcpy(errorBuffer, "not a valid IPv4 address - target ignored");
    return -1;
  } else {
    *gatewayAddress =  addr.s_addr;
  }
}
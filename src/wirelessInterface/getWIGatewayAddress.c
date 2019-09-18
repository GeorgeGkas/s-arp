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

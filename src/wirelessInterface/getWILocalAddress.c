#include "wirelessInterface.h"

int getWILocalAddress(const char *deviceName, bpf_u_int32 *localAddress, char *errorBuffer) {
  link_t handle;

  handle.fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (handle.fd < 0) {
    strcpy(errorBuffer, strerror(errno));
    return -1;
  }

  handle.ifr.ifr_addr.sa_family = AF_INET;
  strncpy(handle.ifr.ifr_name, deviceName, IFNAMSIZ - 1);
  if (ioctl(handle.fd, SIOCGIFADDR, &handle.ifr) != 0) {
    strcpy(errorBuffer, strerror(errno));
    return -1;
  }
  close(handle.fd);

  *localAddress = ((struct sockaddr_in *)&handle.ifr.ifr_addr)->sin_addr.s_addr;
}

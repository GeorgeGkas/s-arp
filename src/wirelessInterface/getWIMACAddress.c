#include "wirelessInterface.h"

/**
 * Open the specified wireless device.
 */
static link_t *link_open(const char *deviceName) {
  link_t *handle;

  handle = malloc(sizeof(*handle));
  memset(handle, '\0', sizeof(*handle));
  if ((handle->fd = socket(PF_PACKET, SOCK_RAW, 0)) < 0) {
    return NULL;
  }
  strlcpy(handle->ifr.ifr_name, deviceName, sizeof(handle->ifr.ifr_name));
  if ((ioctl(handle->fd, SIOCGIFINDEX, &(handle->ifr))) != 0) {
    return NULL;
  }
  handle->sll.sll_family = PF_PACKET;
  handle->sll.sll_ifindex = handle->ifr.ifr_ifindex;
  handle->sll.sll_halen = ETH_ALEN;

  return handle;
}

/**
 * Close the link.
 */
static void link_close(link_t *handle) {
  if (handle != NULL) {
    if (handle->fd != 0) {
      close(handle->fd);
    }
    free(handle);
  }
}

int getWIMACAddress(const char *deviceName, unsigned char *MAC, char *errorBuffer) {
  link_t *handle;

  handle = link_open(deviceName);
  if (handle == NULL) {
    strcpy(errorBuffer, strerror(errno));
    return -1;
  }

  /**
   * Obtain hardware address for specified interface.
   */
  if ((ioctl(handle->fd, SIOCGIFHWADDR, &(handle->ifr))) != 0) {
    strcpy(errorBuffer, strerror(errno));
    return -1;
  }

  link_close(handle);

  memcpy(MAC, handle->ifr.ifr_ifru.ifru_hwaddr.sa_data, ETH_ALEN);
}

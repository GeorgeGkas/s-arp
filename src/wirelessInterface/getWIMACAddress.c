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

// open the spessified wireless device
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

// Close the link
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
   * Obtain hardware address for specified interface 
   */
  if ((ioctl(handle->fd, SIOCGIFHWADDR, &(handle->ifr))) != 0) {
    strcpy(errorBuffer, strerror(errno));
    return -1;
  }

  link_close(handle);

  memcpy(MAC, handle->ifr.ifr_ifru.ifru_hwaddr.sa_data, ETH_ALEN);
}
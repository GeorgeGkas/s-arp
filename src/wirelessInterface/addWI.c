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

void addWI(wirelessInterface **WI, const char *deviceName, const bpf_u_int32 *localAddressRange, const bpf_u_int32 *localAddress, const bpf_u_int32 *gatewayAddress, const bpf_u_int32 *subnetMask, const unsigned char *MAC) {
    strcpy((*WI)->deviceName, deviceName);
    memcpy(&((*WI)->localAddressRange), localAddressRange, sizeof(bpf_u_int32));
    memcpy(&((*WI)->localAddress), localAddress, sizeof(bpf_u_int32));
    memcpy(&((*WI)->gatewayAddress), gatewayAddress, sizeof(bpf_u_int32));
    memcpy(&((*WI)->subnetMask), subnetMask, sizeof(bpf_u_int32));
    memcpy((*WI)->MAC, MAC, ETH_ALEN);
}
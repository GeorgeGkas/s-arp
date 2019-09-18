#include "wirelessInterface.h"

void addWI(wirelessInterface **WI, const char *deviceName, const bpf_u_int32 *localAddressRange, const bpf_u_int32 *localAddress, const bpf_u_int32 *gatewayAddress, const bpf_u_int32 *subnetMask, const unsigned char *MAC) {
    strcpy((*WI)->deviceName, deviceName);
    memcpy(&((*WI)->localAddressRange), localAddressRange, sizeof(bpf_u_int32));
    memcpy(&((*WI)->localAddress), localAddress, sizeof(bpf_u_int32));
    memcpy(&((*WI)->gatewayAddress), gatewayAddress, sizeof(bpf_u_int32));
    memcpy(&((*WI)->subnetMask), subnetMask, sizeof(bpf_u_int32));
    memcpy((*WI)->MAC, MAC, ETH_ALEN);
}

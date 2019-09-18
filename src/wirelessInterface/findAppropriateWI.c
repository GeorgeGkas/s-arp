#include "wirelessInterface.h"

int findAppropriateWI(char *deviceName, char *errorBuffer) {
	pcap_if_t *interfacesList;
	pcap_if_t *interface;
	pcap_addr_t *interface_addr;

	if (pcap_findalldevs(&interfacesList, errorBuffer) == -1) {
		return -1;
	}
	for (interface = interfacesList; interface != NULL; interface = interface->next) {
		for (interface_addr = interface->addresses; interface_addr != NULL; interface_addr = interface_addr->next) {
			if (interface_addr->addr->sa_family == AF_INET && interface_addr->addr && interface_addr->netmask && strcmp(interface->name, "lo") != 0) {
				strcpy(deviceName, interface->name);
			}
		}
	}
}

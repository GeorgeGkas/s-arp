#ifndef ERROR_H
#define ERROR_H

#define ERR_BUFF_SIZE 256

#define DEVICENAMENULL 1
#define PCAPLOOKUPNET 2
#define GETWILOCALADDRESS 3
#define GETWIGATEWAY 4
#define GETWIMAC 5
#define EMPTYMAC 6
#define ADDDEVICE 7

#define PCAP_ARP_HANDLER_CREATE 8
#define PCAP_ARP_HANDLER_SET_SNAPLEN 9
#define PCAP_ARP_HANDLER_SET_PROMISC 10
#define PCAP_ARP_HANDLER_SET_TIMEOUT 11
#define PCAP_ARP_HANDLER_ACTIVATE 12

#define PCAP_ARP_COMPILE 13
#define PCAP_ARP_SET_FILTER 14

#define PCAP_SEND_ARP_REQUEST 15
#define PCAP_SEND_SPOOFED_ARP_RESPONSE 16
#define PCAP_SEND_UNSPOOFED_ARP_RESPONSE 17

#define PCAP_DEAUTH_HANDLER_CREATE 18
#define PCAP_DEAUTH_HANDLER_SET_SNAPLEN 19
#define PCAP_DEAUTH_HANDLER_SET_PROMISC 20
#define PCAP_DEAUTH_HANDLER_SET_TIMEOUT 21
#define PCAP_DEAUTH_HANDLER_ACTIVATE 22

#define REGISTERWIMONITOR 23

#define FINDAPPROPRIATEDEVICE 24

#define REGISTERWIMONITOR_IPLINKUP 25

#endif

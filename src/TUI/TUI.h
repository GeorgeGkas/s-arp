#ifndef TUI_H
#define TUI_H

#include <ncurses.h>
#include <string.h>

#include "TUIutils/TUIutils.h"


#define PROGRAM_NAME "The s-arp project v1.0"
#define COPYRIGHT_HOLDER "(C) 2017 George G. Gkasdrogkas"
#define GNU_GPL_3_l1 "This program comes with ABSOLUTELY NO WARRANTY."
#define GNU_GPL_3_l2 "This is free software, and you are welcome"   
#define GNU_GPL_3_l3 "to redistribute it under certain conditions."   
#define PROGRAM_DESCRIPTION "An ARP spoofing tool for your LAN."

void printWelcomeScreen();
void throwErrorScreen(char *errorMessage, int errorCode);
void drawTimeHeader();
void printARPLoadingScreen();

#endif

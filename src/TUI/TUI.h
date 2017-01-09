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
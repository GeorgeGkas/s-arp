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
#include "TUI.h"

void throwErrorScreen(char *errorMessage, int errorCode) {
  int screenWidth;
  WINDOW *errorScr;
  initCenteralizeScreen(&errorScr, &screenWidth);

  char *Pname = initCenteralizedMessage(PROGRAM_NAME, screenWidth);

  char errorBuffer[256];
  sprintf(errorBuffer, "Error [%d]: %s", errorCode, errorMessage);
  char *centeralizedErrorMessage = initCenteralizedMessage(errorBuffer, screenWidth);
  
  char *returnButton = initCenteralizedMessage("Press any button to exit...", screenWidth);

  wprintw(errorScr, "\n%s\n\n%s\n\n\n%s", Pname, centeralizedErrorMessage, returnButton);
  wrefresh(errorScr);
  drawBorder(errorScr);
  wgetch(errorScr);
  delwin(errorScr);
  endwin();
  exit(-1);
}
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

void printWelcomeScreen() {
  int screenWidth;
  WINDOW *welcomeScr;
  initCenteralizeScreen(&welcomeScr, &screenWidth);

  char *Pname = initCenteralizedMessage(PROGRAM_NAME, screenWidth);
  char *Pcopyright = initCenteralizedMessage(COPYRIGHT_HOLDER, screenWidth);
  char *Plicence1 = initCenteralizedMessage(GNU_GPL_3_l1, screenWidth);
  char *Plicence2 = initCenteralizedMessage(GNU_GPL_3_l2, screenWidth);
  char *Plicence3 = initCenteralizedMessage(GNU_GPL_3_l3, screenWidth);
  char *Pdescription = initCenteralizedMessage(PROGRAM_DESCRIPTION, screenWidth);
  char *nextButton = initCenteralizedMessage("Press ENTER to continue...", screenWidth);

  wprintw(welcomeScr, "\n%s\n%s\n\n%s\n%s\n%s\n%s\n\n\n%s", Pname, Pdescription, Pcopyright, Plicence1, Plicence2, Plicence3, nextButton);
  wrefresh(welcomeScr);
  drawBorder(welcomeScr);

  int ch;
  while (ch = wgetch(welcomeScr)) {
    if (ch == 10) {
      break;
    }
  }
  delwin(welcomeScr);
}
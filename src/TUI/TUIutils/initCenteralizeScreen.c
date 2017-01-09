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
#include "TUIutils.h"

void initCenteralizeScreen(WINDOW **localscr, int *width) {
  int max_x, max_y;
  getmaxyx(stdscr, max_y, max_x);

  *width = (max_x >= 60) ? 60 : max_x;
  int height = 15;
  int start_y = 2;
  int start_x = (max_x / 2) - ((*width) / 2);

  *localscr = newwin(height, (*width), start_y, start_x);
  wrefresh(*localscr);
}
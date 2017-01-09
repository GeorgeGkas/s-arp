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
#ifndef TUIutils_H
#define TUIutils_H

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>

typedef struct {
  time_t currentTime;
  time_t previousTime;
  int elapsedTime; /* currentTime - previousTime */
  char timeUnit[5]; /* "s", "min", "h" */
} ElapsedTime_s;

char *initCenteralizedMessage(char *str, int winWidth);
void initCenteralizeScreen(WINDOW **localscr, int *width);
void drawBorder(WINDOW *localscr);
char *getDateAndTime();
char *getElapsedTime();

#endif
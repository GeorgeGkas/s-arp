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

char *getDateAndTime() {
  char *time_buffer;
  time_buffer = malloc(sizeof(char)*100);
  time_t currentTime;
  time(&currentTime);
  struct tm *time_info;
  time_info = localtime(&currentTime);
  strftime(time_buffer,80,"%Y-%m-%d %H:%M:%S", time_info);
  return time_buffer;
}
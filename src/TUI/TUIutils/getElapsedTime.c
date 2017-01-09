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

ElapsedTime_s ElapsedTime = {0, 0, 0, "s"};

char *getElapsedTime() {
  time(&ElapsedTime.currentTime);

  if (strcmp(ElapsedTime.timeUnit, "s") == 0) {
    if (difftime(ElapsedTime.currentTime, ElapsedTime.previousTime) >= 1.0) {
      if (ElapsedTime.elapsedTime >= 59) {
        ElapsedTime.elapsedTime = 1;
        strcpy(ElapsedTime.timeUnit, "min");
      } else {
        ElapsedTime.elapsedTime++;
      }
      time(&ElapsedTime.previousTime);
    }
  } else if (strcmp(ElapsedTime.timeUnit, "min") == 0) {
    if (difftime(ElapsedTime.currentTime, ElapsedTime.previousTime) >= 60.0) {
      if (ElapsedTime.elapsedTime >= 59) {
        ElapsedTime.elapsedTime = 1;
        strcpy(ElapsedTime.timeUnit, "h");
      } else {
        ElapsedTime.elapsedTime++;
      }
      time(&ElapsedTime.previousTime);
    }
  } else if (strcmp(ElapsedTime.timeUnit, "h") == 0) {
    if (difftime(ElapsedTime.currentTime, ElapsedTime.previousTime) >= 3600.0) {
      ElapsedTime.elapsedTime++;
      time(&ElapsedTime.previousTime);
    }
  }

  static char buffer[10];
  snprintf(buffer, 10, "%d %s", ElapsedTime.elapsedTime, ElapsedTime.timeUnit);
  return buffer;
}
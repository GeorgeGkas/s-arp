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

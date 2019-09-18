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

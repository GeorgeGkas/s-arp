#include "TUIutils.h"

char *initCenteralizedMessage(char *str, int winWidth) {
  int str_left_padding = winWidth / 2 - strlen(str) / 2 - (winWidth < 60 ? 0 : 1);

  char *str_return;
  str_return = malloc(sizeof(char)*(str_left_padding + strlen(str) + 1));

  int i;
  for (i = 0; i < str_left_padding; ++i) {
    str_return[i] = ' ';
  }
  str_return[i] = '\0';

  strcat(str_return, str);
  return str_return;
}

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

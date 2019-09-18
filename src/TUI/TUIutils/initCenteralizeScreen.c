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

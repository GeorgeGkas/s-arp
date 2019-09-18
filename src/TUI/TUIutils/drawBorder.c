#include "TUIutils.h"

void drawBorder(WINDOW *localscr) {
  box(localscr, 0, 0);
  wrefresh(localscr);
}

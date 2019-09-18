#include "TUI.h"

void drawTimeHeader() {
  printw("[Elapsed %s] [%s]\n\n", getElapsedTime(), getDateAndTime());
}

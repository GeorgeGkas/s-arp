#include "TUI.h"

void printWelcomeScreen() {
  int screenWidth;
  WINDOW *welcomeScr;
  initCenteralizeScreen(&welcomeScr, &screenWidth);

  char *Pname = initCenteralizedMessage(PROGRAM_NAME, screenWidth);
  char *Pcopyright = initCenteralizedMessage(COPYRIGHT_HOLDER, screenWidth);
  char *Plicence1 = initCenteralizedMessage(GNU_GPL_3_l1, screenWidth);
  char *Plicence2 = initCenteralizedMessage(GNU_GPL_3_l2, screenWidth);
  char *Plicence3 = initCenteralizedMessage(GNU_GPL_3_l3, screenWidth);
  char *Pdescription = initCenteralizedMessage(PROGRAM_DESCRIPTION, screenWidth);
  char *nextButton = initCenteralizedMessage("Press ENTER to continue...", screenWidth);

  wprintw(
    welcomeScr,
    "\n%s\n%s\n\n%s\n%s\n%s\n%s\n\n\n%s",
    Pname,
    Pdescription,
    Pcopyright,
    Plicence1,
    Plicence2,
    Plicence3,
    nextButton
  );
  wrefresh(welcomeScr);
  drawBorder(welcomeScr);

  int ch;
  while (ch = wgetch(welcomeScr)) {
    if (ch == 10) {
      break;
    }
  }
  delwin(welcomeScr);
}

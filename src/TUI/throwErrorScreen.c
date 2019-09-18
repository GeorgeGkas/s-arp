#include "TUI.h"

void throwErrorScreen(char *errorMessage, int errorCode) {
  int screenWidth;
  WINDOW *errorScr;
  initCenteralizeScreen(&errorScr, &screenWidth);

  char *Pname = initCenteralizedMessage(PROGRAM_NAME, screenWidth);

  char errorBuffer[256];
  sprintf(errorBuffer, "Error [%d]: %s", errorCode, errorMessage);
  char *centeralizedErrorMessage = initCenteralizedMessage(errorBuffer, screenWidth);

  char *returnButton = initCenteralizedMessage("Press ctrl+c to exit...", screenWidth);

  wprintw(errorScr, "\n%s\n\n%s\n\n\n%s", Pname, centeralizedErrorMessage, returnButton);
  wrefresh(errorScr);
  drawBorder(errorScr);
  while (1); /* infinite loop to force the user press ctrl+c and use the handler in s-arp.c */
}

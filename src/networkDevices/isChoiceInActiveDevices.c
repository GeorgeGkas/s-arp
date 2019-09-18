#include "networkDevices.h"

int isChoiceInActiveDevices(int ch, int numberOfActiveDevices) {
  if (ch - '0' >= 0 && ch - '0' < numberOfActiveDevices) {
    return 1;
  }
  
  return 0;
}

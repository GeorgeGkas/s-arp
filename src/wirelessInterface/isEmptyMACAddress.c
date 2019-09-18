#include "wirelessInterface.h"

int isEmptyMACAddress(const unsigned char *MAC) {
  if (MAC[0] == 0 && MAC[1] == 0 &&
      MAC[2] == 0 && MAC[3] == 0 &&
      MAC[4] == 0 && MAC[5] == 0) {
        return 1;
  }

  return 0;
}

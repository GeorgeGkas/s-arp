#include "utils.h"

#include <stdio.h>
#include <stdarg.h>

/*
 * make_message -- allocate a sufficiently large string and print into it.
 *
 * Inputs:
 *
 * Format and variable number of arguments.
 *
 * Outputs:
 *
 * Pointer to the string,
 *
 * The code for this function is from the Debian Linux "woody" sprintf man
 * page.
 */
char *makeMessage(const char *fmt, ...) {
  int n;
  /* Guess we need no more than 100 bytes. */
  size_t size = 100;
  char *p;
  va_list ap;
  p = malloc(size);
  while (1) {
    /* Try to print in the allocated space. */
    va_start(ap, fmt);
    n = vsnprintf (p, size, fmt, ap);
    va_end(ap);
    /* If that worked, return the string. */
    if (n > -1 && n < (int) size)
      return p;
    /* Else try again with more space. */
    if (n > -1)    /* glibc 2.1 */
      size = n + 1; /* precisely what is needed */
    else           /* glibc 2.0 */
      size *= 2;  /* twice the old size */
    p = realloc(p, size);
  }
}

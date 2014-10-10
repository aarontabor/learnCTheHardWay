#include <stdio.h>
#include <stdlib.h>

/*
 * man pages for atoi and atof state
 *  "converts initial portion of string to number"
 * this was to test what happens to the rest of it
 */


int main () {
  char *s = "123.234asdf123";
  double n = atof(s);

  // rest of string is ignored
  printf("%f\n", n);

  return 0;
}

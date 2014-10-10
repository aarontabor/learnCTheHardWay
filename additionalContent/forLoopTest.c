#include <string.h>
#include <stdio.h>

int main() {

  char *letters = "abcde\n";
  int len = strlen(letters);

  int i = 0;
  for(i=0; i < len; i++) {
    if(letters[i] == '\n') break;

    // i would be incremented here (so it doesn't get incremented the last iteration)
  }

  // so i is 5 (instead of 6)
  printf("%d\n", i);

  return 0;
}

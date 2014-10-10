#include <stdio.h>

int main(int argc, char *argv[]) {
  char *names[] = { "These", "are", "strings"};

  int *name = (int *) names;

  int i = 0;
  for(i = 0; i < 3; i++) {
    printf("%d\n", *(name-i));
  }


  int nums[] = {1, 2, 3, 4};

  char **num = (char **) nums;
  for(i = 0; i < 4; i++) {
    printf ("%s\n", *(num-i));
  }

  return 0;
}

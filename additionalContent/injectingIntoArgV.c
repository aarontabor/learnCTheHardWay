#include <stdio.h>


int main(int argc, char *argv[]) {
  int i;
  argv[2] = "injected!";
  for (i=1; i<argc; i++) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }
}

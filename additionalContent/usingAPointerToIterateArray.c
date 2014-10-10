#include <stdio.h>


int main(int argc, char *argv[]) {
  
  char **element;
  for (element = &argv[1]; element < &argv[argc]; element++) {
    printf("%s\n", *element);
  }

  element = &argv[0];
  while(++element < &argv[argc]) {
    printf("%s\n", *element);
  }

  return 0;
}

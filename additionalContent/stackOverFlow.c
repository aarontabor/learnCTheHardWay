#include <stdio.h>

void incr(int num) {
  printf("%d\n", num);
  incr(num+1);

  return;
}

int main() {
  incr(0);

  return 0;

}

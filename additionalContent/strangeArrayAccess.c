#include <stdio.h>


int main() {
  char phrase[6] = {'p', 'h', 'r', 'a', 's', 'e'};
  char *another = "another";

  printf("phrase[2]: %c\n", phrase[2]);
  printf("2[phrase]: %c\n", 2[phrase]);

  printf("another[2]: %c\n", another[2]); 
  printf("2[another]: %c\n", 2[another]);
  printf("\"another\"[2]: %c\n", "another"[2]); 
  printf("2[\"another\"]: %c\n", 2["another"]);
  return 0;
}

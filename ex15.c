#include <stdio.h>

void printUsingIndexing(char *names[], int ages[], int count) {
  // first way using indexing
  int i = 0;
  for(i = count-1; i >= 0; i--) {
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }

}

void printUsingPointerOffset(char **name, int *age, int count) {
  // second way using pointers
  int i = 0;
  for(i = count-1; i >= 0; i--) {
    printf("%s is %d years old.\n", *(name+i), *(age+i));
  }
}

void printPointersAreJustArrays(char **name, int *age, int count) {
  // third way, pointers are just arrays
  int i = 0;
  for(i = count-1; i >= 0; i--) {
    printf("%s is %d years old again.\n", name[i], age[i]);
  }
}

void printComplexWay(char **name, int *age, int count) {
  // forth way with pointers in a stupid complex way
  char **cur_name;
  int *cur_age;
  for(cur_name = name + count-1, cur_age = age + count-1;
      (cur_age - age) >= 0;
      cur_name--, cur_age--)
  {
    printf("%s lived %d years so far.\n", cur_name[0], cur_age[0]);
  }
}



int main(int argc, char *argv[])
{
  // create two arrays that we care about
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  printUsingIndexing(names, ages, count);
  printf("---\n");

  // setup the pointers to the start of the arrays
  int *cur_age = ages;
  char **cur_name = names;

  printUsingPointerOffset(cur_name, cur_age, count);
  printf("---\n");

  printPointersAreJustArrays(cur_name, cur_age, count);
  printf("---\n");

  printComplexWay(cur_name, cur_age, count);
  printf("---\n");
  
  //print out pointer addresses
  for(i=0; i < count; i++) {
    printf("Address of %s: %p, address of %d: %p\n",
        *(names+i), *(names+i), *(ages+i), ages+i);
  }

  return 0;
}

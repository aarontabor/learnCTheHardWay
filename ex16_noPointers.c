#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person Person_create(char *name, int age, int height, int weight) {
  struct Person who;

  who.name = strdup(name); // this malloc's (heap space)
  who.age = age;
  who.height = height;
  who.weight = weight;

  return who;
}


void Person_destroy(struct Person who) {

  free(who.name);
  // People are just regular variables now (defined in stack space).
}

void Person_print(struct Person who) {
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age); 
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}




int main(int argc, char *argv[]) {

  // create two people
  struct Person frank = Person_create("Frank Blank", 21, 54, 70);
  struct Person bob = Person_create("Bobby Nobby", 43, 60, 32);

  printf("Frank is at memory location %p\n", &frank);
  Person_print(frank);

  printf("Bob is at memory location %p\n", &bob);
  Person_print(bob);

  // make them age by 20 years
  frank.age += 20;
  frank.weight += 15;
  Person_print(frank);

  bob.age += 20;
  bob.height -= 2;
  Person_print(bob);

  // destroy them
  Person_destroy(frank);
  Person_destroy(bob);


  return 0;
}

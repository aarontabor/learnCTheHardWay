#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*
 * stdio -    A library for reading from inputs and writing to outputs (we use printf)
 * assert -   Assertions accept a scaler expression, and cause program to abort when 0. (Abort if failed assertion)
 *            If marcro NDEBUG is defined, assertings will be ignored (be careful if expression contains side effects) 
 *
 * stdlib -   
 * string -   A collection of utility methods for strings (char *).  This includes copying, parsing, concatenating, searching.
 *
 */

//dfeine struct Person
struct Person {
  // with attributes
  char *name;
  int age;
  int height;
  int weight;
};

/*
 * creating a new datatype
 *  each line defines an attribute of the new type
 *
 */

// * acutally belongs to return type ( this function returns a Person *)
struct Person *Person_create(char *name, int age, int height, int weight) {
  // allocating a piece of memory that is the size of a person (malloc returns a pointer to meomry)
  struct Person *who = malloc(sizeof(struct Person));

  // ensure malloc was successful
  assert(who != NULL);

  // set each attribute
  who->name = strdup(name); //duplicate string (as this is a pointer, so we are passing string by REFERENCE)
  who->age = age;
  who->height = height;
  who ->weight = weight;

  // return the newly created person
  return who;
}

// free the memory allocated to the person
void Person_destroy(struct Person *who) {
  assert(who != NULL);

  // free the persons name first (otherwise we would lose reference to it)
  free(who->name);
  free(who);
}

// print out the persons information
void Person_print(struct Person *who) {
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age); // tab character
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  // create two people
  struct Person *frank = Person_create("Frank Blank", 21, 54, 70);
  struct Person *bob = Person_create("Bobby Nobby", 43, 60, 32);

  printf("Frank is at memory location %p\n", frank);
  Person_print(frank);

  printf("Bob is at memory location %p\n", bob);
  Person_print(bob);

  // make them age by 20 years
  frank->age += 20;
  frank->weight += 15;
  Person_print(frank);

  bob->age += 20;
  bob->height -= 2;
  Person_print(bob);

  // destroy them
  Person_destroy(frank);
  Person_destroy(bob);

  return 0;
}




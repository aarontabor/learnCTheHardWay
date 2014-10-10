#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

struct Stack {
  int *top, elements[STACK_SIZE];
};

struct Stack *createStack() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  stack->top = stack->elements;
  return stack;
}

void destroyStack(struct Stack *stack) {
  free(stack);
}

int die(char *errorMessage) {
  printf("ERROR: %s -- Aborting.\n", errorMessage);
  exit(1);
}

void push(struct Stack *stack, int toPush) {
  if (stack->top >= &stack->elements[STACK_SIZE-1]) {
    die("Stack OverFlow.");
  }
  *(++stack->top) = toPush;
}
  
int pop(struct Stack *stack) {
  if (stack->top < stack->elements) {
    die("Stack UnderFlow.");
  }
  return *(stack->top--);
}

int peek(struct Stack *stack) {
  return *stack->top;
}


int main() {
  struct Stack *stack = createStack();
  
  int i;
  for(i=0; i<10; i++) {
    printf("pushing %d...\n", i);
    push(stack, i);
  }

  int popped, peeked;
  for(i=0; i<10; i++) {
    peeked = peek(stack);
    printf("peeked %d...\n", peeked);
    popped = pop(stack);
    printf("popped %d...\n", popped);
  }
  pop(stack);
  pop(stack);

  return 0;
}

#include <stdio.h>

// forces ascii characters [A-Z, a-z] to their lowercase form
char lower(char letter) {
  return (letter | 0x20);
}

int main(int argc, char *argv[]) 
{
  if (argc < 2) {
    printf("Usage: you need at least one argument\n");

    //This is how you abort a program
    return 1;
  }

  int j;
  char *word;

  int i;
  char letter;
  for (j = 0; word = argv[j], j < argc; j++) {
    printf("arg[%d]: %s\n", j, word);

    for (i = 0; letter = word[i], letter != '\0'; i++) {
      letter = lower(letter);

      switch(letter) {
        case 'a':
          // case 'A':
          printf("%d: A\n", i);
          break;

        case 'e':
          // case 'E':
          printf("%d: E\n", i);
          break;

        case 'i':
          // case 'I':
          printf("%d: I\n", i);
          break;

        case 'o':
          // case 'O':
          printf("%d: O\n", i);
          break;

        case 'u':
          // case 'U':
          printf("%d: U\n", i);
          break;

        case 'y':
          // case 'Y':
          if (i > 2) {
            printf("%d: Y\n", i);
          }
          break;

        default:
          printf("%d: %c is not a vowel\n", i, letter);

      }
    }
    puts("");
  }
  return 0;
}




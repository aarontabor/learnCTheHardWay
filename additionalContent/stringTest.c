#include <stdio.h>

int main() {
	char *string1;
	char *string2 = "another";

	*string1 = *string2; // i.e. value @ string1[0] = value @ string2[0]

	printf("string1: %s, string2: %s\n", string1, string2);

	return 0;
}

#include <stdio.h>

int main(int argc, char* argv[])
{
	int areas[] = {10, 12, 13, 14 ,20};
	char name[] = "Aaron";
	char full_name[] = {'A', 'a', 'r', 'o', 'n', ' ', 'T', 'a', 'b', 'o', 'r', '\0'};

	// WARNING: on some systems you may have to change the %ld in this code to %u since it will use unsigned ints
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas: %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
	printf("The tenth area is: %d and the second area is: %d\n", areas[10], areas[1]);

	printf("The size of char: %ld\n", sizeof(char));
	printf("The size of name: %ld\n", sizeof(name));
	printf("The number of chars in name: %ld\n", sizeof(name) / sizeof(char));

	printf("The size of full name: %ld\n", sizeof(full_name));
	printf("The number of chars in full name: %ld\n", sizeof(full_name) / sizeof(char));

	printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

	name[5] = 'w';

	//printf("What, my name is whaaat, my name is shic-a-shic-a-%s-shady.\n", name);
	return 0;
}

#include <stdio.h>
int main()
{
	int age = 10;
	int height = 72;

	printf("I am %d years old\n", age);
	printf("I am %d inches tall\n", height);

	float num = 1234.567;
	int width = 7;
	int precision = 2;

	// %m$	arg to print
	// *m$	arg to substitute
	printf("%3$*1$.*2$f\n", width, precision, num);
	return 0;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.5432;
	char initial = 'W';
	char first_name[] = "Aaron";
	char last_name[] = "Tabor";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super-powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have first name %s.\n", first_name);
	printf("I have last name %s.\n", last_name);
	printf("My full name is %s %c. %s.\n",first_name, initial, last_name);

	return 0;
}

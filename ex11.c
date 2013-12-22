#include <stdio.h>

int printStrings(int numStrings, char *strings[], char *label) {
	int i = 0;
	while (i < numStrings) {
		printf("%s %d: %s\n", label, i, strings[i]);
		i++;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	// go through each string in argv
	
	int i = argc-1;
	
	printStrings(argc, argv, "params");

	//let's make our own array of strings
	
	char *states[] = {
		"California", "Oregon",
		"New York", "Texas"
	};

	int numStates = 4;
	printStrings(numStates, states, "states");

	i = 0;
	while (i < argc) {
		if (i < numStates) {
			states[i] = argv[i];
		}
		i++;
	}

	printStrings(numStates, states, "states");


	return 0;
}


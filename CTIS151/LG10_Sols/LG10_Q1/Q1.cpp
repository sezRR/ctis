#define _CRT_SECURE_NO_WARNINGS

#define MAX 14
#define MIN 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// Declare variables
	int generatedNumber;

	// Generate random value
	srand(time(NULL));
	generatedNumber = rand() % (MAX - MIN + 1) + MIN;

	// Show generated random value
	printf("Randomly generated number is: %d\n", generatedNumber);

	// Generate the pyrdamid
	for (int i = 1; i <= generatedNumber; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
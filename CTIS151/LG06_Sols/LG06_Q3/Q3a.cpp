#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Declare variables
	int seed, numberGuess, generatedNumber;

	// Get inputs from the user
	printf("Enter a seed value to test your program: ");
	scanf("%d", &seed);

	srand(seed);
	generatedNumber = rand() % 10;

	printf("Please guess, the randomly generated number (1-10): ");
	scanf("%d", &numberGuess);

	if (generatedNumber == numberGuess) {
		printf("Congratulations! You have guessed the number correctly :)");
	}
	else {
		printf("You couldn't guess correctly! The number was %d, See you again next time.", generatedNumber);
	}

	return 0;
}
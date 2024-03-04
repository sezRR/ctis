#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// Declare variables
	int numberGuess, generatedNumber;

	srand(time(NULL));
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
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	char lowercaseFormOfAnyLetter, uppercaseFormOfAnyLetter, _;
	int differenceResult;
	
	// Get letters from the user
	printf("Enter the lowercase form of any letter: ");
	scanf("%c", &lowercaseFormOfAnyLetter);

	printf("Enter the UPPERCASE form of any letter: ");
	scanf(" %c", &uppercaseFormOfAnyLetter);

	// Make calculations
	differenceResult = lowercaseFormOfAnyLetter - uppercaseFormOfAnyLetter;

	// Show ASCII codes of letters
	printf("\nASCII code of lowercase form: %d", lowercaseFormOfAnyLetter);
	printf("\nASCII code of UPPERCASE form: %d", uppercaseFormOfAnyLetter);

	// Show the difference between codes
	printf("\n\nDifference bettween the code is: %d", differenceResult);
}
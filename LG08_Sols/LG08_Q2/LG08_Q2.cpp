#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Define variables
	char letterToCount,
		sentenceInput;

	int searchedLetterCounter = 0,
		letterCounter = 0,
		digitCounter = 0;

	// Get inputs from the user
	printf("Enter the letter to count: ");
	scanf("%c", &letterToCount);
	
	printf("Enter characters: ");
	scanf(" %c", &sentenceInput);

	while (sentenceInput != '!' && sentenceInput != '?')
	{
		if (sentenceInput == letterToCount)
			searchedLetterCounter++;

		if (sentenceInput >= 'a' && sentenceInput <= 'z'
			|| sentenceInput >= 'A' && sentenceInput <= 'Z')
			letterCounter++;

		if (sentenceInput >= '0' && sentenceInput <= '9')
			digitCounter++;

		scanf("%c", &sentenceInput);
	}

	printf("\nThe letter <%c> appears %d times.", letterToCount, searchedLetterCounter);
	printf("\n\nThere are %d letters and %d digits in the given sentence", letterCounter, digitCounter);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	FILE *numbersFile = fopen("numbers.txt", "r");
	int productOfNumbers = 1, tempNumber;

	// Check that is file exists
	if (numbersFile == NULL)
		printf("File could not opened.");
	else
	{
		printf("Numbers read from the file are: "); 
		for (int i = 0; i < 10; i++)
		{
			fscanf(numbersFile, "%d", &tempNumber);
			printf("%d ", tempNumber);
			productOfNumbers *= tempNumber;
		}

		printf("\nThe multiplication of these numbers %d", productOfNumbers);
		fclose(numbersFile);
	}

	return 0;
}
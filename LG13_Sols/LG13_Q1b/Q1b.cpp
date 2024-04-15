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
		int status;
		printf("Numbers read from the file are: ");
		status = fscanf(numbersFile, "%d", &tempNumber);

		while (status != EOF)
		{
			printf("%d ", tempNumber);
			productOfNumbers *= tempNumber;

			status = fscanf(numbersFile, "%d", &tempNumber);
		}

		printf("\nThe multiplication of these numbers %d", productOfNumbers);
		fclose(numbersFile);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	FILE *numbersFile = fopen("numbers.txt", "r");
	FILE *evenNumbersFile = fopen("even.txt", "w");
	FILE *oddNumbersFile = fopen("odd.txt", "w");
	int tempNumber;

	// Check that is file exists
	if (numbersFile == NULL)
		printf("File could not opened.");
	else
	{
		int status;
		status = fscanf(numbersFile, "%d", &tempNumber);

		while (status != EOF)
		{
			if (tempNumber % 2 == 0)
				fprintf(evenNumbersFile, "%d ", tempNumber);
			else
				fprintf(oddNumbersFile, "%d ", tempNumber);

			status = fscanf(numbersFile, "%d", &tempNumber);
		}

		fclose(numbersFile);
		fclose(evenNumbersFile);
		fclose(oddNumbersFile);
	}

	return 0;
}
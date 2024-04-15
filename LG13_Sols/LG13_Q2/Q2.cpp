#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

bool isPerfect(int number)
{
	int sumOfDivisors = 0;

	for (int i = 1; i < number ; i++)
	{
		if (number % i == 0)
			sumOfDivisors += i;
	}

	return number == sumOfDivisors;
}

int main(void)
{
	// Declare variables
	FILE *numbersFile = fopen("integers.txt", "r");
	int productOfNumbers = 1, tempNumber;

	// Check that is file exists
	if (numbersFile == NULL)
		printf("File could not opened.");
	else
	{
		int status;
		printf("Perfect numbers are: ");
		status = fscanf(numbersFile, "%d", &tempNumber);

		while (status != EOF)
		{
			if (isPerfect(tempNumber))
			{
				printf("%d ", tempNumber);
			}

			status = fscanf(numbersFile, "%d", &tempNumber);
		}

		fclose(numbersFile);
	}

	return 0;
}
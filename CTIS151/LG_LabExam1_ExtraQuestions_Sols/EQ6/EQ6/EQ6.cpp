#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Define variables
	int rows;

	// Get inputs from the user
	printf("Enter number of rows: ");
	scanf("%d", &rows);

	// Validate rows input
	if (rows <= 0) {
		printf("EXIT!");
		return 1;
	}

	// Show the half-number pyramid
	for (int i = 0; i < rows; i++)
	{
		for (int j = rows; rows - i <= j; j--)
		{
			printf("%d", j);
		}

		printf("\n");
	}

	return 0;
}
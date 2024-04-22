#define _CRT_SECURE_NO_WARNINGS

#define ARR_LENGTH 7

#include <stdio.h>

int main(void)
{
	// Declare variables
	int arr[ARR_LENGTH];
	FILE *valuesFilePtr;

	// Get inputs from the file
	valuesFilePtr = fopen("values.txt", "r");

	if (valuesFilePtr == NULL)
		printf("File could not opened!");
	else 
	{
		printf("Reading contents of the file, the 7 numbers are: ");
		for (int i = 0; i < ARR_LENGTH; i++)
		{
			fscanf(valuesFilePtr, " %d", &arr[i]);
			printf("%d ", arr[i]);
		}

		printf("\nThe array contents are: ");
		for (int i = 0; i < ARR_LENGTH; i++)
			printf("%d ", arr[i]);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LENGTH 100

#include <stdio.h>

void swap(int* number1, int* number2)
{
	int temp = *number2;

	*number2 = *number1;
	*number1 = temp;
}

int main(void)
{
	// Declare the variables
	int arr[MAX_ARR_LENGTH];
	int numberOfElements;

	// Get inputs from the user
	do
	{
		printf("Enter the number of elements: ");
		scanf("%d", &numberOfElements);

		if (numberOfElements % 2 == 1)
			printf("The number of elements should be EVEN.\n\n");
	} while (numberOfElements % 2 == 1);

	printf("\nEnter array elements:\n");
	for (int i = 0; i < numberOfElements; i++)
	{
		printf("Enter element on index [%d]: ", i);
		scanf("%d", &arr[i]);
	}

	// Swap elements
	printf("Array elements after swapping adjacent elements:");
	for (int i = 0; i < numberOfElements; i += 2)
	{
		swap(&arr[i], &arr[i + 1]);
		printf("%d %d ", arr[i], arr[i + 1]);
	}

	return 0;
}
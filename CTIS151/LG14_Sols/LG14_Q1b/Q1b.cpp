#define _CRT_SECURE_NO_WARNINGS

#define ARR_LENGTH 7

#include <stdio.h>

int main(void)
{
	// Declare variables
	int arr[ARR_LENGTH];
	
	// Get inputs from the user
	printf("Enter 7 numbers: ");
	for (int i = 0; i < ARR_LENGTH; i++)
		scanf(" %d", &arr[i]);

	printf("The array contents are: ");
	for (int i = 0; i < ARR_LENGTH; i++)
		printf("%d ", arr[i]);

	return 0;
}
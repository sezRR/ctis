#define _CRT_SECURE_NO_WARNINGS

#define ARR_LENGTH 7

#include <stdio.h>

int main(void)
{
	// Declare variables
	int arr[ARR_LENGTH] = { 78, 43, 1, 12, 90, 34, 55 };

	printf("The array contents are: ");
	for (int i = 0; i < ARR_LENGTH; i++)
		printf("%d ", arr[i]);

	return 0;
}
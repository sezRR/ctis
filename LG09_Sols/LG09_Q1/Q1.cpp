#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	int integerInput, productOfDigits = 1;

	// Get inputs from the user
	printf("Enter a positive integer: ");

	scanf("%d", &integerInput);
	while (integerInput <= 0)
	{
		printf("Invalid Input: Please enter a positive integer number.\n");
		scanf("%d", &integerInput);
	}

	while (integerInput > 1)
	{
		productOfDigits *= integerInput % 10;
		integerInput /= 10;
	}

	printf("Product of digits = %d", productOfDigits);

	return 0;
}
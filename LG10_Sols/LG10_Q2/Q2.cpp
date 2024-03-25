#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	int integerInput, productOfDigits = 1;

	// Get input from the user
	do
	{
		printf("Enter a positive integer (negative number to stop): ");
		scanf("%d", &integerInput);

		// Check integerInput
		if (integerInput > 0)
		{
			// Make calculation
			do
			{
				productOfDigits = productOfDigits * (integerInput % 10);
				integerInput /= 10;
			} while (integerInput > 1);

			printf("Product of digits = %d\n", productOfDigits);
			productOfDigits = 1;
		}
	} while (integerInput >= 0);

	return 0;
}
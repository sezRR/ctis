#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	int y, i, sign = -1, lastElement = 1;
	double result = 0;

	// Get inputs from the user
	do
	{
		printf("Enter the value of y: ");
		scanf("%d", &y);
	} while (y == 0);

	// Make calculation

	for (i = 1; i <= 7; i++)
	{
		lastElement = (2 * i) / y;
		result += sign * lastElement;

		sign *= -1;
	}

	printf("The result is %.2f", result);

	return 0;
}
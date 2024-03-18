#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	int y, i, sign = -1;
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
		result += sign * (2 * i) / powf(y, i);
		sign *= -1;
	}

	printf("The result is %.2f", result);

	return 0;
}
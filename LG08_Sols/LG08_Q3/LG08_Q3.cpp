#define _CRT_SECURE_NO_WARNINGS

#define MAX_POWER_OF_Y 56

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	int i;
	double y, result = 0;

	// Get 'y' from the user
	printf("Enter the value of y: ");
	scanf("%lf", &y);

	// Make calculations
	for (i = 1; i <= MAX_POWER_OF_Y; i++)
	{
		result += pow(y, i) / (2 * i);
	}

	printf("The result is %.2f", result);

	return 0;
}
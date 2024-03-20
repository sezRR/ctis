#define _CRT_SECURE_NO_WARNINGS

#define ITERATION_COUNT 5

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	double xValue, result = 0;

	// Get inputs from the user
	for (int i = 0; i < ITERATION_COUNT; i++)
	{
		printf("Enter %d. x value: ", i);
		scanf("%lf", &xValue);

		if (xValue > 0 && xValue <= 10) {
			result = 3 / sqrtf(powf(xValue, 3) + 1);
		}
		else if (xValue > 10) {
			result = fabs(xValue) + powf(xValue, 5);
		}

		printf("f(%.1f) = %.3f\n\n", xValue, result);
		result = 0;
	}

	return 0;
}
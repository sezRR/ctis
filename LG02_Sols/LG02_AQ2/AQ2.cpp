/* Purpose to find the result of defined operation */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	double result;
	double a = 80.6, b = 8.4, c = 4;

	// Make calculation
	result = ((a + b) / 2) - (b * c);

	// Print the result
	printf("Result = %.2f", result);

	return(0);
}

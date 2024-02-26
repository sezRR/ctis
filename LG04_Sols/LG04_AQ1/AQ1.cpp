#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	int a, b, c, d;
	double result;

	// Get inputs from the user
	printf("Enter the value for a, b, c and d: ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	
	// Make calculation
	result = pow(a, 3) + (powf(sqrt(d), c) / ((-b + sqrtf(pow(b, 2) - 4 * a * c)) / (2 * a)) / ((a * (b - d)) / c));

	// Show the result
	printf("The result of the equation is %f", result);

	return 0;
}
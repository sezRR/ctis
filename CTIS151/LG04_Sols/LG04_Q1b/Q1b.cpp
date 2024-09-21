#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	double t, s, k, b, result;

	// Get inputs from the user
	printf("Enter t and s: ");
	scanf_s("%lf %lf", &t, &s);

	printf("Enter k and b: ");
	scanf_s(" %lf %lf", &k, &b);

	// Make calculation
	result = fabs((sqrt(t * k) + 6 * b) / (b / sqrtf(pow(3, t)) - pow(s, k) / 7 + 4));

	// Show the result
	printf("Result is: %.2f", result);

	return (0);
}
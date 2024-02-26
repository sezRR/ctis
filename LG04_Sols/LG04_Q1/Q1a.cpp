#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	double t = 7.2, s = 3.4, k = 2, b = 19, result; // For 1.a)

	// Get inputs from the user
	printf("Enter t and s: ");
	scanf_s("%lf %lf", &t, &s);

	printf("Enter k and b: ");
	scanf_s(" %lf %lf", &k, &b);

	// Make calculation
	result = fabs((sqrt(t * k) + 6 * b) / (b / sqrtf(pow(3, t)) - pow(s, k) / 7 + 4));

	// Show the result
	printf("Result is: %.3f", result); // For 1.a)

	return (0);
}
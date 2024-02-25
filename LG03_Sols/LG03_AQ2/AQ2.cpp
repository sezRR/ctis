#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	int b = 4, c = 12, e = 9;
	double a = 5.6, d = 5.2, result;

	// Make calculations
	result = fabs(d - c) / (a + (b + (pow(a, 3)) / (2 + (sqrt(sqrt(c)) / (e + (sqrt(b + c) / (c + pow(e, 2) / 5)
	))))));

	// Show the result
	printf("Result is %.4f", result);
}
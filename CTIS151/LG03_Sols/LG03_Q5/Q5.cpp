#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	int x = 2, y = 3, t = 4;
	double z = 4.2, w = 1.8, result;

	// Make calculation
	result = x - (z * (y - w) / t) / (w - (z * t) / w);

	// Display the result
	printf("The result of the equation is %.2f", result);
}
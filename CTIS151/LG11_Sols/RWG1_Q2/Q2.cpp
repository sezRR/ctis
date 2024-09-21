#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	double result = 0;
	int x, sign = 1;

	// Get inputs from the user
	printf("Enter x (other than 0): ");
	scanf("%d", &x);
	
	while (x == 0) {
		printf("Division by zero! Please reenter x: ");
		scanf("%d", &x);
	}

	// Make calculation
	for (int i = 2; i <= 18; i += 2)
	{
		result += sign * i / (pow(x, i * (3 - x)/2));
		sign *= -1;
	}

	// Show the result
	printf("Result: %f", result);

	return 0;
}
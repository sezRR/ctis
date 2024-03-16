#define _CRT_SECURE_NO_WARNINGS

#define COUNT_OF_PROCESS 10

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	int x, 
		i,
		sign = -1;
	double result = 0;

	// Get 'x' from the user
	printf("Enter x (other than 5): ");
	scanf("%d", &x);

	while (x == 5)
	{
		printf("Division by zero! Please reenter x: ");
		scanf("%d", &x);
	}

	// Make calculations
	for (i = 1; i <= COUNT_OF_PROCESS; i++)
	{
		result += sign * 3 * i / pow(x - 5, (1 + 3 * i));
		sign *= -1;
	}

	printf("Result: %.2f", result);

	return 0;
}
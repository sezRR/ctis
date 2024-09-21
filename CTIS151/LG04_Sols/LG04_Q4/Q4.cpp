#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	double firstNumber, secondNumber;
	bool result;

	// Get inputs from the user
	printf("Enter the first number: ");
	scanf_s("%lf", &firstNumber);

	printf("Enter the second number: ");
	scanf_s("%lf", &secondNumber);

	// Make calculation
	result = fabs(firstNumber + secondNumber) * 36 == 71 || !(firstNumber * secondNumber != -10) || (secondNumber - 10) / (secondNumber + 3) > 10;

	// Show the result
	printf("The result is %d", result);

	return (0);
}
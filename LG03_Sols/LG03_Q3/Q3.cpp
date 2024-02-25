#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	double decimalNumber;

	// Get decimalNumber from user
	printf("Enter a number (3 digits integer and 5 digits fractional): ");
	scanf("%lf", &decimalNumber);

	// Show all the formats
	printf("%.0f\n", decimalNumber);
	printf("%.2f\n", decimalNumber);
	printf("%.8f\n", decimalNumber);
	printf("%9.2f\n", decimalNumber);
	printf("%.7f\n", decimalNumber);
	printf("%8.3f\n", decimalNumber);
	printf("%6.0f\n", decimalNumber);
}
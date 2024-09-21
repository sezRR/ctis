#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	int binaryNumber, dg1, dg2, dg3, dg4, dg5, decimalEquivalent;

	// Get inputs from user
	printf("Enter a binary number: ");
	scanf("%d", &binaryNumber);

	// Make calculation
	dg5 = binaryNumber % 10;
	binaryNumber /= 10;

	dg4 = binaryNumber % 10;
	binaryNumber /= 10;

	dg3 = binaryNumber % 10;
	binaryNumber /= 10;

	dg2 = binaryNumber % 10;
	binaryNumber /= 10;

	dg1 = binaryNumber % 10;
	binaryNumber /= 10;


	decimalEquivalent = dg1 * pow(2, 4) + dg2 * pow(2, 3) + dg3 * pow(2, 2) + dg4 * pow(2, 1) + dg5 * pow(2, 0);

	// Show the result
	printf("Decimal equivalent: %d", decimalEquivalent);
}
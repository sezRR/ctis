#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	double firstProductPrice, firstProductVat;
	double secondProductPrice, secondProductVat;
	double thirdProductPrice, thirdProductVat;
	double result = 0;

	// Get inputs from the user
	printf("Enter first product price and vat: ");
	scanf_s("%lf %lf", &firstProductPrice, &firstProductVat);

	printf("Enter second product price and vat: ");
	scanf_s("%lf %lf", &secondProductPrice, &secondProductVat);

	printf("Enter third product price and vat: ");
	scanf_s("%lf %lf", &thirdProductPrice, &thirdProductVat);

	// Make calculations
	result += (firstProductPrice + firstProductPrice * firstProductVat / 100) + (secondProductPrice + secondProductPrice * secondProductVat / 100) + (thirdProductPrice + thirdProductPrice * thirdProductVat / 100);

	// Show the result
	printf("Total money is %.2f", result);
}
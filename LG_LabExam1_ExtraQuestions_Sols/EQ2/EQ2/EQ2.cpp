#define _CRT_SECURE_NO_WARNINGS

#define DISCOUNT_RATE_GLASSWARE .15
#define DISCOUNT_RATE_EXTRA_GLASSWARE .1

#define DISCOUNT_RATE_FURNITURE .3
#define DISCOUNT_RATE_EXTRA_FURNITURE .15

#include <stdio.h>

int main(void)
{
	// Define variables
	char productType;
	int productPrice;
	double discountedPrice, appliedDiscountRate = 0;

	// Get inputs from the user
	printf("Enter price: ");
	scanf("%d", &productPrice);

	printf("\nEnter product type (G/g or F/f): ");
	scanf(" %c", &productType);

	// Make calculations
	switch (productType)
	{
	case 'G':
	case 'g':
		appliedDiscountRate += DISCOUNT_RATE_GLASSWARE;
		if (productPrice >= 100)
			appliedDiscountRate += DISCOUNT_RATE_EXTRA_GLASSWARE;
		break;
	case 'F':
	case 'f':
		appliedDiscountRate += DISCOUNT_RATE_FURNITURE;
		
		char isFurnitureLeather;
		printf("\nLeather (y/n): ");
		scanf(" %c", &isFurnitureLeather);

		if (isFurnitureLeather == 'y')
			appliedDiscountRate += DISCOUNT_RATE_EXTRA_FURNITURE;
	}

	discountedPrice = productPrice - productPrice * appliedDiscountRate;

	// Show the results
	printf("\nDiscounted price is: %.2f TL", discountedPrice);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#define DISCOUNT_COLD_COFFEES .1
#define EXTRA_DISCOUNT_PRICE_OVER_60 .1
#define DISCOUNT_HOT_COFFEES .25
#define EXTRA_DISCOUNT_ESPRESSO_COFFEES .2

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	int price;
	double discountedPrice = 0;
	char coffeeType, isEspresso;

	// Get inputs from the user
	printf("Enter coffee type (C/c or H/h): ");
	scanf("%c", &coffeeType);

	if (coffeeType == 'C' || coffeeType == 'c') {
		printf("Enter price: ");
		scanf("%d", &price);

		// Consider extra discounts
		if (price > 60) {
			discountedPrice = price - price * (DISCOUNT_COLD_COFFEES + EXTRA_DISCOUNT_PRICE_OVER_60);
			printf("Discounted price is: %.2f TL", discountedPrice);
		}
		else if (price > 0 && price <= 60) {
			discountedPrice = price - price * DISCOUNT_COLD_COFFEES;
			printf("Discounted price is: %.2f TL", discountedPrice);
		}
	}
	else if (coffeeType == 'H' || coffeeType == 'h') {
		printf("Enter price: ");
		scanf("%d", &price); 
		
		printf("Espresso (y/n): ");
		scanf(" %c", &isEspresso);

		if (isEspresso == 'y') {
			discountedPrice = price - price * (DISCOUNT_HOT_COFFEES + EXTRA_DISCOUNT_ESPRESSO_COFFEES);
			printf("Discounted price is: %.2f TL", discountedPrice);
		}
		else if (isEspresso == 'n') {
			discountedPrice = price - price * DISCOUNT_HOT_COFFEES;
			printf("Discounted price is: %.2f TL", discountedPrice);
		}
	}

	return 0;
}
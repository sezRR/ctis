#define _CRT_SECURE_NO_WARNINGS

#define STANDARD_BASE_SHIPPING_COST 30
#define EXTRA_COST_STANDARD_ADDITIONAL_KG 5

#define EXPRESS_BASE_SHIPPING_COST 40
#define EXTRA_COST_EXPRESS_ADDITIONAL_KG 10

#define OVERNIGHT_BASE_SHIPPING_COST 60
#define EXTRA_COST_OVERNIGHT_ADDITIONAL_KG 15

#include <stdio.h>

int main(void)
{
	// Declare variables
	double priceOfItem, _weightOfItem, shippingCost = 0;
	int weightOfItem;
	char shippingMethod;

	// Get inputs from the user
	printf("Enter the price of the item (in TL): ");
	scanf("%lf", &priceOfItem);

	printf("Enter the weight of the item (in kg): ");
	scanf("%lf", &_weightOfItem);

	weightOfItem = _weightOfItem;

	printf("Enter the shipping method (S/s for Standard, E/e for Express, O/o for Overnight): ");
	scanf(" %c", &shippingMethod);

	// Make calculations
	if (shippingMethod == 's' || shippingMethod == 'S') {
		if (priceOfItem < 200) {
			shippingCost = STANDARD_BASE_SHIPPING_COST + (weightOfItem - 1) * EXTRA_COST_STANDARD_ADDITIONAL_KG;
			printf("Total cost is %.2f with Standard shipping", shippingCost + priceOfItem);
		}
		else if (priceOfItem >= 200) {
			printf("Total cost is %.2f with free shipping", priceOfItem);
		}
	}
	else if (shippingMethod == 'e' || shippingMethod == 'E') {
		if (weightOfItem > 1) {
			shippingCost = EXPRESS_BASE_SHIPPING_COST + (weightOfItem - 1) * EXTRA_COST_EXPRESS_ADDITIONAL_KG;
			printf("Total cost is %.2f with Express shipping", shippingCost + priceOfItem);
		}
		else {
			shippingCost = EXPRESS_BASE_SHIPPING_COST;
			printf("Total cost is %.2f with Express shipping", shippingCost + priceOfItem);
		}
	}
	else if (shippingMethod == 'o' || shippingMethod == 'O') {
		shippingCost = OVERNIGHT_BASE_SHIPPING_COST + (weightOfItem - 1) * EXTRA_COST_OVERNIGHT_ADDITIONAL_KG;
		printf("Total cost is %.2f with Overnight shipping", shippingCost + priceOfItem);
	}
	else {
		printf("Shipping method unavaliable!");
	}
}
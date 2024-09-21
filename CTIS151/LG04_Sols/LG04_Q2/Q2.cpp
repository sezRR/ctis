#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	double costOfItem, salesPriceOfItem, profit;

	// Get inputs from the user
	printf("Enter cost of the item: ($) ");
	scanf_s("%lf", &costOfItem);

	printf("Enter sales price of the item: ($) ");
	scanf_s("%lf", &salesPriceOfItem);

	// Make calculation
	profit = salesPriceOfItem - costOfItem;

	// Show the result
	if (profit > 0)
		printf("You are making a profit of %.2f $ from this sale.", profit);
	else
		printf("You are making a loss of %.2f $ from this sale.", fabs(profit));

	return (0);
}
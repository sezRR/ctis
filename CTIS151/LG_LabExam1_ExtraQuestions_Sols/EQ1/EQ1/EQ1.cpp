#define _CRT_SECURE_NO_WARNINGS

#define TAX_RATE_EDUCATION 0.1
#define TAX_RATE_HEALTH 0.2
#define TAX_RATE_FOOD 0.12
#define TAX_RATE_CLOTHING 0.15
#define TAX_RATE_UNKNOWN 0.1

#include <stdio.h>

int main(void)
{
	// Define variables
	char taxGroupCode;
	int priceOfItem;
	double totalPrice, vatAmount, appliedTaxRate = TAX_RATE_UNKNOWN;

	// Get inputs from the user
	printf("Enter tax group code...: ");
	scanf("%c", &taxGroupCode);

	if (taxGroupCode != 'E' &&
		taxGroupCode != 'e' &&
		taxGroupCode != 'H' &&
		taxGroupCode != 'h' &&
		taxGroupCode != 'F' &&
		taxGroupCode != 'f' &&
		taxGroupCode != 'C' &&
		taxGroupCode != 'c')
		printf("\nUnknown tax group code!\n");

	printf("Enter the price of item: ");
	scanf("%d", &priceOfItem);

	// Calculate tax rate by tax group code
	switch (taxGroupCode)
	{
	case 'E':
	case 'e': 
		appliedTaxRate = TAX_RATE_EDUCATION;
		break;
	case 'H':
	case 'h':
		appliedTaxRate = TAX_RATE_HEALTH;
		break;
	case 'F':
	case 'f':
		appliedTaxRate = TAX_RATE_FOOD;
		break;
	case 'C':
	case 'c':
		appliedTaxRate = TAX_RATE_CLOTHING;
	}

	// Make calculations
	vatAmount = priceOfItem * appliedTaxRate;
	totalPrice = priceOfItem + vatAmount;

	// Show the results
	printf("\nVAT amount: %.2f", vatAmount);
	printf("\nTotal price: %.2f", totalPrice);

	return 0;
}
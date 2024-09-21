#define _CRT_SECURE_NO_WARNINGS

#define LUCKY_CUSTOMER_DISCOUNT .65
#define CARPET_PRICE_FOR_SQUARE_METER 112.5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// Declare variables
	int numberOfWaitingCustomer, luckyCustomerNo, carpetArea;
	double price = 0, totalPrice = 0;

	// Get inputs from the user
	printf("Enter the number of waiting customers: ");
	scanf("%d", &numberOfWaitingCustomer);

	srand(time(NULL));
	luckyCustomerNo = rand() % numberOfWaitingCustomer + 1;

	for (int i = 0; i < numberOfWaitingCustomer; i++)
	{
		printf("Enter the area of your carpet: ");
		scanf("%d", &carpetArea);

		if (luckyCustomerNo == i)
		{
			printf("CONGRATULATIONS!! YOU WON AN EXTRA %65 DISCOUNT!!!");
			price = (carpetArea * CARPET_PRICE_FOR_SQUARE_METER) * (1 - LUCKY_CUSTOMER_DISCOUNT);
		}
		else {
			price = carpetArea * CARPET_PRICE_FOR_SQUARE_METER;
		}

		printf("\nYou should pay %.2fTL", price);

		totalPrice += price;
	}

	printf("\nThe company earned %.2f TL from the opening day.", totalPrice);

	return 0;
}
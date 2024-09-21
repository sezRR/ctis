/* LB05_AQ2 -> Purpose of the Program is Finding to Discounted Bill Price
   with Using RandomNumberGenerator.h*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "RandomNumberGenerator.h"

int main(void)
{
	// Define variables
	int bill, discountPercentage;
	double discountedBill;

	// Get the Bill from the User
	printf("Enter your bill: ");
	scanf("%d", &bill);

	// Calculate the Discount Percentage
	discountPercentage = generateRandomNumber();
	printf("\nYou won %d%% discount", discountPercentage);

	// Calculate the Discounted Bill Price
	discountedBill = bill - bill * discountPercentage / 100;
	printf("\nYour new bill is %.2f TL", discountedBill);

	return 0;
}
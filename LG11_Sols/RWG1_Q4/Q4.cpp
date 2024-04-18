#define _CRT_SECURE_NO_WARNINGS

#define BONUS_PAYMENT_PERCENTAGE .15
#define EXTRA_BONUS_PAYMENT 500

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Define variables
	int userId, greatestBonusUserId, saleAmount;
	char isSenior;
	double bonusAmount, greatestBonus = -1;

	while (1)
	{
		// Get inputs from the user
		printf("Enter the id ( <=0 to STOP): ");
		scanf("%d", &userId);

		if (userId <= 0)
			break;

		printf("Enter the sale amount%6c: ", ' ');
		scanf("%d", &saleAmount);

		printf("is s/he is Senior Representitave(y/n): ");
		scanf(" %c", &isSenior);

		// Calculate bonus
		bonusAmount = saleAmount * BONUS_PAYMENT_PERCENTAGE;

		if (isSenior == 'y' || isSenior == 'Y')
			bonusAmount += EXTRA_BONUS_PAYMENT;

		// Check greatest bonus
		if (bonusAmount >= greatestBonus)
		{
			greatestBonusUserId = userId;
			greatestBonus = bonusAmount;
		}

		// Print bonus amount
		printf("Bonus amount is: %.2f\n\n", bonusAmount);
		bonusAmount = 0;
	}

	if (greatestBonus > 0)
	{
		printf("\nThe following representative has the maximum sale amount");
		printf("\nId%3c: %d", ' ', greatestBonusUserId);
		printf("\nBonus: $%.2f", greatestBonus);
	}


	return 0;
}
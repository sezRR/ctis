#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	int menuChoice, numberCount, i;
	double number, result = 0;

	// Get inputs from the user
	do
	{
		printf("1) Addition\n");
		printf("2) Multiplication\n");
		printf("3) Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &menuChoice);
	} while (menuChoice < 1 || menuChoice > 3);

	switch (menuChoice)
	{
	case 1:
		printf("\nHow many numbers do you want to add? ");
		scanf("%d", &numberCount);

		for (i = 1; i <= numberCount; i++)
		{
			printf("Enter %d. number: ", i);
			scanf("%lf", &number);

			result += number;
		}

		printf("The result of addition is %.2f", result);
		break;
	case 2:
		result = 1;
		printf("\nHow many numbers do you want to multiply? ");
		scanf("%d", &numberCount);

		for (i = 1; i <= numberCount; i++)
		{
			printf("Enter %d. number: ", i);
			scanf("%lf", &number);

			result *= number;
		}

		printf("The result of multiplication is %.2f", result);
		break;
	case 3:
		return 0;
	}

	return 0;
}
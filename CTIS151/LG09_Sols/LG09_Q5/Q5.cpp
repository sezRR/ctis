#define _CRT_SECURE_NO_WARNINGS

#define DEFAULT_PRICE 1500
#define PIANO_PRICE 2000
#define ANALYTICAL_THINKING_PRICE 1750

#include <stdio.h>
#include <math.h>

int main(void)
{
	// Declare variables
	int choice, activityCounter = 0;
	double payment = 0;
	char continueInput;

	// Get inputs from the user
	do
	{
		printf("WEEKEND ACTIVITY PROGRAM\n");
		printf("1. Gymnastics\n");
		printf("2. Basketball\n");
		printf("3. Piano\n");
		printf("4. Traditional Dance\n");
		printf("5. Analytical Thinking\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		if (choice > 5 || choice < 1)
			printf("\nWrong Choice!\n");
	} while (choice > 5 || choice < 1);

	do
	{
		activityCounter++;
		switch (choice)
		{
		case 1:
		case 2:
		case 4:
			payment += DEFAULT_PRICE;
			break;
		case 3:
			payment += PIANO_PRICE;
			break;
		case 5:
			payment += ANALYTICAL_THINKING_PRICE;
			break;
		default:
			do
			{
				printf("WEEKEND ACTIVITY PROGRAM\n");
				printf("1. Gymnastics\n");
				printf("2. Basketball\n");
				printf("3. Piano\n");
				printf("4. Traditional Dance\n");
				printf("5. Analytical Thinking\n");
				printf("Enter your choice: ");
				scanf("%d", &choice);

				if (choice > 5 || choice < 1)
					printf("\nWrong Choice!\n");
			} while (choice > 5 || choice < 1);
		}
		printf("Do you want to select new activity (limit is 3): ");
		scanf(" %c", &continueInput);
		choice = 999;
	} while (continueInput == 'y' && activityCounter < 3);

	printf("Total payment is %.2f", payment);

	return 0;
}
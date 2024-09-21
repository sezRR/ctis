#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int* dice1, int* dice2, int* sumOfDices)
{
	srand(time(0));

	*dice1 = rand() % 6 + 1;
	*dice2 = rand() % 6 + 1;

	*sumOfDices = *dice1 + *dice2;
}

int main(void)
{
	// Define variables
	int dice1, dice2, sumOfDices, counter = 1;

	// Make calculations
	while (1)
	{
		rollDice(&dice1, &dice2, &sumOfDices);

		printf("Player rolled %d + %d  = %d\n", dice1, dice2, sumOfDices);

		if (sumOfDices == 2
			|| sumOfDices == 6
			|| sumOfDices == 7
			|| sumOfDices == 11)
		{
			printf("Player wins with %d rolls\n\n", counter);
			break;
		}
		else {
			printf("Player loses\n");
			printf("Continues rolling..\n\n");
		}

		counter++;
	}

	return 0;
}
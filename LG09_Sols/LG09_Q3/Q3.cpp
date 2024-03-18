#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// Declare variables
	int winCounter = 0, generatedNumber = 0;
	char shakeAgain;

	// Get inputs from the user
	do
	{
		printf("\nShake & Win ;)\n");
		srand(time(NULL));
		generatedNumber = rand() % 4 + 1;

		switch (generatedNumber)
		{
		case 1:
			printf("Daily 1 GB internet\n");
			break;
		case 2:
			printf("Weekly 10 GB internet\n");
			break;
		case 3:
			printf("Monthly video and Music package\n");
			break;
		case 4:
			printf("100 mins call package\n");
		}

		winCounter++;
		if (winCounter < 3)
		{
			printf("Shake again? (y/n): ");
			scanf(" %c", &shakeAgain);
		}
	} while (winCounter < 3 && shakeAgain == 'y');

	return 0;
}
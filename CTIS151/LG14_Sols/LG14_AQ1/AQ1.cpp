#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	char wordChar;
	char lastChar = 'a';
	int queueChecker = 0;

	while (1)
	{
		char word[999];
		queueChecker++;

		if (queueChecker % 2 == 1)
			printf("Player-1, enter a word: ");
		else
			printf("Player-2, enter a word: ");

		int counter = 0;
		scanf(" %c", &wordChar);
		while (wordChar != '.')
		{
			if (wordChar != '\n')
			{
				word[counter] = wordChar;
			}

			scanf("%c", &wordChar);
			counter++;
		}
		
		if (lastChar != word[0])
		{
			printf("\n");
			for (int i = 0; i < counter; i++)
			{
				printf("%c", word[i]);
			}

			printf(" does not start with %c!\n", lastChar);
			printf("Game over: Player-%d wins.\n", (queueChecker % 2) + 1);
			break;
		}

		lastChar = word[counter - 1];
	}

	return 0;
}
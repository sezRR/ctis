#define _CRT_SECURE_NO_WARNINGS

#define SIZE_X 5
#define SIZE_Y 4
#define BONUS_CHECK 3
#define BONUS 5

#include <stdio.h>

int main(void)
{
	FILE* gamersFile = fopen("gamers.txt", "r");

	if (gamersFile == NULL)
		printf("File could not be opened!");
	else
	{
		int arr[SIZE_Y][SIZE_X];

		for (int i = 0; i < SIZE_Y; i++)
			for (int j = 0; j < SIZE_X; j++)
				fscanf(gamersFile, "%d", &arr[i][j]);

		for (int i = 0; i < SIZE_Y; i++)
		{
			int tempSum = 0;
			for (int j = 0; j < SIZE_X; j++)
			{
				tempSum += arr[i][j];

				if (j == BONUS_CHECK - 1 && arr[i][j] >= 10)
					tempSum += BONUS;
			}

			printf("%d. player score: %d\n", i + 1, tempSum);
		}
	}

	return 0;
}
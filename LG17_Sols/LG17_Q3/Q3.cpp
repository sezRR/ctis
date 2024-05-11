#define _CRT_SECURE_NO_WARNINGS

#define SIZE_X 12
#define SIZE_Y 5

#include <stdio.h>

int main(void)
{
	FILE* wordsFile = fopen("words.txt", "r");

	if (wordsFile == NULL)
		printf("File could not be opened!");
	else
	{
		char arr[SIZE_Y][SIZE_X];

		for (int i = 0; i < SIZE_Y; i++)
			for (int j = 0; j < SIZE_X; j++)
				fscanf(wordsFile, " %c", &arr[i][j]);

		int column;
		printf("Which word do you want to display? ");
		scanf("%d", &column);

		char word[SIZE_Y];
		for (int i = 0; i < SIZE_Y; i++)
			word[i] = arr[i][column - 1];

		printf("\nThe word -> ");
		for (int i = 0; i < SIZE_Y; i++)
			printf("%c", word[i]);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LENGTH 99

#include <stdio.h>

void readFromFile(FILE* file, char chars[][MAX_ARR_LENGTH], int* arrSizeX, int* arrSizeY)
{
	int row = 0, column = 0;
	while (fscanf(file, "%c", &chars[row][column]) != EOF)
	{
		if (chars[row][column] == '\n')
		{
			row++;
			column = 0;
		}
		else
			column++;
	}

	*arrSizeX = column;
	*arrSizeY = row + 1;
}

void displayTwoDimension(char chars[][MAX_ARR_LENGTH], int arrSizeX, int arrSizeY)
{
	for (int i = 0; i < arrSizeY; i++) {
		for (int j = 0; j < arrSizeX; j++)
			printf("%c", chars[i][j]);

		printf("\n");
	}

	printf("\n");
}

void displayDimension(char chars[][MAX_ARR_LENGTH], int dimensionLength)
{
	printf("Dimension for %d, MAJOR elements of the file is: ", dimensionLength);
	for (int i = 0; i < dimensionLength; i++)
			printf("%c", chars[i][i]);

	printf("\nDimension for %d, MINOR elements of the file is: ", dimensionLength);
	for (int i = 0; i < dimensionLength; i++)
		printf("%c", chars[i][dimensionLength - i - 1]);

	printf("\n\n");
}

int main(void)
{
	FILE* wordsFile = fopen("words.txt", "r");

	if (wordsFile == NULL)
		printf("File could not be opened!");
	else
	{
		int sizeX = 0, sizeY = 0;
		char chars[MAX_ARR_LENGTH][MAX_ARR_LENGTH];

		readFromFile(wordsFile, chars, &sizeX, &sizeY);
		displayTwoDimension(chars, sizeX, sizeY);

		int userDimensionChoice;
		while (1)
		{
			do {
				printf("Enter the dimension: [1 - %d]: ", sizeY);
				scanf("%d", &userDimensionChoice);
			} while (userDimensionChoice < -1 || userDimensionChoice > sizeY);

			if (userDimensionChoice == -1)
			{
				printf("EXIT!");
				break;
			}

			displayDimension(chars, userDimensionChoice);
		}
	}

	return 0;
}
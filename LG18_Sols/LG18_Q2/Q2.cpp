#define _CRT_SECURE_NO_WARNINGS

#define ARR_LENGTH 4

#include <stdio.h>

int readFromFile(FILE* file, int ids[], int gameScores[][ARR_LENGTH])
{
	int i = 0, row = 0, column = 0;
	while (fscanf(file, "%d %d %d %d %d", &ids[i++], &gameScores[row][column++], &gameScores[row][column++], &gameScores[row][column++], &gameScores[row][column++]) != EOF)
		row++;

	return i + 1;
}

void findTeamAvg(int gameScores[][ARR_LENGTH], int numberOfTeams)
{
	for (int i = 0; i < ARR_LENGTH; i++)
	{

	}
}

int main(void)
{
	FILE* bowlingFile = fopen("bowling.txt", "r");

	if (bowlingFile == NULL)
		printf("File could not be opened!");
	else
	{

	}

	return 0;
}
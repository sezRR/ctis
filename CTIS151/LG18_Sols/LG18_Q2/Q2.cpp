#define _CRT_SECURE_NO_WARNINGS

#define ARR_LENGTH 4
#define MAX_ARR_LENGTH 99

#include <stdio.h>

int readFromFile(FILE* file, int ids[], int gameScores[][ARR_LENGTH])
{
	int i = 0, row = 0;
	while (fscanf(file, "%d %d %d %d %d", &ids[i++], &gameScores[row][0], &gameScores[row][1], &gameScores[row][2], &gameScores[row][3]) != EOF)
		row++;

	return i - 1;
}

void findTeamAvg(int gameScores[][ARR_LENGTH], double teamAverages[], int numberOfTeams)
{
	double sum = 0;
	for (int i = 0; i < numberOfTeams; i++)
	{
		for (int j = 0; j < ARR_LENGTH; j++)
			sum += gameScores[i][j];

		teamAverages[i] = sum / ARR_LENGTH;
		sum = 0;
	}
}

void findGameAvg(int gamesScores[][ARR_LENGTH], double gameAverages[], int numberOfTeams)
{
	double sum = 0;
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		for (int j = 0; j < numberOfTeams; j++)
			sum += gamesScores[j][i];
			
		gameAverages[i] = sum / numberOfTeams;
		sum = 0;
	}
}

void displayTeamAverages(int teamIds[], double teamAverages[], int numberOfTeams)
{
	printf("Team Number\tAverage\n");
	printf("***********\t*******\n");

	for (int i = 0; i < numberOfTeams; i++)
		printf(" %-6d %14.2f\n", teamIds[i], teamAverages[i]);

	printf("\n");
}

void displayGameAverages(double gameAverages[])
{
	printf("Game Number\tAverage\n");
	printf("***********\t*******\n");

	for (int i = 0; i < ARR_LENGTH; i++)
		printf("%-7d %13.1f\n", i + 1, gameAverages[i]);
}

int main(void)
{
	FILE* bowlingFile = fopen("bowling.txt", "r");

	if (bowlingFile == NULL)
		printf("File could not be opened!");
	else
	{
		int gameScores[MAX_ARR_LENGTH][ARR_LENGTH], ids[MAX_ARR_LENGTH];
		int numberOfTeams = readFromFile(bowlingFile, ids, gameScores);

		double gameAverages[ARR_LENGTH], teamAverages[MAX_ARR_LENGTH];

		findTeamAvg(gameScores, teamAverages, numberOfTeams);
		findGameAvg(gameScores, gameAverages, numberOfTeams);

		displayTeamAverages(ids, teamAverages, numberOfTeams);
		displayGameAverages(gameAverages);
	}

	return 0;
}
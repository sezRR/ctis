#define _CRT_SECURE_NO_WARNINGS

#define MAX_SCORE_LEN 4
#define MAX_TEAM 10

#include <stdio.h>
#include <stdlib.h>

int readFromFile(FILE* file, int teamIds[], int scores[][MAX_SCORE_LEN]) {
	int teamCounter = 0;
	while (fscanf(file, "%d", &teamIds[teamCounter]) != EOF) {
		for (int i = 0; i < MAX_SCORE_LEN; i++)
			fscanf(file, "%d", &scores[teamCounter][i]);
		teamCounter += 1;
	}
	return teamCounter + 1;
}

void findTeamAvg(int scores[][MAX_SCORE_LEN], double teamAverages[]) {
	double teamSum = 0;
	for (int i = 0; i < MAX_TEAM; i++)
	{
		for (int j = 0; j < MAX_SCORE_LEN; j++)
			teamSum += scores[i][j];
		teamAverages[i] = teamSum / MAX_SCORE_LEN;
		teamSum = 0;
	}
}

void findGameAvg(int scores[][MAX_SCORE_LEN], double gameAverages[]) {
	double gameSum = 0;
	for (int i = 0; i < MAX_SCORE_LEN; i++)
	{
		for (int j = 0; j < MAX_TEAM; j++)
			gameSum += scores[j][i];
		gameAverages[i] = gameSum / MAX_TEAM;
		gameSum = 0;
	}
}

void displayGameAvg(double gameAverages[], double teamAverages[], int teamIds[]) {
	printf("Team Number\tAverage\n");
	printf("***********\t*******\n");
	for (int i = 0; i < MAX_TEAM; i++)
	{
		printf("%d\t\t%.2f\n", teamIds[i], teamAverages[i]);
	}

	printf("\nGame Number\tAverage\n");
	printf("***********\t*******\n");
	for (int i = 0; i < MAX_SCORE_LEN; i++)
	{
		printf("%d\t\t%.1f\n", i + 1, gameAverages[i]);
	}
}

int main(void) {
	int teamIds[MAX_TEAM], scores[MAX_TEAM][MAX_SCORE_LEN];
	double teamAverages[MAX_TEAM], gameAverages[MAX_SCORE_LEN];
	FILE* bowlingFile = fopen("bowling.txt", "r");
	if (bowlingFile == NULL)
	{
		printf("File could not be read!");
	}
	else {
		readFromFile(bowlingFile, teamIds, scores);
		findTeamAvg(scores, teamAverages);
		findGameAvg(scores, gameAverages);
		displayGameAvg(gameAverages, teamAverages, teamIds);
		fclose(bowlingFile);
	}

	return 0;
}
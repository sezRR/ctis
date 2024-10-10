#define _CRT_SECURE_NO_WARNINGS

#define MAX_TEAM_COUNT 20

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int playedMatch;
	int wins;
	int losses;
} match_details_t;

typedef struct {
	char name[50];
	int points;
	match_details_t matchDetails;
} volleyball_team_t;

int readFromFile(FILE* file, volleyball_team_t* teams) {
	int teamCount = 0;
	while (fscanf(file, "%s %d %d %d %d", (teams + teamCount)->name, &(teams + teamCount)->points, &(teams + teamCount)->matchDetails.playedMatch, &(teams + teamCount)->matchDetails.wins, &(teams + teamCount)->matchDetails.losses) != EOF)
		teamCount++;

	return teamCount;
}

void displayAll(volleyball_team_t* teams, int teamCount) {
	printf("Team Name \t\t Pts \t Matches \t Wins \t Losses\n");
	printf("-----------------------------------------------------------------\n");
	for (int i = 0; i < teamCount; i++)
		printf("%-20s \t %d \t %d \t\t %d \t %d\n", (teams + i)->name, (teams + i)->points, (teams + i)->matchDetails.playedMatch, (teams + i)->matchDetails.wins, (teams + i)->matchDetails.losses);
}

int findWinner(volleyball_team_t* teams, int teamCount) {
	int maxPoint = -1, returnIndex = -1;

	for (int i = 0; i < teamCount; i++)
		if ((teams + i)->points >= maxPoint) {
			returnIndex = i;
			maxPoint = (teams + i)->points;
		}

	return returnIndex;
}

int main(void) {
	FILE* volleyballFile = fopen("volleyball.txt", "r");
	volleyball_team_t* teams;
	int teamCount, winnerTeamIndex;

	if (volleyballFile == NULL)
		printf("File could not be opened!");
	else {
		teams = (volleyball_team_t*)malloc(MAX_TEAM_COUNT * sizeof(volleyball_team_t));
		teamCount = readFromFile(volleyballFile, teams);

		displayAll(teams, teamCount);
		winnerTeamIndex = findWinner(teams, teamCount);

		printf("\n\nThe Winner team:\n");
		printf("%s \t %d \t %d \t %d \t %d", (teams + winnerTeamIndex)->name, (teams + winnerTeamIndex)->points, (teams + winnerTeamIndex)->matchDetails.playedMatch, (teams + winnerTeamIndex)->matchDetails.wins, (teams + winnerTeamIndex)->matchDetails.losses);

		free(teams);
		fclose(volleyballFile);
	}

	return 0;
}
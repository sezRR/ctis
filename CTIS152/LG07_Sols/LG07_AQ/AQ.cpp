#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int age;
	double length;
	double avgScore;
	double avgRebound;
} player_t;

int readFromFile(FILE* file, player_t* players) {
	int nb = 0;
	while (fscanf(file, "%s %d %lf %lf %lf",
		(players + nb)->name,
		&(players + nb)->age,
		&(players + nb)->length,
		&(players + nb)->avgScore,
		&(players + nb)->avgRebound) != EOF)
				nb++;
	return nb;
}

void displayPlayer(player_t* players, int nb) {
	printf("NAME \t\t AGE \t LENGTH \t AVG SCORE \t AVG REBOUND\n");
	printf("--------------------------------------------------------------------\n");
	for (int i = 0; i < nb; i++)
		printf("%-7s \t %d \t %.2lf \t\t %.2lf \t\t %.2lf\n",
			(players + i)->name,
			(players + i)->age,
			(players + i)->length,
			(players + i)->avgScore,
			(players + i)->avgRebound);
}

int findBestRebound(player_t* players, int nb) {
	int mx = 0;
	for (int i = 1; i < nb; i++)
		if ((players + i)->avgRebound >= (players + mx)->avgRebound)
			mx = i;
	return mx;
}

int main(void) {
	FILE* file = fopen("players.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		player_t players[15];
		int nb = readFromFile(file, players);
		displayPlayer(players, nb);

		int bestRebound = findBestRebound(players, nb);
		printf("\nThe Best Rebound Player:\n");
		printf("%-7s \t %d \t %.2lf \t\t %.2lf \t\t %.2lf\n",
			(players + bestRebound)->name,
			(players + bestRebound)->age,
			(players + bestRebound)->length,
			(players + bestRebound)->avgScore,
			(players + bestRebound)->avgRebound);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	char surname[50];
	double timeToComplete;
	char medalInfo;
} swimmer_t;

int main(void) {
	FILE* swimmersFile = fopen("swimmers.txt", "r");
	swimmer_t* swimmers;

	if (swimmersFile == NULL)
		printf("File could not be opened!");
	else {
		int swimmerCount;
		fscanf(swimmersFile, "%d", &swimmerCount);

		swimmers = (swimmer_t*)malloc(swimmerCount * sizeof(swimmer_t));

		for (int i = 0; i < swimmerCount; i++)
			fscanf(swimmersFile, "%s %s %lf %c",
				(swimmers + i)->name,
				(swimmers + i)->surname,
				&(swimmers + i)->timeToComplete,
				&(swimmers + i)->medalInfo);

		printf("Swimmer Name \t Surname \t Time to Complete the Lane \t Medal Info\n");
		printf("************ \t ********* \t ************************* \t ********** \n");
		for (int i = 0; i < swimmerCount; i++)
		{
			if ((swimmers + i)->medalInfo != 'Y' || (swimmers + i)->timeToComplete >= 160)
				continue;

			int completedInSeconds = (int)(swimmers + i)->timeToComplete;
			int completedInSecMiliseconds = (int)((swimmers + i)->timeToComplete * 10) % 10;
			printf("%-10s \t %-10s \t %d seconds %d miliseconds \t %c \n",
				(swimmers + i)->name,
				(swimmers + i)->surname,
				completedInSeconds,
				completedInSecMiliseconds,
				(swimmers + i)->medalInfo);
		}

		fclose(swimmersFile);
	}

	return 0;
}
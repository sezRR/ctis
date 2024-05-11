#define _CRT_SECURE_NO_WARNINGS

#define ARR_MAX_LENGTH 50

#include <stdio.h>

int dispMenu()
{
	int userChoice;
	printf("1. Display Highest Scores\n");
	printf("2. Display Average of Highest Scores\n");
	printf("3. Display Player Info\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");

	while (1)
	{
		scanf("%d", &userChoice);

		if (userChoice < 1 || userChoice > 4)
			printf("Wrong choice! Enter again: ");
		else
			break;
	} 

	return userChoice;
}

void displayHighest(int ids[], int highestScores[], int counter)
{
	printf("ID %5c Highest Score\n", ' ');
	printf("**** %3c **************\n", ' ');
	for (int i = 0; i < counter; i++)
		printf("%d %13d\n", ids[i], highestScores[i]);
}

void displayAverages(char genders[], int highestScores[], int counter)
{
	int sumMale = 0, counterMale = 0;
	int sumFemale = 0, counterFemale = 0;
	double avgMale, avgFemale;

	for (int i = 0; i < counter; i++)
	{
		switch (genders[i])
		{
		case 'M':
			counterMale++;
			sumMale += highestScores[i];
			break;
		case 'F':
			counterFemale++;
			sumFemale += highestScores[i];
		}
	}

	printf("Average highest score for male Players is  : %d\n", sumMale / counterMale);
	printf("Average highest score for female Players is: %d\n", sumFemale / counterFemale);
	printf("Average highest score for all Players is   : %d\n\n", (sumMale + sumFemale) / (counterMale + counterFemale));
}

int findPlayer(int ids[], int ages[], char genders[], int highestScores[], int counter)
{
	int userIdToFind;
	printf("Enter Player Id: ");
	scanf("%d", &userIdToFind);

	for (int i = 0; i < counter; i++)
	{
		if (ids[i] == userIdToFind)
		{
			printf("Player Info\n");
			printf("Id: %d\n", ids[i]);
			printf("Age: %d\n", ages[i]);
			printf("Gender: %c\n", genders[i]);
			printf("Highest Score: %d\n\n", highestScores[i]);

			return i;
		}
	}

	return -1;
}

int main(void)
{
	FILE* playersFile = fopen("players.txt", "r");

	if (playersFile == NULL)
		printf("File could not be opened!");
	else {
		int ids[ARR_MAX_LENGTH];
		char genders[ARR_MAX_LENGTH];
		int ages[ARR_MAX_LENGTH];
		int highScores[ARR_MAX_LENGTH];

		int counter = 0;
		while (fscanf(playersFile, "%d %c %d %d", &ids[counter], &genders[counter], &ages[counter], &highScores[counter]) != EOF)
			counter++;

		while (1)
		{
			int menuChoice = dispMenu();
			switch (menuChoice)
			{
			case 1:
				displayHighest(ids, highScores, counter);
				break;
			case 2:
				displayAverages(genders, highScores, counter);
				break;
			case 3:
				if (findPlayer(ids, ages, genders, highScores, counter) == -1)
					printf("Player not found!\n\n");
			}

			if (menuChoice == 4)
				break;
		}
	}

	return 0;
}
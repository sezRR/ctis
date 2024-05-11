#define _CRT_SECURE_NO_WARNINGS

#define FEMALE_CHAR 'F'
#define MALE_CHAR 'M'

#include <stdio.h>

int dispMenu()
{
	int menuChoice;

	printf("1. Display Highest Scores\n");
	printf("2. Display Average of Highest Scores\n");
	printf("3. Display Player info\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");

	while (1)
	{
		scanf("%d", &menuChoice);

		if (menuChoice < 1 || menuChoice > 4)
			printf("Wrong choice! Enter again: ");
		else
			break;
	}
	
	return menuChoice;
}

void displayHighest()
{
	FILE* playersFile = fopen("players.txt", "r");

	if (playersFile == NULL)
		printf("\nFile could not be opened!");
	else {
		int tempId;
		double tempHighScore;

		printf("\nID          Highest Score\n");
		printf("****       ***************\n");
		while (fscanf(playersFile, "%d %*c %*d %lf", &tempId, &tempHighScore) != EOF)
			printf("%d %15.0f\n", tempId, tempHighScore);
	}
}

void displayAverages()
{
	FILE* playersFile = fopen("players.txt", "r");

	if (playersFile == NULL)
		printf("\nFile could not be opened!");
	else {
		int averageHighestScoreMale, averageHighestScoreFemale, averageHighestScoreAll;
		int maleHighestScoreSum = 0, femaleHighestScoreSum = 0;
		int maleCounter = 0, femaleCounter = 0;

		char tempGender;
		int tempHighScore;

		while (fscanf(playersFile, "%*d %c %*d %d", &tempGender, &tempHighScore) != EOF)
			switch (tempGender)
			{
			case MALE_CHAR:
				maleHighestScoreSum += tempHighScore;
				maleCounter++;
				break;
			case FEMALE_CHAR:
				femaleHighestScoreSum += tempHighScore;
				femaleCounter++;
			}

		// Make calculations
		averageHighestScoreMale = maleHighestScoreSum / maleCounter;
		averageHighestScoreFemale = femaleHighestScoreSum / femaleCounter;
		averageHighestScoreAll = (maleHighestScoreSum + femaleHighestScoreSum) / (maleCounter + femaleCounter);

		printf("\nAverage highest score for male Players is : %d\n", averageHighestScoreMale);
		printf("Average highest score for female Players is : %d\n", averageHighestScoreFemale);
		printf("Average highest score for all Players is : %d\n", averageHighestScoreAll);
	}
}

void displayPlayerInfo()
{
	FILE* playersFile = fopen("players.txt", "r");

	if (playersFile == NULL)
		printf("\nFile could not be opened!");
	else {
		int playerId, tempPlayerId, tempPlayerAge, tempHighestScore;
		char tempPlayerGender;

		printf("\nEnter Player ID: ");
		scanf("%d", &playerId);

		while (fscanf(playersFile, "%d %c %d %d", &tempPlayerId, &tempPlayerGender, &tempPlayerAge, &tempHighestScore) != EOF)
		{
			if (playerId == tempPlayerId)
			{
				printf("Player Info\n");
				printf("ID: %d\n", playerId);
				printf("Age: %d\n", tempPlayerAge);
				printf("Gender: %c\n", tempPlayerGender);
				printf("Highest Score: %d\n", tempHighestScore);

				return;
			}
		}

		printf("Player not found!\n");
	}
}

int main(void)
{
	while (1)
	{
		switch (dispMenu())
		{
		case 1:
			displayHighest();
			break;
		case 2:
			displayAverages();
			break;
		case 3:
			displayPlayerInfo();
			break;
		case 4:
			return 0;
		}
	}

	return 0;
}
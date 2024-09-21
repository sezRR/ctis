#define _CRT_SECURE_NO_WARNINGS

#define SYMBOL_PAPER 'p'
#define SYMBOL_ROCK 'r'
#define SYMBOL_SCISSORS 's'
#define SYMBOL_QUIT 'q'

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getMachineChoice(char *machineChoice)
{
	srand(time(NULL));

	int generatedNumber = rand() % 3;

	switch (generatedNumber)
	{
	case 0:
		*machineChoice = SYMBOL_PAPER;
		printf("The machine chooses paper. ");
		break;
	case 1:
		*machineChoice = SYMBOL_ROCK;
		printf("The machine chooses rock. ");
		break;
	case 2:
		*machineChoice = SYMBOL_SCISSORS;
		printf("The machine chooses scissors. ");
		break;
	}
}

void getUserChoiceAsAnInput(char &userChoice)
{
	printf("Choose (%c)aper, (%c)ock, (%c)cissors or (%c)uit: ", SYMBOL_PAPER, SYMBOL_ROCK, SYMBOL_SCISSORS, SYMBOL_QUIT);
	scanf(" %c", &userChoice);
}

void checkUserScoreAndProcess(int* userScore, int process)
{
	if (!(*userScore == 0 && process < 0))
		*userScore = *userScore + process;
}

void processUserLoseSituation(int& userScore)
{
	printf("You Lose! ");
	checkUserScoreAndProcess(&userScore, -1);
}

void processUserWinSituation(int& userScore)
{
	printf("You Win! ");
	checkUserScoreAndProcess(&userScore, 1);
}

void printPaperCoversRock()
{
	printf("Paper covers Rock. ");
}

void printScissorsCutsPaper()
{
	printf("Scissors cuts Paper. ");
}

void printRockBreaksScissors()
{
	printf("Rock breaks Scissors. ");
}

void printUserScore(int& userScore)
{
	printf("Your score: %d\n\n", userScore);
}

void evaluateUserChoice(char& userChoice, char& machineChoice, int& userScore)
{
	switch (userChoice)
	{
	case SYMBOL_PAPER:
		if (machineChoice == SYMBOL_ROCK)
		{
			printPaperCoversRock();
			processUserWinSituation(userScore);
		}
		else if (machineChoice == SYMBOL_SCISSORS)
		{
			printScissorsCutsPaper();
			processUserLoseSituation(userScore);
		}
		break;
	case SYMBOL_ROCK:
		if (machineChoice == SYMBOL_PAPER)
		{
			printPaperCoversRock();
			processUserLoseSituation(userScore);
		}
		else if (machineChoice == SYMBOL_SCISSORS)
		{
			printRockBreaksScissors();
			processUserWinSituation(userScore);
		}
		break;
	case SYMBOL_SCISSORS:
		if (machineChoice == SYMBOL_PAPER)
		{
			printScissorsCutsPaper();
			processUserWinSituation(userScore);
		}
		else if (machineChoice == SYMBOL_ROCK)
		{
			printRockBreaksScissors();
			processUserLoseSituation(userScore);
		}
	}
}

int main(void)
{
	// Define variables
	char userChoice;
	char machineChoice;
	int userScore = 0;

	while (1)
	{
		getUserChoiceAsAnInput(userChoice);

		if (userChoice == SYMBOL_QUIT)
			break;

		getMachineChoice(&machineChoice);

		if (userChoice == machineChoice)
		{
			printf("It's a tie! ");
		}
		else {
			evaluateUserChoice(userChoice, machineChoice, userScore);
		}

		printUserScore(userScore);
	}

	return 0;
}

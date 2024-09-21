#define _CRT_SECURE_NO_WARNINGS

#define ARR_MAX_LENGTH 53

#include <stdio.h>

void printAllNumbers(char* numbers);
void printEvenNumbers(char* numbers);
int menu();
void readFile(FILE* file, char* numbers);

int main(void)
{
	// Declare variables
	FILE* numbersFile{};
	char numbers[ARR_MAX_LENGTH];

	readFile(numbersFile, numbers);

	while (1)
	{
		switch (menu())
		{
		case 1:
			printAllNumbers(numbers);
			break;
		case 2:
			printEvenNumbers(numbers);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}
	}

	return 0;
}

void printAllNumbers(char* numbers)
{
	printf("\nAll numbers\n");
	printf("************\n");
	for (int i = 0; i < ARR_MAX_LENGTH; i++)
		printf("%c", *(numbers + i));

	printf("\n\n");
}

void printEvenNumbers(char* numbers)
{
	printf("\Even numbers\n");
	printf("************\n");
	for (int i = 0; i < ARR_MAX_LENGTH; i++)
	{
		for (int j = 0; j < ARR_MAX_LENGTH; j++)
		{
			char tempChars[ARR_MAX_LENGTH];
			int maxElementIndex = 0;

			if (*(numbers + j) != ' ')
			{
				tempChars[j] = *(numbers + i);
				maxElementIndex++;
			}
			else
			{
				if (*(numbers + j - 1) % 2 == 0)
				{
					for (int k = 0; k <= maxElementIndex; k++)
						printf("%c", tempChars[k]);

					printf(" ");
				}
			}
		}
	}

	printf("\n\n");
}

int menu()
{
	int userChoice;

	printf("DISPLAY\n");
	printf("1. All numbers\n");
	printf("2. Even numbers\n");
	printf("3. Subscripts of odd numbers\n");
	printf("4. The numbers with even subscripts\n");
	printf("5. Minimum number\n");
	printf("6. Subscript of maximum number\n");
	printf("7. Exit\n");
	printf("Enter your choice: ");

	while (1)
	{
		scanf("%d", &userChoice);

		if (userChoice < 1 || userChoice > 7)
			printf("Wrong Choice! Enter again: ");
		else
			return userChoice;
	}
}

void readFile(FILE* file, char* numbers)
{
	file = fopen("numbers.txt", "r");

	if (file == NULL)
		printf("File could not be opened!");
	else
	{
		int indexCounter = 0;
		bool skip = 0;

		char tempChar = fgetc(file);
		while (tempChar != EOF)
		{
			if (skip != 1)
			{
				if (tempChar == ' ')
					skip = 1;

				*(numbers + indexCounter) = tempChar;
				indexCounter++;
			}
			else
				skip = 0;

			tempChar = fgetc(file);
		}
	}

	fclose(file);
}
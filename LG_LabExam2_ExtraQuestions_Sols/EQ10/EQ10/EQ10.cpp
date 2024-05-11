#define _CRT_SECURE_NO_WARNINGS

#define MAX_X 51
#define MAX_Y 25

#include <stdio.h>

int menu()
{
	int userChoice;

	printf("1. Display original\n");
	printf("2. Display with rightwards rotation\n");
	printf("3. Display with leftwards rotation\n");
	printf("4. Exit\n");

	do
	{
		printf("Enter your choice: ");
		scanf("%d", &userChoice);
	} while (userChoice < 1 || userChoice > 4);

	return userChoice;
}

void display(int arr[MAX_X][MAX_Y])
{
	printf("\nORIGINAL PICTURE\n");
	for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
			printf("%c", arr[j][i]);
	}
}

void rightwards(int arr[MAX_Y][MAX_X])
{
	printf("\nPICTURE RIGHT-ROTATED\n");
	for (int i = 0; i < MAX_X; i++)
	{
		for (int j = 0; j < MAX_Y; j++)
			printf("%c", arr[j][i]);
	}
}

int main(void)
{
	FILE* mortalKombatFile = fopen("mortalkombat.txt", "r");

	if (mortalKombatFile == NULL)
		printf("File could not be opened!");
	else {
		switch (menu())
		{
		case 1:
			int arr[MAX_X][MAX_Y];

			for (int i = 0; i < MAX_Y; i++)
			{
				for (int j = 0; j < MAX_X; j++)
					arr[j][i] = fgetc(mortalKombatFile);
			}

			display(arr);
			break;
		case 2:
			int arrRightwards[MAX_Y][MAX_X];

			for (int i = MAX_X - 1; i >= 0; i--)
			{
				for (int j = 0; j < MAX_Y; j++)
				{
					char temp = fgetc(mortalKombatFile);
					arrRightwards[j][i] = temp;
					//printf("%c", arr[j][i]);
				}
			}

			rightwards(arrRightwards);
			break;
		case 3:
			break;
		case 4:
			break;
		}

		fclose(mortalKombatFile);
	}


	return 0;
}
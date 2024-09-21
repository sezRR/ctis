#define _CRT_SECURE_NO_WARNINGS

#define RECTANGLE_HEIGHT 4
#define PARALLELOGRAM_HEIGHT 4

#include <stdio.h>

void menu()
{
	printf("MENU\n");
	printf("1. Draw a single line\n");
	printf("2. Draw a rectangle\n");
	printf("3. Draw a parallelogram\n");
	printf("4. EXIT\n");
}

void dispLine()
{
	char printedSymbol;
	int numberOfCharacterToBeDisplayed;

	printf("Enter a symbol: ");
	scanf(" %c", &printedSymbol);

	printf("Enter the number of symbols to be displayed: ");
	scanf("%d", &numberOfCharacterToBeDisplayed);

	for (int i = 0; i < numberOfCharacterToBeDisplayed; i++)
	{
		printf("%c", printedSymbol);
	}
	printf("\n");
}

void dispRectangle()
{
	char printedSymbol;
	int side1, side2;

	printf("Enter a symbol: ");
	scanf(" %c", &printedSymbol);

	printf("Enter the side1: ");
	scanf("%d", &side1);

	printf("Enter the side2: ");
	scanf("%d", &side2);

	for (int i = 0; i < side1; i++)
	{
		for (int i = 0; i < side2; i++)
		{
			printf("%c", printedSymbol);
		}
		printf("\n");
	}
}

void dispParallelogram()
{
	char printedSymbol;
	int side1, side2;

	printf("Enter a symbol: ");
	scanf(" %c", &printedSymbol);

	printf("Enter the side1: ");
	scanf("%d", &side1);

	printf("Enter the side2: ");
	scanf("%d", &side2);

	for (int i = 0; i < side1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}

		for (int i = 0; i < side2; i++)
		{
			printf("%c", printedSymbol);
		}
		printf("\n");
	}
}

int main(void)
{
	// Declare variables
	int choice;

	do
	{
		menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);

		if (choice != 4)
		{
			switch (choice)
			{
			case 1:
				dispLine();
				break;
			case 2:
				dispRectangle();
				break;
			case 3:
				dispParallelogram();
			}
		}
	} while (choice >= 1 && choice < 4);

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#define LINE_SIZE 10
#define LINE_CHARACTER '#'

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
	for (int i = 0; i < LINE_SIZE; i++)
	{
		printf("%c", LINE_CHARACTER);
	}
	printf("\n");
}

void dispRectangle()
{
	for (int i = 0; i < RECTANGLE_HEIGHT; i++)
	{
		dispLine();
	}
}

void dispParallelogram()
{
	for (int i = 0; i < PARALLELOGRAM_HEIGHT; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		dispLine();
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

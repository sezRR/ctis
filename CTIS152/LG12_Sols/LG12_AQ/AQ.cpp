#define _CRT_SECURE_NO_WARNINGS

#define MENU_CHOICE_VALIDATOR(choice) choice < 1 || choice > 3

#define MAX 30

#include <stdio.h>
#include <string.h>

int menu() {
	int choice;
	do
	{
		printf("MENU\n");
		printf("********************\n");
		printf("1. Display the Hotel List\n");
		printf("2. Add a new Hotel\n");
		printf("3. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		if (MENU_CHOICE_VALIDATOR(choice))
			printf("Invalid Menu Choice!\n\n");
	} while (MENU_CHOICE_VALIDATOR(choice));

	return choice;
}

int readFromFile(FILE* file, char hotels[][MAX]) {
	int hotelCounter = 0;
	while (fscanf(file, " %[^\n]", hotels[hotelCounter]) != EOF)
		hotelCounter++;
	return hotelCounter;
}

void display(char hotels[][MAX], int hotelCount) {
	printf("Hotel List\n");
	printf("--------------------\n");
	for (int i = 0; i < hotelCount; i++)
		printf("%d) %s\n", i + 1, hotels[i]);
	printf("\n");
}

void swap(char* s1, char* s2) {
	char temp[MAX] = "";
	strcpy(temp, s1);
	strcpy(s1, s2);
	strcpy(s2, temp);
}

void bubbleSort(char hotels[][MAX], int hotelCount) {
	int sorted = 0,
		progress = 1;
	do
	{
		sorted = 1;
		for (int i = 0; i < hotelCount - progress; i++)
			if (strcmp(hotels[i], hotels[i + 1]) > 0) {
				swap(hotels[i], hotels[i + 1]);
				sorted = 0;
			}
		progress++;
	} while (!sorted);
}

int binarySearch(char hotels[][MAX], char* search, int l, int r, int* insertPos) {
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (strcmp(hotels[m], search) == 0)
			return m;
		else if (strcmp(hotels[m], search) > 0)
			r = m - 1;
		else
			l = m + 1;
	}

	*insertPos = l;
	return -1;
}

void shiftDown(char hotels[][MAX], int* arrSize, int insertPos) {
	for (int i = *arrSize - 1; i >= insertPos; i--)
		strcpy(hotels[i + 1], hotels[i]);
	(*arrSize)++;
}

void addToList(char hotels[][MAX], char* newHotel, int* arrLen) {
	int insertPos = -1;
	binarySearch(hotels, newHotel, 0, *arrLen - 1, &insertPos);
	if (insertPos != -1) {
		shiftDown(hotels, arrLen, insertPos);
		strcpy(hotels[insertPos], newHotel);
		printf("\"%s\" ADDED to the list!\n\n", newHotel);
	}
	else {
		printf("\"%s\" already exists in the list!\n\n", newHotel);
		return;
	}
}

int main(void) {
	FILE* file = fopen("hotels.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		char hotels[MAX][MAX];
		int hotelCount = readFromFile(file, hotels);
		bubbleSort(hotels, hotelCount);

		display(hotels, hotelCount);

		int choice;
		choice = menu();
		while (choice != 3)
		{
			switch (choice)
			{
			case 1:
				display(hotels, hotelCount);
				break;
			case 2:
				char newHotel[MAX];
				printf("Enter the hotel name: ");
				scanf(" %[^\n]", newHotel);
				addToList(hotels, newHotel, &hotelCount);
			}

			choice = menu();
		}

		fclose(file);
	}
	
	return 0;
}
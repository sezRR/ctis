#define _CRT_SECURE_NO_WARNINGS

#define MAX 150

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* str1, char* str2) {
	char temp[MAX] = "";
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

void bubbleSort(char films[MAX][MAX], int nbEl) {
	int sorted, visited = 1;
	do
	{
		sorted = 1;
		for (int i = 0; i < nbEl - visited; i++)
		{
			if (strcmp(films[i], films[i + 1]) > 0)
			{
				swap(films[i], films[i + 1]);
				sorted = 0;
			}
		}
		visited++;
	} while (!sorted);
}

void display(char films[MAX][MAX], int nbEl) {
	for (int i = 0; i < nbEl; i++)
		printf("%s\n", films[i]);
}

int main(void) {
	char films[MAX][MAX]{};
	int filmCounter = 0;
	char temp[MAX] = "";

	do
	{
		printf("Enter a movie (end to stop): ");
		scanf(" %[^\n]", temp);

		if (strcmp(temp, "end") != 0) {
			strcpy(films[filmCounter], temp);
			filmCounter++;
		}
	} while (strcmp(temp, "end") != 0);

	bubbleSort(films, filmCounter);
	display(films, filmCounter);

	return 0;
}
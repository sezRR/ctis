#define _CRT_SECURE_NO_WARNINGS

#define MAX 30

#include <stdio.h>
#include <string.h>

int readFromFile(FILE* file, char flowers[][MAX]) {
	int elC = 0;
	while (fscanf(file, " %[^\n]", flowers[elC]) != EOF)
		elC++;
	return elC;
}

void display(char flowers[][MAX], int count) {
	printf("The List of Flowers\n");
	printf("-------------------\n");
	for (int i = 0; i < count; i++)
		printf("%s\n", flowers[i]);
	printf("\n");
}

int binarySearch(char flowers[][MAX], char* search, int top, int bottom) {
	int mid;
	while (top <= bottom)
	{
		mid = (top + bottom) / 2;
		if (strcmp(flowers[mid], search) == 0)
			return mid;
		else if (strcmp(flowers[mid], search) > 0)
			bottom = mid - 1;
		else
			top = mid + 1;
	}

	return -1;
}


int main(void) {
	FILE* file = fopen("flowers.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		char flowers[MAX][MAX];
		char search[MAX];
		int elementCount = readFromFile(file, flowers);

		do
		{
			printf("Enter a flower name to search (or end to stop searching): ");
			scanf(" %[^\n]", search);

			int res = binarySearch(flowers, search, 0, elementCount);

			if (strcmp(search, "end") != 0)
			{
				if (res != -1)
					printf("%s found on the index %d in the list", search, res);
				else
					printf("%s could not be found!", search);
				printf("\n\n");
			}
		} while (strcmp(search, "end") != 0);

		fclose(file);
	}

	return 0;
}
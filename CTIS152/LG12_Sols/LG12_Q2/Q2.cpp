#define _CRT_SECURE_NO_WARNINGS

#define MAX 20

#include <stdio.h>

int readFromFile(FILE* file, int* numbs) {
	int elC = 0;
	while (fscanf(file, "%d", &numbs[elC]) != EOF)
		elC++;
	return elC;
}

int binarySearch(int* numbs, int search, int top, int bottom, int* steps) {
	int mid;
	while (top <= bottom)
	{
		(*steps)++;

		mid = (top + bottom) / 2;
		if (search == numbs[mid])
			return mid;
		else if (search < numbs[mid])
			bottom = mid - 1;
		else
			top = mid + 1;		
	}

	return -1;
}


int main(void) {
	FILE* file = fopen("courseCodes.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		int numbs[MAX], search;
		int elCount = readFromFile(file, numbs);

		printf("Enter value to find: ");
		scanf("%d", &search);

		int steps = 0;
		int res = binarySearch(numbs, search, 0, elCount - 1, &steps);

		if (res != -1)
			printf("%d is found at %d. line", search, res + 1);
		else
			printf("The number is NOT found in the courseCodes.txt");

		printf("\n%d comparisons.", steps);

		fclose(file);
	}

	return 0;
}
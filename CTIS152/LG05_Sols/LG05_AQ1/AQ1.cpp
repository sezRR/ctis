#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void readFile(FILE* file, char* arr, int r, int c) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			fscanf(file, " %c", arr + i * c + j);
}

void displayWords(char* arr, int r, int c) {
	printf("Array elements:\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%c ", *(arr + i * c + j));
		printf("\n");
	}
}

void displayWordSpecCol(char* arr, int r, int c, int inp_c) {
	for (int i = 0; i < r; i++)
		printf("%c", arr[i * c + inp_c]);
}

int main(void) {
	FILE* file = fopen("input.txt", "r");
	char* arr;

	if (file == NULL)
		printf("File could not be opened!");
	else {
		int row, col, inp_c;
		fscanf(file, "%d %d", &row, &col);
		arr = (char*)malloc(col * row * sizeof(char));

		readFile(file, arr, row, col);
		displayWords(arr, row, col);

		printf("\nEnter the column number: ");
		scanf("%d", &inp_c);
		displayWordSpecCol(arr, row, col, inp_c - 1);

		free(arr);
		fclose(file);
	}

	return 0;
}
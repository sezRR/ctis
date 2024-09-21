#define _CRT_SECURE_NO_WARNINGS

#define SIZE 8

#include <stdio.h>

int main(void)
{
	FILE* numbersFile = fopen("nums.txt", "r");

	if (numbersFile == NULL)
		printf("File could not be opened!");
	else
	{
		int arr[SIZE][SIZE];
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				fscanf(numbersFile, "%d", &arr[i][j]);

		printf("The content of the matrix is:\n");
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				printf("%3d ", arr[i][j]);

			printf("\n");
		}
	}


	return 0;
}
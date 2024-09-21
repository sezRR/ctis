#define _CRT_SECURE_NO_WARNINGS

#define SIZE 3

#include <stdio.h>

int main(void)
{
	int arr[SIZE][SIZE] = { 0 };

	printf("MAJOR DIAGONAL\n");
	printf("**************\n");
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (i == j)
				arr[i][j] = 1;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%3d ", arr[i][j]);

		printf("\n");
	}

	printf("\nMINOR DIAGONAL\n");
	printf("**************\n");
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (i == j || i + j == SIZE - 1)
				arr[i][j] = 1;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%3d ", arr[i][j]);

		printf("\n");
	}


	return 0;
}
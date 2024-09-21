#define _CRT_SECURE_NO_WARNINGS

#define SIZE 3

#include <stdio.h>

int main(void)
{
	int arr[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			printf("Enter the value for cell [%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%d ", arr[i][j]);

		printf("\n");
	}


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#define SIZE 3

#include <stdio.h>

int main(void)
{
	int arr[SIZE][SIZE] = { {48, 73, 14},
							{51, 22, 98},
							{13, 16, 27} };
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%d ", arr[i][j]);

		printf("\n");
	}

	return 0;
}
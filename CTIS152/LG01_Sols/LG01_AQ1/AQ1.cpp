#define _CRT_SECURE_NO_WARNINGS

#define SPECIFIED_COLUMN_LEN 5

#include <stdio.h>

void display(int arr[][SPECIFIED_COLUMN_LEN], int rowLen) {
	for (int i = 0; i < rowLen; i++)
	{
		for (int j = 0; j < SPECIFIED_COLUMN_LEN; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int sumOfMinor(int arr[][SPECIFIED_COLUMN_LEN], int rowLen) {
	int sum = 0;
	for (int i = 0; i < rowLen; i++)
		sum += arr[i][rowLen - i - 1];
	return sum;
}

int productOfRow(int arr[][SPECIFIED_COLUMN_LEN], int rowNumb) {
	int product = 1;
	for (int i = 0; i < SPECIFIED_COLUMN_LEN; i++)
		product *= arr[rowNumb - 1][i];
	return product;
}

int main(void) {
	FILE* file = fopen("input2.txt", "r");
	int numbers[100][SPECIFIED_COLUMN_LEN];
	int r = 0, c = 0;

	if (file == NULL)
		printf("File could not be opened!");
	else {
		while (fscanf(file, "%d", &numbers[r][c]) != EOF)
		{
			c++;
			if (c == SPECIFIED_COLUMN_LEN)
			{
				r++;
				c = 0;
			}
		}

		display(numbers, r);

		if (r == SPECIFIED_COLUMN_LEN)
			printf("\nThe sum of the elements on the Minor Diagonal is: %d", sumOfMinor(numbers, r));
		else {
			int rowNumb;
			printf("\nThe matrix is not a SQUARE matrix\nEnter the row number: ");
			scanf("%d", &rowNumb);
			printf("The product of the elements on the given row: %d", productOfRow(numbers, rowNumb));
		}

		fclose(file);
	}

	return 0;
}
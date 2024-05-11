#define _CRT_SECURE_NO_WARNINGS

#define ARR_LENGTH 5

#include <stdio.h>

int readFromFile(FILE* file, int ids[], double points[][ARR_LENGTH])
{
	int i;
	for (i = 0; i < ARR_LENGTH; i++)
	{
		fscanf(file, "%d", &ids[i]);
		for (int j = 1; j < ARR_LENGTH; j++)
			fscanf(file, "%lf", &points[i][j]);
	}

	return i + 1;
}

void display(int ids[], double points[][ARR_LENGTH])
{
	printf("ID %c R %c L %c S %c W %c ELIGIBLE %c OVERALL\n", ' ', ' ', ' ', ' ', ' ', ' ');
	printf("------------------------------------------------------------\n");

	int i, j;
	for (i = 0; i < ARR_LENGTH; i++)
	{
		double sum = 0;
		printf("%4d", ids[i]);

		for (j = 1; j < ARR_LENGTH; j++)
		{
			sum += points[i][j];
			printf("%6.2f", points[i][j]);
		}
		
		int counter = j - 1;
		if (sum / counter >= 6.5)
			printf("%4c", 'Y');
		else
			printf("%4c", 'N');

		printf("%7.2f\n", sum / counter);
	}
}

int main(void)
{
	FILE* ieltsFile = fopen("ielts.txt", "r");

	if (ieltsFile == NULL)
		printf("File could not be opened!");
	else 
	{
		int ids[ARR_LENGTH];
		double points[ARR_LENGTH][ARR_LENGTH];

		readFromFile(ieltsFile, ids, points);
		display(ids, points);
	}

	return 0;
}
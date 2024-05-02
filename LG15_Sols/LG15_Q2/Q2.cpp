#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LENGTH 99

#include <stdio.h>

int findMax(int distArr[], int* maxIndex)
{
	int greatest = 0;
	for (int i = 1; i < 10; i++)
	{
		if (distArr[i] > greatest)
		{
			greatest = distArr[i];
			*maxIndex = i;
		}
	}

	return greatest;
}

void display(int distArr[])
{
	printf("GRADE FREQUENCY\n");
	printf("----  --------\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("%3d  %5d\n", i, distArr[i - 1]);
	}
}

int main(void)
{
	FILE* gradesFile = fopen("grades.txt", "r");
	int greatest = 0;

	if (gradesFile == NULL)
		printf("File could not be opened!");
	else
	{
		int temp, i = 0;
		int grades[MAX_ARR_LENGTH];
		int distribution[10]{ 0 };
		while (fscanf(gradesFile, "%d", &grades[i]) != EOF)
		{
			distribution[grades[i] - 1] += 1;
			i++;
		}

		int index = 0;
		greatest = findMax(distribution, &index);
		display(distribution);
		printf("Most of the students(%d students) have got the grade %d", greatest, index + 1);
	}

	return 0;
}
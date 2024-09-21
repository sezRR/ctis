#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Define variables
	int i = 1, // control variable
		grade, // grade input
		maxGrade = -1,
		minGrade = 999;

	// Get inputs from the user
	printf("Enter grades (a negative value to stop): \n");
	scanf("%d", &grade);
	while (grade >= 0)
	{
		if (grade > maxGrade)
			maxGrade = grade;

		if (grade < minGrade)
			minGrade = grade;

		scanf("%d", &grade);
	}

	printf("\nMaximum grade: %d", maxGrade);
	printf("\nMinimum grade: %d", minGrade);

	return 0;
}
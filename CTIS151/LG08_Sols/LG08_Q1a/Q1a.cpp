#define _CRT_SECURE_NO_WARNINGS

#define COUNT_GRADE_INPUT 5

#include <stdio.h>

int main(void)
{
	// Define variables
	int i, // control variable
		grade, // grade input
		maxGrade = -1,
		minGrade = 999;

	// Get inputs from the user
	for (i = 1; i <= COUNT_GRADE_INPUT; i++)
	{
		printf("Enter the grade: ");
		scanf("%d", &grade);

		if (grade > maxGrade)
			maxGrade = grade;

		if (grade < minGrade)
			minGrade = grade;
	}

	printf("\nMaximum grade: %d", maxGrade);
	printf("\nMinimum grade: %d", minGrade);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void input(int *arr, int gradeCount) {
	int elCounter = 0;
	printf("Enter %d grades: ", gradeCount);

	for (int i = 0; i < gradeCount; i++)
		scanf("%d", &*(arr + i));
}

double findGrade(int *arr, int arrSize) {
	double sum = 0;
	for (int i = 0; i < arrSize; i++)
		sum += *(arr + i);

	return sum * (40.0 / 100);
}

int main(void) {
	int *arr, arrSize;

	while (1)
	{
		printf("How many grades? ");
		scanf("%d", &arrSize);

		if (arrSize <= 0)
			break;

		arr = (int*)malloc(arrSize * sizeof(int));

		input(arr, arrSize);
		double avg = findGrade(arr, arrSize);

		printf("The 40%% of the total grade: %.2f\n\n", avg);

		free(arr);
	}


	return 0;
}
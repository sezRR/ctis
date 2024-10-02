#define _CRT_SECURE_NO_WARNINGS

#define ARR_SIZE 10

#include <stdio.h>

int readList(FILE* file, int arr[]) {
	int elCount = 0;
	while (fscanf(file, "%d", &(*(arr + elCount++))) != EOF)
		continue;
	return elCount;
}

void findMinMax(int arr[], int* min, int* max, int arrLen) {
	for (int i = 0; i < arrLen - 1; i++)
		if (*min > *(arr + i))
			*min = *(arr + i);
		else if (*max < *(arr + i))
			*max = *(arr + i);
}

double findAvgExcMinMax(int arr[], int min, int max, int arrLen) {
	double sum = 0;
	for (int i = 0; i < arrLen - 1; i++)
		if (*(arr + i) != min && *(arr + i) != max)
			sum += *(arr + i);

	return sum / (arrLen - 3);
}

int main(void) {
	FILE* numbersFile = fopen("numbers.txt", "r");
	int arr[ARR_SIZE], min = 999999, max = -9999999;

	if (numbersFile == NULL)
		printf("File could not be opened!");
	else {
		int len = readList(numbersFile, arr);
		findMinMax(arr, &min, &max, len);
		double avg = findAvgExcMinMax(arr, min, max, len);
		printf("Min value: %d\n", min);
		printf("Max value: %d\n\n", max);
		printf("Average excluding the min and max value: %.2f", avg);
		fclose(numbersFile);
	}

	return 0;
}
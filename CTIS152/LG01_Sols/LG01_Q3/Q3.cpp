#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int fillArray(int arr[]) {
	int numb = 0, i = 0;
	while (numb >= 0)
	{
		printf("Enter a positive number: ");
		scanf("%d", &numb);
		arr[i] = numb;
		i += 1;
	}

	return i;
}

double findEvenAverage(int arr[], int elLen) {
	double sumEven = 0, evenCount = 0;
	for (int i = 0; i < elLen; i++)
	{
		if (arr[i] % 2 == 0) {
			sumEven += arr[i];
			evenCount++;
		}
	}

	if (evenCount == 0) {
		printf("No even numbers in the array");
		return -1;
	}


	return sumEven / evenCount;
}

int main(void) {
	int arr[256];

	int i = fillArray(arr);

	if (i == 1) {
		printf("cannot calculate, please enter positive number");
		return 1;
	}

	double avg = findEvenAverage(arr, i);
	if (avg != -1)
		printf("Average of even numbers: %.2f", avg);

	return 0;
}
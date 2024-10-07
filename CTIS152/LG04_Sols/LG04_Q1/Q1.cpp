#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void readList(int arrLen, int *arr) {
	printf("Enter list elements:\n");
	for (int i = 0; i < arrLen; i++)
		scanf("%d", &(*(arr + i)));
}

void findSumPro(int *arr, int arrLen, int *sum, int *product) 
{
	for (int i = 0; i < arrLen; i++) {
		*sum += *(arr + i);
		*product *= *(arr + i);
	}
}

int compareSumPro(int *arr, int arrLen) {
	int sum = 0, product = 1;
	findSumPro(arr, arrLen, &sum, &product);

	if (sum == product)
		return 0;
	else if (sum > product)
		return 1;
	else if (product > sum)
		return 2;
}

int main(void) {
	int arrLen, *arr;

	printf("Enter the number of values you want to input: ");
	scanf("%d", &arrLen);

	arr = (int*)malloc(arrLen * sizeof(int));

	readList(arrLen, arr);
	int result = compareSumPro(arr, arrLen);

	printf("The sum of the elements is ");
	switch (result)
	{
	case 0:
		printf("EQUAL to the product of the elements!");
		break;
	case 1:
		printf("GREATER than the product of the elements!");
		break;
	case 2:
		printf("LESS than the product of the elements!");
	}

	return 0;
}
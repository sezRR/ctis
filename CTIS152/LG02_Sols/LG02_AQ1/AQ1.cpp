#define _CRT_SECURE_NO_WARNINGS

#define MAX_ARR_LEN 100

#include <stdio.h>

int readFromFile(FILE* file, int* arr) {
	int arrLen = 0;

	while (fscanf(file, "%d", &(*(arr + arrLen))) != EOF)
		arrLen++;

	return arrLen;
}

void display(int* arr, int len) {
	printf("The list of numbers in the file:\n\t");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

bool isPerfect(int number) {
	int sumDivisors = 1;
	for (int i = 2; i <= number / 2; i++)
		if (number % i == 0)
			sumDivisors += i;

	return sumDivisors == number;
}

int findPerfect(int* numbers, int lenArrNumbers, int* perfectNumsArr) {
	int numOfPerfectNumbs = 0;

	for (int i = 0; i < lenArrNumbers; i++)
		if (isPerfect(numbers[i])) {
			*(perfectNumsArr + numOfPerfectNumbs) = *(numbers + i);
			numOfPerfectNumbs++;
		}

	return numOfPerfectNumbs;
}

void writeToFile(FILE* file, int* perfectNums, int perfectNumsLen) {
	for (int i = 0; i < perfectNumsLen; i++)
		fprintf(file, "%d ", *(perfectNums + i));
}

int main(void) {
	FILE* numbersFile = fopen("numbersAQ1.txt", "r");
	FILE* perfectNumbersFile = fopen("perfect.txt", "w");
	int numbers[MAX_ARR_LEN], perfectNums[MAX_ARR_LEN];

	if (numbersFile == NULL || perfectNumbersFile == NULL)
		printf("File(s) could not be opened!");
	else {
		int numbersArrLen = readFromFile(numbersFile, numbers);
		display(numbers, numbersArrLen);

		int perfectNumsArrLen = findPerfect(numbers, numbersArrLen, perfectNums);
		printf("There are %d numbers in the array, %d of them are perfect numbers", numbersArrLen, perfectNumsArrLen);
		writeToFile(perfectNumbersFile, perfectNums, perfectNumsArrLen);
	}

	return 0;
}
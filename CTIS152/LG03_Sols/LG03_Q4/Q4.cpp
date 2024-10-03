#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

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

bool isPrime(int number) {
	for (int i = 2; i <= number / 2; i++)
		if (number % i == 0)
			return false;

	return true;
}

int findPrime(int* numbers, int lenArrNumbers, int* primeNumsArr) {
	int numOfPrimeNumbs = 0;

	for (int i = 0; i < lenArrNumbers; i++)
		if (isPrime(numbers[i]))
			*(primeNumsArr + numOfPrimeNumbs++) = *(numbers + i);

	return numOfPrimeNumbs;
}

void writeToFile(FILE* file, int* primeNums, int primeNumsLen) {
	for (int i = 0; i < primeNumsLen; i++)
		fprintf(file, "%d ", *(primeNums + i));
}

int main(void) {
	FILE* numbersFile = fopen("numbers.txt", "r");
	FILE* perfectNumbersFile = fopen("perfect.txt", "w");
	int *numbers, *primeNums;

	if (numbersFile == NULL || perfectNumbersFile == NULL)
		printf("File(s) could not be opened!");
	else {
		int numbersArrLen = 0;
		fscanf(numbersFile, "%d", &numbersArrLen);

		numbers = (int*)malloc(numbersArrLen * sizeof(int));
		primeNums = (int*)malloc(numbersArrLen * sizeof(int));

		readFromFile(numbersFile, numbers);

		display(numbers, numbersArrLen);
		int perfectNumsArrLen = findPrime(numbers, numbersArrLen, primeNums);

		printf("There are %d numbers in the array, %d of them are prime numbers", numbersArrLen, perfectNumsArrLen);
		writeToFile(perfectNumbersFile, primeNums, perfectNumsArrLen);

		free(numbers);
	}

	return 0;
}
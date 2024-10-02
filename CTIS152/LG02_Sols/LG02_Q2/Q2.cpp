#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 6

#include <stdio.h>

int main(void) {
	FILE* numbersFile = fopen("numbers.txt", "r");
	FILE* sequenceFile = fopen("sequence.txt", "w");
	int arr[ARR_SIZE];

	if (numbersFile == NULL || sequenceFile == NULL)
		printf("File could not be opened!");
	else {
		for (int i = 0; i < ARR_SIZE; i++)
			fscanf(numbersFile, "%d", &arr[i]);

		fprintf(sequenceFile, "Element Name\tValue\tAddress\n");
		fprintf(sequenceFile, "------------\t-----\t-------\n");
		for (int i = 0; i < ARR_SIZE; i++)
			fprintf(sequenceFile, "*(nums + %d)\t%d\t%p\n", i, *(arr + i), arr + i);
		printf("Successful! Please see the sequence.txt file for the output.");
	}

	return 0;
}
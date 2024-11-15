#define _CRT_SECURE_NO_WARNINGS

constexpr char BIN_FILE[11] = "output.bin";
constexpr int MAX = 50;

#include <stdio.h>
#include <stdlib.h>
#include "BinFileUtil.h"

void readAndPrint(FILE* binFile, int insertedElements, bool rewindAfterPrint = false);
size_t readAndAssign(FILE* binFile, int max, int* assignTo, bool rewindAfterPrint = false);
void checkRewind(FILE* binFile, bool isRewindRequested);
int readAndAssignDemo(FILE* binFile, int insertedElements);
int findAndReturnNthNumber(FILE* binFile, int nthElement);

int main(void) {
	FILE* outputFile = fopen(BIN_FILE, "wb");
	int insertedElements = createSeedBinFile(outputFile);

	FILE* binFile = fopen(BIN_FILE, "rb");
	if (binFile == NULL)
		printf("File could not be opened!");
	else {
		readAndPrint(binFile, insertedElements, true);

		int status = readAndAssignDemo(binFile, insertedElements);
		if (status == 1)
			return 1;

		int nthElement = 5;
		int result = findAndReturnNthNumber(binFile, nthElement); // Expected 5
		if (result == -1)
			return 1;
		printf("Element Found!\n%dth element is: %d", nthElement, result);

		fclose(binFile);
	}
}

void readAndPrint(FILE* binFile, int insertedElements, bool rewindAfterPrint) {
	int tempNum;
	for (int i = 0; i < insertedElements; i++)
	{
		fread(&tempNum, sizeof(int), 1, binFile);
		printf("%d\n", tempNum);
	}

	checkRewind(binFile, rewindAfterPrint);
}

size_t readAndAssign(FILE* binFile, int max, int* assignTo, bool rewindAfterPrint) {
	size_t actualRead = fread(assignTo, sizeof(int), max, binFile);
	checkRewind(binFile, rewindAfterPrint);

	return actualRead;
}

void checkRewind(FILE* binFile, bool isRewindRequested) {
	if (isRewindRequested) {
		rewind(binFile);
		printf("\nINFO -> binFile rewinded!\n");
	}
}

int readAndAssignDemo(FILE* binFile, int insertedElements)
{
	int* numbers = (int*)malloc(insertedElements * sizeof(int));
	if (numbers == NULL)
	{
		printf("Numbers array cannot be allocated with malloc! Exiting...");
		return 1;
	}

	size_t actualNumbersSize = readAndAssign(binFile, MAX, numbers, true);
	printf("Actual Size (MAX: %d): %zu\n", MAX, actualNumbersSize);

	for (size_t i = 0; i < actualNumbersSize; i++)
		printf("%d\n", *(numbers + i));

	free(numbers);

	return 0;
}

int findAndReturnNthNumber(FILE* binFile, int nthElement)
{
	fseek(binFile, (nthElement - 1) * sizeof(int), SEEK_SET);

	int element;
	size_t res = fread(&element, sizeof(int), 1, binFile);
	if (res != 1)
		return -1;

	return element;
}

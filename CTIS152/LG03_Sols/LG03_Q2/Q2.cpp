#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void) {
	FILE* outputFile = fopen("result.txt", "w");
	int arr[3][3], c = 1;

	if (outputFile == NULL)
		printf("File could not be opened!");
	else {
		fprintf(outputFile, "Element Name\t\tValue\t\tAddress\n");
		fprintf(outputFile, "------------\t\t-----\t\t--------\n");
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				fprintf(outputFile, "*(*(arr + %d) + %d)\t%.2f\t\t%p\n", i, j, pow(3, c++), *(arr + i) + j);
		printf("Successful! Please see the result.txt file for the output.");
	}

	return 0;
}
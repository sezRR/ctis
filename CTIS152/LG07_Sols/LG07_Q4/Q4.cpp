#define _CRT_SECURE_NO_WARNINGS

#define MAX_STR_LEN 12

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE* inputFile = fopen("input.txt", "r");
	FILE* outputFile = fopen("output.txt", "w");

	if (inputFile == NULL)
		printf("File(s) could not be opened!");
	else {
		char tempStr[50];
		int freqWordLen[13] = { 0 };
		while (fscanf(inputFile, "%s", &tempStr) != EOF)
			freqWordLen[strlen(tempStr)]++;

		fprintf(outputFile, "Word length \t Occurrences\n");
		fprintf(outputFile, "----------------------------\n");
		for (int i = 1; i <= MAX_STR_LEN; i++)
			if (freqWordLen[i] != 0)
				fprintf(outputFile, "%d \t\t\t %d \n", i, freqWordLen[i]);

		fclose(inputFile);
		fclose(outputFile);
	}

	return 0;
}
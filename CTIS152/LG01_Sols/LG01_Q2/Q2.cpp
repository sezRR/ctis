#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	FILE* outputFile = fopen("reverse.txt", "w");
	int numberToGenerate;

	if (outputFile == NULL)
	{
		printf("File could not be opened!");
	}
	else {
		printf("How many numbers will you generate: ");
		scanf("%d", &numberToGenerate);
		printf("%d numbers and their digits in reverse order were written to reverse.txt file", numberToGenerate);

		srand(time(NULL));

		fprintf(outputFile, "Generated number\tDigits in reverse order\n");
		fprintf(outputFile, "****************\t***********************\n");

		for (int i = 0; i < numberToGenerate; i++)
		{
			int generatedNumb = rand() % ((666 + 1) - 101) + 101;
			fprintf(outputFile, "%16d\t", generatedNumb);

			int reversedNumber = 0;
			while (generatedNumb != 0)
			{
				fprintf(outputFile, "%d\t", generatedNumb % 10);
				generatedNumb /= 10;
			}
			fprintf(outputFile, "\n");
		}
	}


	return 0;
}
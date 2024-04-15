#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare variables
	FILE *sentencesFile = fopen("sentence.txt", "r");
	FILE *outputFile = fopen("output.txt", "w");

	int linesCounter = 1, letterCounter = 0, wordsCounter = 0;
	char tempChar;

	// Check that is file exists
	if (sentencesFile == NULL)
		printf("File could not opened.");
	else
	{
		int status;
		status = fscanf(sentencesFile, "%c", &tempChar);

		while (1)
		{
			switch (tempChar)
			{
			case ' ':
				fprintf(outputFile, " %d\n", letterCounter);
				letterCounter = 0;
				wordsCounter++;

				break;
			case '\n':
				fprintf(outputFile, " %d\n", letterCounter);
				letterCounter = 0;

				printf("%d. line --> %d words\n", linesCounter++, ++wordsCounter);
				wordsCounter = 0;
				break;
			default:
				if (status == EOF) break;

				fprintf(outputFile, "%c", tempChar);
				letterCounter++;
			}

			if (status == EOF) {
				fprintf(outputFile, " %d\n", letterCounter);
				letterCounter = 0;
				wordsCounter++;
				printf("%d. line --> %d words\n", linesCounter, wordsCounter);
				break;
			}

			status = fscanf(sentencesFile, "%c", &tempChar);
		}

		fclose(sentencesFile);
	}

	return 0;
}
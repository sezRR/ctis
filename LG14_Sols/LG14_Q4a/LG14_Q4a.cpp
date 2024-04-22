#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Declare the variables
	FILE *sentenceFile = fopen("sentence.txt", "r");
	FILE *reverseAFile = fopen("reverseA.txt", "w");

	char words[56];
	int letterCounter = 0;

	if (sentenceFile == NULL)
		printf("File could not opened!");
	else 
	{
		while (fscanf(sentenceFile, "%c", &words[letterCounter]) != EOF)
		{
			letterCounter++;
		}

		for (int i = letterCounter; i > 0; i--)
		{
			fprintf(reverseAFile, "%c", &words[i]);
		}

		fclose(sentenceFile);
		fclose(reverseAFile);
	}

	return 0;
}
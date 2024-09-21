#define _CRT_SECURE_NO_WARNINGS

#define ARR_MAX_LENGTH 99

#include <stdio.h>

int main(void)
{
	FILE* sentenceFile = fopen("sentence.txt", "r");

	if (sentenceFile == NULL)
		printf("File could not be opened!");
	else
	{
		int wordCounter = 0;
		int word[ARR_MAX_LENGTH];

		while (fscanf(sentenceFile, "%c", ))
		{

		}
	}

	return 0;
}
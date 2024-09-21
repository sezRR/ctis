#define _CRT_SECURE_NO_WARNINGS

#define ARR_MAX_LENGTH 56

#include <stdio.h>

int main(void)
{
	FILE* sentenceFile = fopen("sentence.txt", "r");

	if (sentenceFile == NULL)
		printf("File could not be opened!");
	else 
	{
		FILE* reverseBFile = fopen("reverseB.txt", "w");

		char sentence[ARR_MAX_LENGTH];
		int wordStartIndex = 0, wordLastIndex = 0;

		for (int i = 0; i < ARR_MAX_LENGTH; i++) {
			char tempChar = fgetc(sentenceFile);
			sentence[i] = tempChar;

			if (sentence[i] != ' ' && tempChar != EOF) {
				if (i != 0 && sentence[i - 1] == ' ')
					wordStartIndex = i;
			}
			else {
				wordLastIndex = i - 1;
				for (int j = wordLastIndex; j >= wordStartIndex; j--)
					fprintf(reverseBFile, "%c", sentence[j]);

				fprintf(reverseBFile, "%c", ' ');
			}
		}

		fclose(sentenceFile);
		fclose(reverseBFile);
	}

	return 0;
}
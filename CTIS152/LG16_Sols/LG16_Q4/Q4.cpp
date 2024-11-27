#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "stack_string.h"

void reverse(stack_t* sentenceStack, char* sentence);

int main(void) {
	FILE* file = fopen("sentences.bin", "rb");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		char sentence[STR_SIZE] = "";
		char word[STR_SIZE] = "";

		stack_t s;
		initializeS(&s);
		while (fread(sentence, sizeof(char) * STR_SIZE, 1, file) == 1)
		{
			int strLen = strlen(sentence);

			int breakP = 0;
			for (int i = 0; i < strLen; i++)
			{
				while (sentence[i] != ' ')
					i++;

				strncat(word, sentence + breakP, i - breakP);

				push(&s, word);
				strcpy(word, "");

				breakP = i + 1;
			}

			printf("The Original Sentence is: %s\n", sentence);
			reverse(&s, sentence);
			printf("Reverse of the sentence is: %s\n\n", sentence);
		}

		fclose(file);
	}

	return 0;
}

void reverse(stack_t* sentenceStack, char* sentence)
{
	char tempString[STR_SIZE] = "";
	while (!isEmptyS(sentenceStack)) {
		strcat(tempString, pop(sentenceStack));
		strcat(tempString, " ");
	}
	strcpy(sentence, tempString);
}

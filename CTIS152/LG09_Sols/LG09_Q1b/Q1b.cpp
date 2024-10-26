#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirst(char* sentence, char* word) {
	int sentenceLen = strlen(sentence),
		wordLen = strlen(word);

	for (int i = 0; i < sentenceLen - wordLen; i++)
		if (strncmp(sentence + i, word, wordLen) == 0)
			return i;
	return -1;
}

void replaceFirstOccur(char* sentence, char* word, char* replaceWord, int indexFirstOccur) {
	int wordLen = strlen(word),
		replaceWordLen = strlen(replaceWord);
	strncpy(sentence + indexFirstOccur, replaceWord, replaceWordLen);
}

int main(void) {
	char sentence[200], word[20];

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string to search: ");
	scanf(" %[^\n]", word);
	
	int res = findFirst(sentence, word);
	if (res == -1)
		printf("The sentence does NOT contain the string <%s>", word);
	else {
		char replaceWord[30];
		printf("Enter a string to replace: ");
		scanf(" %[^\n]", replaceWord);

		replaceFirstOccur(sentence, word, replaceWord, res);
		printf("New form of the sentence:\n");
		printf("%s", sentence);
	}

	return 0;
}
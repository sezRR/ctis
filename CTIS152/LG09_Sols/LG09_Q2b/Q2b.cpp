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

void deleteFirst(char* sentence, char* word, int startIndex) {
	int sentenceLen = strlen(sentence),
		wordLen = strlen(word);

	char before[250] = "", after[250] = "";
	strncpy(before, sentence, startIndex);
	strcpy(after, sentence + startIndex + wordLen);

	strcpy(sentence, before);
	strcat(sentence, after);
}

void deleteAllOccur(char* sentence, char* word, int* res) {
	while (*res != -1)
	{
		deleteFirst(sentence, word, *res);
		*res = findFirst(sentence, word);
	}
}

int main(void) {
	char sentence[200], word[20];

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string: ");
	scanf("%s", word);

	int res = findFirst(sentence, word);
	if (res != -1) {
		deleteAllOccur(sentence, word, &res);
		printf("The new form of the sentence after deletion: %s", sentence);
	}
	else
		printf("The sentence does NOT contain the string <%s>", word);

	return 0;
}
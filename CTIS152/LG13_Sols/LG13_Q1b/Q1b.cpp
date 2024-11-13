#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int countOccRec(char* sentence, char* search, int pos, int sentenceLen, int searchLen) {
	if (pos >= sentenceLen)
		return 0;

	return (strncmp(sentence + pos, search, searchLen) == 0) + countOccRec(sentence, search, pos + 1, sentenceLen, searchLen);
}

int main(void) {
	char sentence[300] = "", searchWord[300] = "";
	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a word to search in the sentence: ");
	scanf(" %s", searchWord);

	int occ = countOccRec(sentence, searchWord, 0, strlen(sentence), strlen(searchWord));
	printf("\nThe word -%s- occurred %d times in the sentence", searchWord, occ);

	return 0;
}
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

int main(void) {
	char sentence[200], word[20];

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string: ");
	scanf("%s", word);

	int res = findFirst(sentence, word);
	if (res != -1)
		printf("The first occurence of the str <%s> is %d", word, res);
	else
		printf("The sentence does NOT contain the string <%s>", word);

	return 0;
}
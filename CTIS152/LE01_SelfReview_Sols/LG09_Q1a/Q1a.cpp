#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int findFirst(char* sentence, char* str) {
	int sentenceLen = strlen(sentence),
		strLen = strlen(str);

	for (int i = 0; i < sentenceLen - strLen; i++)
		if (strncmp(sentence + i, str, strLen) == 0)
			return i;

	return -1;
}

int main(void) {
	char sentence[250], str[20];

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string: ");
	scanf(" %[^\n]", str);

	int occ = findFirst(sentence, str);

	if (occ == -1)
		printf("The sentence does NOT contain the string <%s>", str);
	else
		printf("The first occurence of the str <%s> is %d", str, occ);
	
	return 0;
}
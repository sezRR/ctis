#define _CRT_SECURE_NO_WARNINGS

#define MAX 250

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

void deleteFirst(char* sentence, char* str) {
	int occ;
	do
	{
		occ = findFirst(sentence, str);
		if (occ == -1) {
			printf("Final format of the str: %s", sentence);
			return;
		}

		int wordLen = strlen(str);
		char temp[MAX] = "";
		strncpy(temp, sentence, occ);
		strcat(temp, sentence + occ + wordLen);
		strcpy(sentence, temp);
	} while (occ != -1);
}

int main(void) {
	char sentence[250] = "", str[20] = "";

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string: ");
	scanf(" %[^\n]", str);

	deleteFirst(sentence, str);

	return 0;
}
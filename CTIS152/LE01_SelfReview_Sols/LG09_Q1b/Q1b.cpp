#define _CRT_SECURE_NO_WARNINGS

#define MAX 150

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

void replaceFirstOccur(char* sentence, char* str, char* replaceStr, int firstOccIndex) {
	char before[MAX] = "", after[MAX] = "";
	int strLen = strlen(str);

	strncpy(before, sentence, firstOccIndex);
	strcat(before, replaceStr);
	strcpy(after, sentence + firstOccIndex + strLen);
	strcat(before, after);
	strcpy(sentence, before);
}

int main(void) {
	char sentence[250] = "", str[20] = "", newStr[20] = "";

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string: ");
	scanf(" %[^\n]", str);

	printf("Enter a string to replace: ");
	scanf(" %[^\n]", newStr);

	int occ = findFirst(sentence, str);

	if (occ == -1)
		printf("The sentence does NOT contain the string <%s>", str);
	else {
		replaceFirstOccur(sentence, str, newStr, occ);
		printf("\nNew form of the sentence:\n");
		printf("%s", sentence);
	}

	return 0;
}
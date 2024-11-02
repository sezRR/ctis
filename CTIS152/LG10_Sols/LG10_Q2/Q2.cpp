#define _CRT_SECURE_NO_WARNINGS

#define MAX_STR_LEN 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirstOccur(char* sentence, char* searchStr) {
	int sentLen = strlen(sentence),
		searchStrLen = strlen(searchStr),
		counter = 0;
	for (int i = 0; i < sentLen - searchStrLen; i++)
		if (strncmp(sentence + i, searchStr, searchStrLen) == 0
			&& (i == 0 || sentence[i - 1] == ' ')
			&& (i == sentLen - searchStrLen || sentence[i + searchStrLen] == ' '))
			return i;
	return -1;
}

void delAllOccur(char* sentence, char* searchStr) {
	int res = findFirstOccur(sentence, searchStr),
		searchStrLen = strlen(searchStr);
	while (res != -1)
	{
		char bef[MAX_STR_LEN] = "", after[MAX_STR_LEN] = "";
		strncpy(bef, sentence, res);
		strcpy(after, sentence + res + searchStrLen);
		strcpy(sentence, bef);
		strcat(sentence, after);

		res = findFirstOccur(sentence, searchStr);
	}
}

int main(void) {
	char sentence[MAX_STR_LEN], str[45];
	int occ[25];

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string: ");
	scanf(" %s", str);

	delAllOccur(sentence, str);
	printf("Final format of the sentence: %s", sentence);

	return 0;
}
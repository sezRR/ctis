#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findAllOccur(char* sentence, char* searchStr, int* occ) {
	int sentLen = strlen(sentence),
		searchStrLen = strlen(searchStr),
		counter = 0;
	for (int i = 0; i < sentLen - searchStrLen; i++)
		if (strncmp(sentence + i, searchStr, searchStrLen) == 0)
			occ[counter++] = i;

	return counter;
}

int main(void) {
	char sentence[250], str[45];
	int occ[25];

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a string: ");
	scanf(" %s", str);

	int occCount = findAllOccur(sentence, str, occ);

	printf("All occurences of the str <%s>:\n\t", str);
	for (int i = 0; i < occCount; i++)
		printf("%d ", occ[i]);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char toLower(char c) {
	if (c >= 'A' && c <= 'Z')
		c += ('a' - 'A');
	return c;
}

int countOccRec(char* sentence, char search, int i) {
	if (sentence[i] == '\0')
		return 0;

	return (toLower(sentence[i]) == toLower(search)) + countOccRec(sentence, search, i + 1);
}

int main(void) {
	char sentence[300], searchChr;
	printf("Enter a string: ");
	scanf("%[^\n]", sentence);

	printf("Enter a character: ");
	scanf(" %c", &searchChr);

	int occ = countOccRec(sentence, searchChr, 0);
	printf("\n%s\n", sentence);
	printf("The number of '%c' is %d", searchChr, occ);
	
	return 0;
}
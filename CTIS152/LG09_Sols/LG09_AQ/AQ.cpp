#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int findLastOcc(char* sentence, char* key) {
	int lenSentence = strlen(sentence),
		lenKey = strlen(key),
		res = -1;

	for (int i = lenKey; i < lenSentence; i++)
		if (strncmp(sentence + i, key, lenKey) == 0)
			res = i;

	return res;
}

int main(void) {
	char sentence[250], key[25];

	printf("Enter a sentence: ");
	scanf("%[^\n]", sentence);

	printf("Enter a key string: ");
	scanf(" %s", key);

	int res = findLastOcc(sentence, key);
	printf("Result: ");
	if (res != -1)
	{
		char temp[250] = "";
		strncpy(temp, sentence, res);
		printf("%s", temp);
	}
	else
		printf("That's an empty string, sorry.");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int myStrLen(char str[]) {
	int strLen = 0;
	while (str[strLen] != '\0')
		strLen++;

	return strLen;
}

int main(void) {
	FILE* placesFile = fopen("places.txt", "r");

	if (placesFile == NULL)
		printf("File could not be opened!");
	else {
		char tempStr[30];
		while (fscanf(placesFile, "%s", &tempStr) != EOF)
			printf("%s-%d\n", tempStr, myStrLen(tempStr));

		fclose(placesFile);
	}
	
	return 0;
}
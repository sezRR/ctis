#define _CRT_SECURE_NO_WARNINGS

#define MAX_STR_LEN 300

#include <stdio.h>
#include <string.h>

void convertToUpper(char word[]) {
	int len;
	len = strlen(word);
	for (int i = 0; i < len; i++)
		if (word[i] >= 'a' && word[i] <= 'z')
			word[i] = word[i] - ('a' - 'A');
}

int main(void) {
	char str[MAX_STR_LEN] = "";
	int wordCounter = 0;

	char tempStr[MAX_STR_LEN] = "";
	while (true)
	{
		printf("Enter a word (or END to stop): ");
		scanf("%s", tempStr);
		if (strcmp(tempStr, "END") == 0) {
			printf("You have entered %d words\n\n", wordCounter);
			break;
		}
		else {
			wordCounter++;
			convertToUpper(tempStr);
			strcat(str, tempStr);
			strcat(str, " ");
		}
	};

	printf("The sentence form in uppercase of the given words:\n");
	printf("%s", str);
	
	return 0;
}
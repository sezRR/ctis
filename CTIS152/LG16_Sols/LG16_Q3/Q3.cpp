#define _CRT_SECURE_NO_WARNINGS

#define MAX 250

#include <stdio.h>
#include <string.h>
#include "stack_char.h"

bool isLetter(char c);
void removePunct(char* sentence);
bool isPalindrome(stack_t stackSentence, char* sentence);
char toLower(char c);

int main(void) {
	FILE* file = fopen("palindrome.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		stack_t s;
		
		char sentence[MAX] = "";
		while (fscanf(file, " %[^\n]", sentence) != EOF)
		{
			initializeS(&s);

			int i = 0;
			removePunct(sentence);
			while (sentence[i] != '\0')
			{
				push(&s, sentence[i]);
				i++;
			}
			bool res = isPalindrome(s, sentence);
			if (res)
				printf("%s\n", sentence);
		}

		fclose(file);
	}
	
	return 0;
}

bool isLetter(char c) {
	if (c >= 'A' && c <= 'z')
		return 1;
	
	return 0;
}

void removePunct(char* sentence) {
    size_t strLen = strlen(sentence);
    for (size_t i = 0; i < strLen; i++) {
        if (!isLetter(sentence[i])) {
            int j = 0;
            while (sentence[i + j] != '\0' && !isLetter(sentence[i + j]))
                j++;

            char bef[MAX] = "", aft[MAX] = "";
            strncpy(bef, sentence, i);
            strcpy(aft, sentence + i + j);
            strcat(bef, aft);
            strcpy(sentence, bef);
        }
    }
}

bool isPalindrome(stack_t stackSentence, char* sentence) 
{
	int i = 0;
	while (!isEmptyS(&stackSentence))
	{
		char rP = pop(&stackSentence);
		if (toLower(sentence[i++]) != toLower(rP))
			return 0;
	}
	return 1;
}

char toLower(char c) {
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return c;
}
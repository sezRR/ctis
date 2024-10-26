#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char sentence1[125];
	printf("Enter a sentence: ");
	scanf("%s ", &sentence1);
	printf("The sentence is: %s \n\n", sentence1);

	char sentence2[125];
	printf("Enter a sentence: ");
	scanf("%[^\n] ", &sentence2);
	printf("The sentence is: %s \n\n", sentence2);

	char sentence3[125];
	printf("Enter a sentence: ");
	scanf("%[^0-9]", &sentence3);
	printf("The sentence is: %s", sentence3);

	return 0;
}
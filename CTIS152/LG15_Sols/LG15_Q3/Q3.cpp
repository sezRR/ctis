#define _CRT_SECURE_NO_WARNINGS

#define MAX 15

#include <stdio.h>
#include <string.h>
#include "stack_str.h"

int main(void) {
	FILE* binFile = fopen("words.bin", "rb");
	if (binFile == NULL)
		printf("File could not be opened!");
	else {
		stack_t stack;
		initializeS(&stack);

		while (!feof(binFile))
		{
			char str[MAX];
			fread(str, sizeof(char) * MAX, 1, binFile);

			push(&stack, str);
		}

		printf("WORDS IN REVERSE ORDER\n***********************\n");
		while (!isEmptyS(&stack)) {
			char el[MAX];
			strcpy(el, pop(&stack));
			if (strlen(el) > 5)
				printf("%s\n", el);
		}
	
		fclose(binFile);
	}
	
	return 0;
}
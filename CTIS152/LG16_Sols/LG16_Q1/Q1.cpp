#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "stack_int.h"

int main(void) {
	int numb, tempNumb;
	do
	{
		printf("Enter a number: ");
		scanf("%d", &numb);
	} while (numb < 10);

	tempNumb = numb;
	
	stack_t stack;
	initializeS(&stack);
	while (numb > 0)
	{
		push(&stack, numb % 10);
		numb /= 10;
	}

	printf("Digits of %d are ", tempNumb);
	while (!isEmptyS(&stack))
		printf("%d ", pop(&stack));
	
	return 0;
}
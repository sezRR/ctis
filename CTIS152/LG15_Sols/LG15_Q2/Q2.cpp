#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "stack_int.h"

int main(void) {
	int tempNumb;

	stack_t stack;
	initializeS(&stack);

	do
	{
		printf("Enter an odd number: ");
		scanf("%d", &tempNumb);

		if (tempNumb != -1)
		{
			do
			{
				if (tempNumb % 2 == 0)
				{
					printf("Enter odd number please: ");
					scanf("%d", &tempNumb);
				}
			} while (tempNumb % 2 == 0);

			push(&stack, tempNumb);
		}
	} while (tempNumb != -1);

	printf("Stack Content\n");
	while (!isEmptyS(&stack))
		printf("%d ", pop(&stack));

	return 0;
}
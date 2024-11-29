#define _CRT_SECURE_NO_WARNINGS

#define SENTINEL_VAL -9

#include <stdio.h>
#include <climits>
#include "stack_int.h"

void initializeStack(stack_t* s) {
	initializeS(s);

	int numb;
	while (1)
	{
		printf("Enter a number: ");
		scanf("%d", &numb);

		if (numb == SENTINEL_VAL)
			break;

		push(s, numb);
	}
}

int menu() {
	int choice;
	do
	{
		printf("\nMENU\n************************\n");
		printf("1) Count Stack\n");
		printf("2) Remove Maximum Element\n");
		printf("3) Send Nth to End\n");
		printf("4) Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice > 4);
	return choice;
}

void displayStack(stack_t s) {
	printf("\nSTACK CONTENT\n");
	while (!isEmptyS(&s))
		printf("%d\n", pop(&s));
	printf("\n");
}

int countStack(stack_t s) {
	int c = 0;
	while (!isEmptyS(&s))
	{
		pop(&s);
		c++;
	}
	return c;
}

void remMaxStack(stack_t* s) {
	stack_t tempS = *s;
	int max = INT_MIN;
	while (!isEmptyS(&tempS))
	{
		int numb = pop(&tempS);
		if (max < numb)
			max = numb;
	}

	initializeS(&tempS);
	while (!isEmptyS(s))
	{
		int numb = pop(s);
		if (numb != max)
			push(&tempS, numb);
	}

	while (!isEmptyS(&tempS))
		push(s, pop(&tempS));
}

void sendNthToEnd(stack_t* s, int n) {
	stack_t tempS = *s;
	int toBottom = INT_MIN;
	for (int i = 0; i < n; i++)
		toBottom = pop(&tempS);

	initializeS(&tempS);
	int i = 1;
	while (!isEmptyS(s)) {
		int numb = pop(s);
		if (i != n)
			push(&tempS, numb);
		i++;
	}

	initializeS(s);
	push(s, toBottom);
	while (!isEmptyS(&tempS))
		push(s, pop(&tempS));
}

int main(void) {
	stack_t s;
	initializeStack(&s);

	while (1)
	{
		int choice = menu();
		if (choice == 4)
			break;

		switch (choice)
		{
		case 1:
			displayStack(s);
			printf("Number of elements in the stack: %d\n", countStack(s));
			break;
		case 2:
			remMaxStack(&s);
			displayStack(s);

			break;
		case 3:
			int n;
			printf("\nEnter N: ");
			scanf("%d", &n);
			sendNthToEnd(&s, n);
			displayStack(s);
		}
	}

	return 0;
}
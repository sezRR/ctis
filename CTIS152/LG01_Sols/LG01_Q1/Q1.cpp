#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int* numb1, int* numb2) {
	int temp;
	temp = *numb1;
	*numb1 = *numb2;
	*numb2 = temp;
}

int main(void) {
	int numb1, numb2;

	do
	{
		printf("\nEnter first number: ");
		scanf("%d", &numb1);
		if (numb1 <= 0)
			printf("First number must be positive.");
	} while (numb1 <= 0);

	do
	{
		printf("\nEnter second number: ");
		scanf("%d", &numb2);
		if (numb2 <= 0)
			printf("Second number must be positive.");
	} while (numb2 <= 0);

	printf("\nBefore swap: a = %d, b = %d", numb1, numb2);
	swap(&numb1, &numb2);
	printf("\nBefore swap: a = %d, b = %d", numb1, numb2);

	return 0;
}
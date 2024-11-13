#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void printDigits(int num) {
	if (num == 0)
		return;

	printf("%d ", num % 10);
	printDigits(num / 10);
}

int main(void)
{
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("Digits of the number %d are:\n", num);
	printDigits(num);

	return 0;
}
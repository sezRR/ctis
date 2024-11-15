#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int isAckermann(int m, int n) {
	if (m == 0) return n + 1;

	if (m > 0 and n == 0)
		return isAckermann(m - 1, 1);
	else if (m > 0 and n > 0)
		return isAckermann(m - 1, isAckermann(m, n - 1));
}

int main(void) {
	int m, n;
	printf("Enter the value of m: ");
	scanf("%d", &m);

	printf("Enter the value of n: ");
	scanf("%d", &n);

	if (m > 4 || m < 0)
	{
		printf("\nThe value of the m had to be less than 4, and greater than 0. Exiting.");
		return 1;
	}

	if (n < 0)
	{
		printf("\nInvalid n. 'n' should be greater or equal to 0. Exiting");
		return 1;
	}

	printf("\nThe result is: %d", isAckermann(m, n));

	return 0;
}
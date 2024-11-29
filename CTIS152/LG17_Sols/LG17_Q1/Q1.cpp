#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue_int.h>

int main(void) {
	int numb;
	queue_t q;
	initializeQ(&q);

	do
	{
		printf("Enter a number (or negative to STOP): ");
		scanf("%d", &numb);
		if (numb >= 0 && numb % 6 == 0)
			insert(&q, numb);
	} while (numb >= 0);

	printf("Queue Content\n--------------------------\n");
	while (!isEmptyQ(&q))
		printf("%d\t", remove(&q));

	return 0;
}
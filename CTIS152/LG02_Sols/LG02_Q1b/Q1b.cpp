#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int arr[10] = { 35, 28, 6, 1, 66, 81, 19, 34, 99 };

	printf("%p\n", arr);
	printf("%p\n", arr + 2);
	printf("%d\n", *(arr + 2));
	printf("%d\n", *arr + 4);
	printf("%p\n", arr + 5);
	printf("%d\n", *(arr + 7));

	return 0;
}
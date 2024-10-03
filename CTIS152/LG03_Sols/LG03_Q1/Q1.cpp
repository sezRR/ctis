#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	double arr[4][3] = { { 69.11, 25.23, 48.79 }, { 81.25, 63.47, 42.14 }, { 99.1, 52.63, 38.21 }, { 11.23, 45.58, 12.49 } };

	//a
	printf("%p", arr);
	printf("\n%p", arr + 1);
	printf("\n%p", *(arr + 1));
	printf("\n%p", *(arr) + 1);
	printf("\n%.2f", *(*(arr) + 1));
	printf("\n%.2f", *(*arr + 1));
	printf("\n%.2f", *(*(arr) + 1) + 2);
	printf("\n%p", *(arr + 1) + 2);
	printf("\n%.2f", *(*(arr + 1) + 2));

	//b
	printf("\n\n%.2f", *(arr[0] + 1));
	printf("\n%.2f", *(arr[1] + 0));
	printf("\n%.2f", *(arr[0] + 1) + 2);
	printf("\n%.2f", *(arr[1] + 2));

	return 0;
}
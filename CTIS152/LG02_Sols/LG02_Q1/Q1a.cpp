#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int x = 21, y;
	int *ptr_x = &x;
	int *ptr_y;

	*ptr_x = x + 2;
	y = *ptr_x + 5;

	ptr_y = ptr_x;
	*ptr_x = x + y;
	printf("%p\n", &x);
	printf("%p\n", &y);
	printf("%p\n", ptr_x);
	printf("%d\n", *ptr_x);
	printf("%d\n", x);
	printf("%p\n", ptr_y);
	printf("%p\n", (ptr_x + 3));
	printf("%d\n", (*ptr_x + 3));

	return 0;
}
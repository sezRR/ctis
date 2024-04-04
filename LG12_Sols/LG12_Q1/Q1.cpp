#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int number = 747;
	int *ptr;
	ptr = &number;

	printf("1.Value of the variable number by using number is : %d\n", number);
	printf("2.Value of the variable number by using ptr is : %d\n", *ptr);
	printf("\n1.Address of the variable number by using number is : %p\n", &number);
	printf("2.Address of the variable number by using ptr is : %p\n", ptr);
	printf("\n1.Address of the pointer ptr by using ptr is : %p\n", &ptr);
	//printf("\n1.Value of the pointer ptr by using ptr is : %d\n", *ptr);
	printf("\n1.Value of the pointer ptr by using ptr is : %p\n", ptr);
	*ptr = 380;
	printf("\n1.Value of the variable number by using number is : %d\n", number);
	printf("2.Value of the variable number by using ptr is : %d\n", *ptr);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// SCOPE OF VARIABLES
int square(int value) {
	int number;
	number = value * value;
	return number;
}

void calcRootSquare(double number, double sRoot, double square) {
	sRoot = sqrt(number);
	square = pow(number, 2);
}

void calcRootSquare_Modified(double number, double* sRoot, double* square) {
	*sRoot = sqrt(number);
	*square = pow(number, 2);
}

void printStatusOfVariables(double number, double sRoot, double square) {
	printf("\tnumber = %.2f\n\tsquare root = %.2f\n\tsquare = %.2f\n\n", number, sRoot, square);
}

//int main(void) {
//	//// BY VALUE
//	//int total = 2512;
//	//printf("Sum is: %d", total);
//
//	//// BY REFERENCE
//	//int num1, num2;
//	//double num3;
//	//scanf("%d %d %lf", &num1, &num2, &num3);
//
//	//int number = 4;
//	//printf("Number = %d, Square = %d.\n", number, square(number));
//
//	//printf("\n\n");
//
//	//system("PAUSE");
//
//	//// CALL BY VALUE
//	//printf("CALL BY VALUE\n\n");
//	//double number = 4,
//	//	sRoot = 0,
//	//	square = 0;
//
//	//printf("Before calculation\n");
//	//printStatusOfVariables(number, sRoot, square);
//
//	//calcRootSquare(number, sRoot, square);
//
//	//printf("After calculation\n");
//	//printStatusOfVariables(number, sRoot, square);
//
//	//printf("\n\n");
//
//	//// CALL BY REFERENCE
//	//printf("CALL BY REFERENCE\n\n");
//
//	//printf("Before calculation\n");
//	//printStatusOfVariables(number, sRoot, square);
//
//	//calcRootSquare_Modified(number, &sRoot, &square);
//
//	//printf("After calculation\n");
//	//printStatusOfVariables(number, sRoot, square);
//
//	//printf("\n\n");
//
//	return 0;
//}
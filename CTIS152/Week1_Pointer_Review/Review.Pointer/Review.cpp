#include "stdio.h"

void printStatusOfVariables(int var1, int var2, int* pVar) {
	printf("\nContent of pointer = %p\n", pVar);
	printf("Content of the memory are referred by pointer = %d\n", *pVar);
}

//int main(void) {
//	int var1 = 3,
//		var2 = 5,
//		* pVar;
//
//	pVar = &var1;
//
//	printStatusOfVariables(var1, var2, pVar);
//
//	*pVar *= 2;
//
//	printStatusOfVariables(var1, var2, pVar);
//
//	pVar = &var2;
//
//	printStatusOfVariables(var1, var2, pVar);
//
//
//	return 0;
//}
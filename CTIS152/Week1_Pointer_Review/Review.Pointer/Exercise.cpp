#include "stdio.h"

void compareReturnAsc(int* numb1, int* numb2, int* numb3) {
	int temp;

	if (*numb1 > *numb2) {
		temp = *numb1;
		*numb1 = *numb2;
		*numb2 = temp;
	}

	if (*numb1 > *numb3) {
		temp = *numb1;
		*numb1 = *numb3;
		*numb3 = temp;
	}

	if (*numb2 > *numb3) {
		temp = *numb2;
		*numb2 = *numb3;
		*numb3 = temp;
	}
}

int main(void) {
	int numb1 = 1,
		numb2 = 3,
		numb3 = 2;

	compareReturnAsc(&numb1, &numb2, &numb3);

	printf("n1 = %d; n2 = %d; n3 = %d;", numb1, numb2, numb3);

	return 0;
}
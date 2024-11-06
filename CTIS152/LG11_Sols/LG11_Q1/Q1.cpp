#define _CRT_SECURE_NO_WARNINGS

#define MAX 15

#include <stdio.h>
#include <stdlib.h>

void swap(int* nb1, int* nb2) {
	int temp = *nb1;
	*nb1 = *nb2;
	*nb2 = temp;
}

int main(void) {
	FILE* file = fopen("labs.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		int numbs[MAX];

		int n = 0;
		while (fscanf(file, "%d", &numbs[n]) != EOF) {
			n++;
		}

		int sorted, visited = 1;
		do
		{
			sorted = 1;
			for (int i = 0; i < n - visited; i++)
			{
				if (numbs[i] > numbs[i + 1])
				{
					swap(&numbs[i], &numbs[i + 1]);
					sorted = 0;
				}
			}
			visited++;
		} while (!sorted);

		printf("#of pcs in labs\n**************\n");
		for (int i = 0; i < n; i++)
			printf("%d\n", numbs[i]);

		fclose(file);
	}

	return 0;
}
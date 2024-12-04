#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "stack_int.h"
#include "queue_int.h"

int main(void) {
	FILE* file = fopen("printingA.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		// INITIALIZE PC STACKS
		stack_t pc1;
		initializeS(&pc1);
		push(&pc1, 60);
		push(&pc1, 50);
		push(&pc1, 40);

		stack_t pc2;
		initializeS(&pc2);
		push(&pc2, 80);
		push(&pc2, 70);

		stack_t pc3;
		initializeS(&pc3);
		push(&pc3, 90);

		// INITIALIZE PRINTER BUFFER
		queue_t q;
		initializeQ(&q);

		char job;
		int pc, jobId;
		int printed[100], printedTotal = 0;
		while (fscanf(file, " %c", &job) != EOF)
		{
			if (job == 'S')
			{
				fscanf(file, "%d", &pc);
				switch (pc)
				{
				case 1:
					jobId = pop(&pc1);
					break;
				case 2:
					jobId = pop(&pc2);
					break;
				case 3:
					jobId = pop(&pc3);
				}
				insert(&q, jobId);
			}
			else {
				printed[printedTotal] = remove(&q);
				printedTotal++;
			}
		}

		printf("Pending jobs: ");
		while (!isEmptyQ(&q))
			printf("%d ", remove(&q));

		printf("\nrinted jobs: ");
		for (int i = 0; i < printedTotal; i++)
			printf("%d ", printed[i]);

		fclose(file);
	}
	
	return 0;
}
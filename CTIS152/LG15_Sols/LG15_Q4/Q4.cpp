#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "stack_struct.h"

int main(void) {
	FILE* file = fopen("companies.bin", "rb");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		stack_t stack;
		initializeS(&stack);

		company_t company{};
		while (fread(&company, sizeof(company_t), 1, file) == 1)
			push(&stack, company);

		int stackSize = stack.top;
		printf("Company Year \t Name \t\t Phone \t\t Web URL\n*************************************************************************** \n");
		for (int i = 0; i <= stackSize; i++)
		{
			company_t comp = pop(&stack);
			printf("%-7d \t %-7s \t %s \t %s \n",
				comp.year,
				comp.name,
				comp.phone,
				comp.webUrl
			);
		}

		fclose(file);
	}

	return 0;
}
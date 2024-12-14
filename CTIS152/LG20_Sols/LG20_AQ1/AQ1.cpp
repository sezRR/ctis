#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "linkedList_struct.h"

void displayCurrList(node_t* headP) {
	node_t* p = headP;
	while (p != NULL)
	{
		printf("%d %.2f", p->data.id, p->data.cgpa);
		p = p->next;
		printf(" -> ");
	}
	printf("NULL\n");
}

node_t* reverseLinkedList(node_t* curr, node_t* prev) {
	if (curr == NULL)
		return prev;

	node_t* temp_curr = curr;
	curr = curr->next;
	temp_curr->next = prev;
	prev = temp_curr;

	return reverseLinkedList(curr, prev);
}

int main(void) {
	FILE* binFile = fopen("students.bin", "rb");
	if (binFile == NULL)
		printf("File could not be opened!");
	else {
		node_t* headP = NULL, * p = NULL;

		student_t temp{};
		while (fread(&temp, sizeof(student_t), 1, binFile) == 1)
		{
			if (headP == NULL)
			{
				headP = addBeginning(headP, temp);
				p = headP;
			}
			else {
				addAfter(p, temp);
				p = p->next;
			}
		}

		printf("Content of the file\n");
		displayCurrList(headP);

		node_t* prev = NULL, * curr = headP;
		headP = reverseLinkedList(curr, prev);

		printf("\nReverse of the list\n");
		displayCurrList(headP);

		fclose(binFile);
	}

	return 0;
}
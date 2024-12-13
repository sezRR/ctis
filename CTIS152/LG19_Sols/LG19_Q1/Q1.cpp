#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "linkedList.h"

void displayList(node_t* head) {
	while (head != NULL) {
		printf("%d ", head->data);
		if (head->next != NULL)
			printf("-> ");
		head = head->next;
	}
	printf("-> NULL\n");
}

int main(void) {
	node_t* headP = NULL, *p;
	int temp;

	printf("Enter a number: ");
	scanf("%d", &temp);
	if (temp != -1) {
		headP = addBeginning(headP, temp);
		p = headP;

		do {
			printf("Enter a number: ");
			scanf("%d", &temp);
			if (temp != -1) {
				addAfter(p, temp);
				p = p->next;
			}
		} while (temp != -1);

		displayList(headP);
	}
	else
		printf("No numbers were entered.\n");

	return 0;
}
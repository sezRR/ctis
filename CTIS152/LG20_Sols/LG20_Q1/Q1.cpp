#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "linkedList_struct.h"

node_t *createList(FILE* file) {
	customer_t temp{};
	node_t* headP = NULL, *p;

	fscanf(file, "%d %s %d", &temp.id, temp.surname, &temp.entranceYear);
	headP = addBeginning(headP, temp);
	p = headP;
	while (fscanf(file, "%d %s %d", &temp.id, temp.surname, &temp.entranceYear) != EOF) {
		addAfter(p, temp);
		p = p->next;
	}
	return headP;
}

node_t *deletePoliciy(node_t* headP) {
	node_t* p = NULL;
	if (headP->data.entranceYear < 2020)
		headP = deleteFirst(headP, &headP->data);
	p = headP;
	while (p != NULL)
	{
		if (p->next->data.entranceYear < 2020)
			deleteAfter(p);
		p = p->next;
	}
	return headP;
}

int main(void) {
	FILE* file = fopen("policies.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		node_t* headP = createList(file);
		
		printf("Original List:\n");
		displayList(headP);

		printf("*** Policiies before year 2020 will be deleted ***\n");
		headP = deletePoliciy(headP);

		displayList(headP);

		fclose(file);
	}

	return 0;
}
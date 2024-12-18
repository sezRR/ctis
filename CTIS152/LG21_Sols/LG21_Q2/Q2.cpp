#define _CRT_SECURE_NO_WARNINGS

#define TERM_CHR '!'

#include <stdio.h>
#include <stdlib.h>
#include "linkedList_char.h"

void displayList(node_t* headP) {
	while (headP != NULL)
	{
		printf("%c ", headP->data);
		headP = headP->next;
		if (headP != NULL)
			printf("-> ");
	}
	printf("NULL\n");
}

int removeChar(node_t** headP, char ch, char* found) {
	node_t* p = NULL;
	if ((*headP)->data == ch)
	{
		*found = (*headP)->data;
		*headP = deleteFirst(*headP, &ch);
		return 1;
	}

	p = *headP;
	while (p != NULL)
	{
		if (p->data == ch)
		{
			*found = p->data;
			return 1;
		}
		p = p->next;
	}
	return 0;
}

int main(void) {
	char ch;
	node_t* headP = NULL, *p = NULL;
	do
	{
		printf("Enter a character (or %c to stop): ", TERM_CHR);
		scanf(" %c", &ch);
		if (ch != '!')
		{
			if (headP == NULL)
			{
				headP = addBeginning(headP, ch);
				p = headP;
			}
			else {
				addAfter(p, ch);
				p = p->next;
			}
		}
	} while (ch != '!');

	displayList(headP);

	char toDel;
	printf("\nEnter a char to delete: ");
	scanf(" %c", &toDel);

	char info;
	int res = removeChar(&headP, toDel, &info);
	displayList(headP);
	
	return 0;
}
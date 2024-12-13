#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "linkedList_string.h"

void displayList(node_t* head) {
	node_t* p = head;
	while (p != NULL) {
		printf("%s ", p->data);
		if (p->next != NULL)
			printf("-> ");
		p = p->next;
	}
	printf("-> NULL\n");
}

node_t* createList(void) {
	node_t* headP = NULL, *p;

	char str[STR_MAX] = "";

	printf("Enter a word: ");
	scanf("%s", str);
	if (strcmp(str, "end") != 0)
	{
		headP = addBeginning(headP, str);
		p = headP;
		while (strcmp(str, "end") != 0)
		{
			printf("Enter a word: ");
			scanf("%s", str);
			if (strcmp(str, "end") != 0)
			{
				addAfter(p, str);
				p = p->next;
			}
		}
	}

	return headP;
}

node_t* findLongest(node_t* headP) {
	node_t* p = headP;
	node_t* max = headP;
	while (p != NULL)
	{
		if (strcmp(max->data, p->data) < 0)
			max = p;
		p = p->next;
	}
	return max;
}

int main(void) {
	node_t* headP = createList();
	displayList(headP);

	char insertStr[STR_MAX] = "";
	printf("Enter a word to insert after the longest word: ");
	scanf("%s", insertStr);

	node_t* longestNodeP = findLongest(headP);
	printf("The longest word in the list is: %s\n", longestNodeP->data);

	node_t* newInsertNode = getnode();
	strcpy(newInsertNode->data, insertStr);
	newInsertNode->next = longestNodeP->next;
	longestNodeP->next = newInsertNode;

	displayList(headP);


	return 0;
}
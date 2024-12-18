#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "linkedList_str.h"

node_t* searchInsertPos(node_t* headP, char* insertEl) {
	node_t* p = headP;
	while (p != NULL && p->next != NULL)
	{
		if (strcmp(insertEl, p->data) > 0 && strcmp(insertEl, p->next->data) < 0)
			break;
		else if (strcmp(insertEl, p->data) < 0)
			return NULL;
		p = p->next;
	}
	return p;
}

void displayList(node_t* headP) {
	while (headP != NULL)
	{
		printf("%s ", headP->data);
		headP = headP->next;
		if (headP != NULL)
			printf("-> ");
	}
	printf("-> NULL\n");
}

node_t* createList(FILE* file) {
	node_t* headP = NULL, *p = NULL;

	char str[MAX_STR] = "";
	while (fscanf(file, "%s", str) != EOF)
	{
		node_t* insertAfter = searchInsertPos(headP, str);
		if (insertAfter == NULL)
			headP = addBeginning(headP, str);
		else
			addAfter(insertAfter, str);
		displayList(headP);
	}

	fclose(file);
	return headP;
}

int removeWord(node_t** headP, char* word) {
	int wordLen = strlen(word);
	int isDeleted = 0;

	while (strncmp((*headP)->data, word, wordLen) == 0) {
		*headP = deleteFirstNode(*headP);
		isDeleted = 1;
	}

	node_t* p = *headP;
	while (p->next != NULL) {
		if (strcmp(p->next->data, word) == 0 || strncmp(p->next->data, word, wordLen) == 0) {
			deleteNodeAfter(p);
			isDeleted = 1;
		}
		else {
			p = p->next;
		}
	}

	return isDeleted;
}


int main(void) {
	FILE* file = fopen("words.txt", "r");
	if (file == NULL)
		printf("File could not be opened!");
	else {
		node_t* headP = createList(file);

		char strToDel[MAX_STR] = "";
		printf("\nEnter a string to delete: ");
		scanf(" %s", strToDel);

		int res = removeWord(&headP, strToDel);

		if (res == 0)
			printf("There is NO word which starts with the string <%s>", strToDel);
		else
			displayList(headP);
	}

	return 0;
}
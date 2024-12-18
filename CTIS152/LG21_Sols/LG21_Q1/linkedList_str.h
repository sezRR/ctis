#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 50

typedef char LType;

typedef struct node_s
{
	LType data[MAX_STR];
	struct node_s *next;
} node_t;

node_t *getnode(void)
{
	node_t *node;
	node = (node_t *)malloc(sizeof(node_t));
	node->next = NULL;
	return (node);
}
void addAfter(node_t *p, LType* item)
{
	node_t *newp;
	newp = getnode();
	strcpy(newp->data, item);
	newp->next = p->next;
	p->next = newp;
}
node_t *addBeginning(node_t *headp, LType* item)
{
	node_t *newp;
	newp = getnode();
	strcpy(newp->data, item);
	newp->next = headp;
	return (newp);
}

void deleteNodeAfter(node_t* node) {
	node_t* temp = node->next;
	node->next = temp->next;
	free(temp);
}

node_t* deleteFirstNode(node_t* headP) {
	node_t* del;
	del = headP;
	headP = del->next;
	free(del);
	return (headP);
}
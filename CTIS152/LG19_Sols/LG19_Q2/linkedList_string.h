#include<stdio.h>
#include<stdlib.h>

#define STR_MAX 100

typedef char LType[STR_MAX];

typedef struct node_s
{	LType data;
	struct node_s *next; 
} node_t;

node_t *getnode (void)
{
	node_t *node;
	node = (node_t *) malloc (sizeof(node_t));
	node->next = NULL;
	return (node);
}
void addAfter (node_t *p, LType item)
{
	node_t *newp;
	newp = getnode();
	strcpy(newp->data, item);
	newp->next = p->next;
	p->next = newp;
}
node_t *addBeginning (node_t *headp, LType item)
{	
	node_t *newp;
	newp = getnode();	
	strcpy(newp->data, item);
	newp->next = headp;
	return (newp);
}
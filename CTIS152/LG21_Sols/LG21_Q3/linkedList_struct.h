#include<stdlib.h>
#define SIZE 50

#define CRS_T_AEROBICS 1
#define CRS_T_ZUMBA 2
#define CRS_T_PILATES 3

typedef struct {
	int courseId;
	char courseName[SIZE];
	char duration[SIZE];
}course_t;

typedef course_t LType;

typedef struct node_s
{	LType data;
	struct node_s *next; 
} node_t;

node_t *getnode(void)
{
	node_t *node;
	node = (node_t *)malloc(sizeof(node_t));
	node->next = NULL;
	return (node);
}

void addAfter(node_t *p, LType item)
{
	node_t *newp;
	newp = getnode();
	newp->data = item;
	newp->next = p->next;
	p->next = newp;
}

node_t *addBeginning(node_t *headp, LType item)
{
	node_t *newp;
	newp = getnode();
	newp->data = item;
	newp->next = headp;
	return (newp);
}
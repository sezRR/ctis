/* Linked List Library */

typedef char LType;

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
	newp->data = item;
	newp->next = p->next;
	p->next = newp;
}

node_t *addBeginning (node_t *headp, LType item)
{	
	node_t *newp;
	newp = getnode();	
	newp->data = item;
	newp->next = headp;
	return (newp);
}

void deleteAfter(node_t *p, LType *item)
{
	node_t *del;
	/* remember the address of the node you want to delete,
	 thus the node after p */
	del = p->next;
	/* store the data in the node you want to delete in
	 *item */
	*item = del->data;
	/* form the new links. link the node before the one to
	 be deleted to the node that comes after it. */
	p->next = del->next;
	/* delete the node from the memory */
	free(del);
}

node_t *deleteFirst(node_t *headp, LType *item) {
	node_t *del;
	/* Remember the address of the first node */
	del = headp;
	/* Store the data in the first node in *item */
	*item = del->data;
	/* Form the new links. HEAD must point to the second
	 node. */
	headp = del->next;
	/* Delete the first node from the memory */
	free(del);
	return (headp);
}

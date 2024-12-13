#define SIZE 20

typedef struct {
	char userName[SIZE];
	char city[SIZE];
	char lastLogin[SIZE];
}login_t;

typedef login_t LType;

typedef struct node_s
{
	LType data;
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

node_t *deleteFirst(node_t *headp) 
{
	node_t *del;
	del = headp;
	headp = del->next;
	free(del);
	return (headp);
}

void deleteAfter(node_t *p)
{
	node_t *del;
	del = p->next;

	p->next = del->next;
	
	free(del);
}

//function that displays the list
void displayList(node_t *headp)
{
	node_t *p;

	if (headp == NULL)
		printf("\nThe List is EMPTY !!!\n\n");
	else
	{
		printf("\nUser Name       City            Last Login\n");
		printf("***********     ********        ****************\n");

		p = headp;
		while (p != NULL)
		{
			printf("%-15s %-15s %-15s ->\n", p->data.userName, p->data.city, p->data.lastLogin);
			p = p->next;
		}
		printf("NULL\n");
	}
}
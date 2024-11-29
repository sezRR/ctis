//
// Stack Implementation, CTIS 152
//
#define STACK_SIZE  100
#define MAX_STR_SIZE 20
#define MAX_TEAM 3
#define TEAM_CODE_PREFIX 5000

typedef struct {
	int code;
	char name[MAX_STR_SIZE];
	char project[MAX_STR_SIZE];
} team_t;

typedef struct {
	char name[MAX_STR_SIZE];
	double profit;
	int teamCodes[MAX_TEAM];
} project_t;

typedef  project_t  SType;

SType  STACK_EMPTY = { "", 0, {} };

typedef struct
{	int	top;
	SType data[STACK_SIZE];
} stack_t;

//Functions in this file...
void initializeS (stack_t *s);
int isEmptyS (stack_t *s);
int isFullS (stack_t *s);
void push (stack_t *s, SType item);
SType pop (stack_t *s);

//------------------------------------------------------------------------------

void initializeS (stack_t *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int isEmptyS (stack_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int isFullS (stack_t *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push (stack_t *s, SType item)
{
	if (isFullS (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
		
	}
}

//------------------------------------------------------------------------------

SType pop (stack_t *s)
{
	SType item;
	if (isEmptyS(s))
	{	printf("\nSorry stack is empty!\n\n");
		item = STACK_EMPTY;	
	}
	else
	{	item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}

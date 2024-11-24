//
// Stack Implementation, CTIS 152
//
#define STACK_SIZE  100

#define MAX_SIZE_1 15
#define MAX_SIZE_2 50

typedef struct {
	int year;
	char name[MAX_SIZE_1];
	char phone[MAX_SIZE_1];
	char webUrl[MAX_SIZE_2];
} company_t;

typedef  company_t  SType;

SType  STACK_EMPTY = { -1, "", "", "" };

typedef struct
{
	int	top;
	SType data[STACK_SIZE];
} stack_t;

//Functions in this file...
void initializeS(stack_t* s);
int isEmptyS(stack_t* s);
int isFullS(stack_t* s);
void push(stack_t* s, SType item);
SType pop(stack_t* s);

//------------------------------------------------------------------------------

void initializeS(stack_t* s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int isEmptyS(stack_t* s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int isFullS(stack_t* s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push(stack_t* s, SType item)
{
	if (isFullS(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;

	}
}

//------------------------------------------------------------------------------

SType pop(stack_t* s)
{
	SType item;
	if (isEmptyS(s))
	{
		printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;
	}
	else
	{
		item = s->data[s->top];
		(s->top)--;
	}
	return (item);
}

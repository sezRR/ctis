
//
// Stack Implementation, CTIS 152
//
#define STACK_SIZE  100
#define STR_SIZE 100

typedef  char  SType;

SType STACK_EMPTY[STR_SIZE] = " ";

typedef struct
{
	int	top;
	SType data[STACK_SIZE][STR_SIZE];
} stack_t;

//Functions in this file...
void initializeS(stack_t* s);
int isEmptyS(stack_t* s);
int isFullS(stack_t* s);
void push(stack_t* s, SType* item);
SType* pop(stack_t* s);

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

void push(stack_t* s, SType* item)
{
	if (isFullS(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		strcpy(s->data[s->top], item);
	}
}

//------------------------------------------------------------------------------

SType* pop(stack_t* s)
{
	SType item[STR_SIZE];
	if (isEmptyS(s))
	{
		printf("Error: Stack is empty!\n");
		strcpy(item, STACK_EMPTY);
	}
	else
	{
		strcpy(item, s->data[s->top]);
		(s->top)--;
	}
	return (item);
}

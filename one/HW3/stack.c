#include "stack.h"

//======================================================================================
//
// Function: stackInit
// Description: initiates the stack and initializes values, and sets array to NAN
// Arguments: none
// Return value: returns the pointer to a stack
//
//======================================================================================
struct Stack* stackInit()
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = 0;
	stack->bottom = -1;
  for(int i = 0; i < MAXSIZE; i++)
	 stack->data[i] = NAN;
	return stack;
}
//======================================================================================
//
// Function: Push
// Description: pushes a value into the stack
// Arguments: a stack pointer and a double
// Return value: bool values, true if successful
//
//======================================================================================
static int push(struct Stack* Stack, double d)
{
	if (isFull(Stack) == 0)
	{
		Stack->data[Stack->top] = d;
		Stack->top++;
		return 1;
	}
	else
		return 0;
}
//======================================================================================
//
// Function: Pop
// Description: removes an item of the stack  LIFO and shows what it is
// Arguments: a stack pointer
// Return value: the vale that was popped or NAN if unsuccessful
//
//======================================================================================
static double pop(struct Stack* Stack)
{
	double itemToBePop = 0;
	if (isEmpty(Stack) == 0)
	{
		itemToBePop = Stack->data[Stack->top-1];
		Stack->data[Stack->top-1] = NAN;
		Stack->top--;
		return itemToBePop;
	};
	return NAN;
}
//======================================================================================
//
// Function: peek
// Description: view the top item on the stack, the first to be popped off
// Arguments: a stack pointer
// Return value: the item on top, or NAN if unsuccessful
//
//======================================================================================
static double peek(struct Stack* Stack)
{
	if (isEmpty(Stack) == 0)
	{
		return Stack->data[Stack->top-1];
	};
	return NAN;
}
//======================================================================================
//
// Function: isEmpty
// Description: checks if stack is empty
// Arguments:	a stack pointer
// Return value: bool value, 1 if empty
//
//======================================================================================
static int isEmpty(struct Stack* Stack)
{
	if (Stack->top-1 == Stack->bottom)
		return 1;
	else
		return 0;
}
//======================================================================================
//
// Function: isFull
// Description: checks if stack is full
// Arguments: a stack pointer
// Return value: bool value, 1 if full
//
//======================================================================================

static int isFull(struct Stack* Stack)
{
	if (Stack->top == MAXSIZE)
		return 1;
	else
		return 0;
}
//======================================================================================
//
// Function: listStackContents
// Description: lists everything in the stack unless empty
// Arguments: a stack pointer
// Return value: bool value if successful as well as printing output
//
//======================================================================================
int listStackContents(struct Stack* Stack)
{
  printf("Stack Contents: (First out on left)\n");
	if (isEmpty(Stack) == 0)
	{
		for (int i = Stack->top-1; i >= 0; i--)
			printf("%lf ", Stack->data[i]);
		printf("\n");
		return 1;
	}
	printf("EMPTY\n");
	return 0;
}
//======================================================================================
//
// Function: printData
// Description: prints data, so that the functions aren't accessed directly
// Arguments: instruction, stack pointer, and an optional double item
//            u is push
//            o is pop
//            e is peek
//         	  t is isEmpty
//         	  f is isfull
// Return value: none, ust displays
//
//======================================================================================
void printData(char instruction,struct Stack* Stack,double item)
{
	switch (instruction)
	{
	case 'u': printf("Pushed success(1 = true,0 = false): %d\n", push(Stack, item));
		break;
	case 'o': printf("Poped item: %lf\n", pop(Stack));
		break;
	case 'e': printf("Peek item: %lf\n", peek(Stack));
		break;
	case 't': printf("Empty success(1 = true,0 = false): %d\n", isEmpty(Stack));
		break;
	case 'f': printf("Full success(1 = true,0 = false): %d\n", isFull(Stack));
		break;
	default: printf("Invalid Instruction");
		break;
	}

}

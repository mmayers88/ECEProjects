#include "Queue.h"

//======================================================================================
//
// Function: QueueInit
// Description: initiates the queue and initializes values, and sets array to NULL character
// Arguments: none
// Return value: returns the pointer to a queue
//
//======================================================================================
struct Queue* QueueInit()
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->end = 0;
	queue->front = 0;
	queue->emptyFlag = 1;
	queue->fullFlag = 0;
	for (int i = 0; i < MAXSIZE; i++)
		queue->data[i] = '\0';
	return queue;
}
//======================================================================================
//
// Function: enqueue
// Description: pushes a value into the queue
// Arguments: a queue pointer and a char
// Return value: bool values, true if successful
//
//======================================================================================
static int enqueue(struct Queue* Queue, char d)
{
	if (isFullQ(Queue) == 0)
	{
		Queue->data[Queue->end] = d;
		Queue->emptyFlag = 0;
		if (Queue->end == MAXSIZE - 1 && Queue->front != 0)
		{
			Queue->end = 0;
			if (isFullQ(Queue) == 1)
				Queue->fullFlag = 1;
		}
		else if (Queue->end > Queue->front)
		{
			Queue->end++;
			if (Queue->end == MAXSIZE && Queue->front == 0)
				Queue->end = MAXSIZE - 1;
			if (isFullQ(Queue) == 1)
				Queue->fullFlag = 1;
		}
		else if (Queue->end + 1 != Queue->front)
		{
			Queue->end++;
			if (isFullQ(Queue) == 1)
				Queue->fullFlag = 1;
		}
		return 1;
	}

		return 0;
}
//======================================================================================
//
// Function: dequeue
// Description: removes an item of the queue  FIFO and shows what it is
// Arguments: a queue pointer
// Return value: the vale that was popped or NAN if unsuccessful
//
//======================================================================================
static char dequeue(struct Queue* Queue)
{
	char itemToBePop = 0;
	if (isEmptyQ(Queue) == 0)
	{
		if (isFullQ(Queue) == 1)
		{
			if (Queue->end == MAXSIZE - 1)
				Queue->end = 0;

			else if (Queue->end + 1 != Queue->front)
				Queue->end++;
		}

		itemToBePop = Queue->data[Queue->front];
		Queue->data[Queue->front] = '\0';
		Queue->front++;
		Queue->fullFlag = 0;
		if (Queue->end == Queue->front)
			Queue->emptyFlag = 1;
		return itemToBePop;
	}
	return '0';
}
//======================================================================================
//
// Function: peek
// Description: view the top item on the queue, the first to be dequeue off
// Arguments: a queue pointer
// Return value: the item on top, or NAN if unsuccessful
//
//======================================================================================
static char peekQ(struct Queue* Queue)
{
	if (isEmptyQ(Queue) == 0)
	{
		return Queue->data[Queue->front];
	};
	return '0';
}
//======================================================================================
//
// Function: isEmptyQ
// Description: checks if queue is empty
// Arguments:	a queue pointer
// Return value: bool value, 1 if empty
//
//======================================================================================
static int isEmptyQ(struct Queue* Queue)
{
	if (Queue->emptyFlag == 1)
		return 1;
	if (Queue->end == Queue->front && Queue->data[Queue->end] == '\0')
		return 1;
	else
		return 0;
}
//======================================================================================
//
// Function: isFullQ
// Description: checks if queue is full
// Arguments: a queue pointer
// Return value: bool value, 1 if full
//
//======================================================================================

static int isFullQ(struct Queue* Queue)
{
	if (Queue->fullFlag == 1)
		return 1;
	if (Queue->end == (MAXSIZE - 1) && Queue->front == 0 && Queue->data[Queue->end] != '\0')
		return 1;
	if (Queue->end + 1 == Queue->front && Queue->data[Queue->end] != '\0')
		return 1;
	return 0;
}
//======================================================================================
//
// Function: listQueueContents
// Description: lists everything in the queue unless empty
// Arguments: a queue pointer
// Return value: bool value if successful as well as printing output
//
//======================================================================================
int listQueueContents(struct Queue* Queue)
{
	printf("Queue Contents: (First out on left)\n");
	if (isEmptyQ(Queue) == 0)
	{
		if (Queue->end > Queue->front)
		{
			for (int i = Queue->front; i <= Queue->end; i++)
				if (Queue->data[i] != '\0')
					printf("%c ", Queue->data[i]);
			printf("\n");
			return 1;
		}
		else
		{
			for (int i = Queue->front; i < MAXSIZE; i++)
				if (Queue->data[i] != '\0')
					printf("%c ", Queue->data[i]);
			for (int i = Queue->end; i < Queue->front; i++)
				if (Queue->data[i] != '\0')
					printf("%c ", Queue->data[i]);
			printf("\n");
			return 1;
		}
	}
	printf("EMPTY\n");
	return 0;
}
//======================================================================================
//
// Function: printDataQ
// Description: prints data, so that the functions aren't accessed directly
// Arguments: instruction, stack pointer, and an optional char item
//            u is push
//            o is pop
//            e is peek
//         	  t is isEmpty
//         	  f is isfull
// Return value: none, ust displays
//
//======================================================================================
void printDataQ(char instruction, struct Queue* Queue, char item)
{
	switch (instruction)
	{
	case 'u': printf("Pushed success(1 = true,0 = false): %d\n", enqueue(Queue, item));
		break;
	case 'o': printf("Poped item: %c\n", dequeue(Queue));
		break;
	case 'e': printf("Peek item: %c\n", peekQ(Queue));
		break;
	case 't': printf("Empty success(1 = true,0 = false): %d\n", isEmptyQ(Queue));
		break;
	case 'f': printf("Full success(1 = true,0 = false): %d\n", isFullQ(Queue));
		break;
	default: printf("Invalid Instruction");
		break;
	}

}

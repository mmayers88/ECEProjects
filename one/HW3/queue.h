#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<math.h>

#define MAXSIZE 10    // <-const int MAXSIZE = 10;

struct Queue
{
	int end;
	int front;
	int fullFlag;
	int emptyFlag;
	char data[MAXSIZE];
};

struct Queue* QueueInit();
static int enqueue(struct Queue*, char d);
static char dequeue(struct Queue*);
static char peekQ(struct Queue*);
static int isEmptyQ(struct Queue*);
static int isFullQ(struct Queue*);
int listQueueContents(struct Queue*);
void printDataQ(char instruction, struct Queue* Queue, char item);
#endif

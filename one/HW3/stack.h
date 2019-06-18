#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>

#define MAXSIZE 10   // <-const int MAXSIZE = 10;

static struct Stack
{
	int top;
	int bottom;
	double data[MAXSIZE];
};
struct Stack* stackInit();
static int push(struct Stack*, double d);
static double pop(struct Stack*);
static double peek(struct Stack*);
static int isEmpty(struct Stack*);
static int isFull(struct Stack*);
int listStackContents(struct Stack*);
void printData(char instruction, struct Stack* Stack, double item);


#endif

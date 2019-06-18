/*
Program Name:	stacksAndQueues
Programmer:		Mikhail Mayers
Date:			10/26/2018
IDE:			mingw32
Purpose:	test some stacks and queues	                                 */

#define QUEUE_H
#define STACK_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<math.h>
#include "stack.h"
#include "queue.h"

void main()
{

	struct Queue * testQueue = QueueInit();
	struct Queue * testQueue2 = QueueInit();
  struct Stack * testStack = stackInit();
	struct Stack * testStack2 = stackInit();

	printf("1st Stack:\n\n" );
  listStackContents(testStack);
  printData('e',testStack,0 );
	printData('u', testStack, .0);
	printData('u', testStack, .1);
	printData('u', testStack, .2);
	printData('u', testStack, .3);
	printData('u', testStack, .4);
	printData('u', testStack, .5);
  printData('u', testStack, .6);
  printData('u', testStack, .7);
  printData('u', testStack, .8);
  printData('u', testStack, .9);
  printData('u', testStack, 1.0);
  printData('u', testStack, 1.1);
  listStackContents(testStack);
  printData('f', testStack, 10);
  printData('e', testStack, 0);
  printData('o', testStack, 10);
  listStackContents(testStack);

	printf("\n\nNew Stack:\n\n" );
	listStackContents(testStack2);
  printData('e',testStack2,0 );
	printData('u', testStack2,.0);
	printData('u', testStack2, .1);
	printData('u', testStack2, .2);
	printData('u', testStack2, .3);
	printData('u', testStack2, .4);
	printData('u', testStack2, .5);
  printData('u', testStack2, .6);
  printData('u', testStack2, .7);
  printData('u', testStack2, .8);
  printData('u', testStack2, .9);
  printData('u', testStack2, 1.0);
  printData('u', testStack2, 1.1);
  listStackContents(testStack2);
  printData('f', testStack2, 10);
  printData('e', testStack2, 0);
  printData('o', testStack2, 10);
  listStackContents(testStack2);

	printf("\n\nQueue:\n\n" );
	listQueueContents(testQueue);
	printDataQ('o', testQueue, 'a');
	printDataQ('e', testQueue, 'b');
  printDataQ('u', testQueue, 'a');
  printDataQ('u', testQueue, 'b');
	printDataQ('u', testQueue, 'c');
	printDataQ('u', testQueue, 'd');
	printDataQ('u', testQueue, 'e');
	printDataQ('u', testQueue, 'f');
	printDataQ('u', testQueue, 'g');
	printDataQ('u', testQueue, 'h');
	printDataQ('u', testQueue, 'i');
	printDataQ('u', testQueue, 'j');
	printDataQ('u', testQueue, 'k');
	listQueueContents(testQueue);
	printDataQ('f', testQueue, 'k');
	printDataQ('e', testQueue, 'k');
	printDataQ('o', testQueue, 'k');
	printDataQ('u', testQueue, 'k');
	printDataQ('e', testQueue, 'i');
	listQueueContents(testQueue);
	printDataQ('u', testQueue, 'l');
	listQueueContents(testQueue);

	printf("\n\nNext Queue:\n\n" );
	listQueueContents(testQueue2);
	printDataQ('o', testQueue2, 'a');
	printDataQ('e', testQueue2, 'b');
  printDataQ('u', testQueue2, 'a');
  printDataQ('u', testQueue2, 'b');
	printDataQ('u', testQueue2, 'c');
	printDataQ('u', testQueue2, 'd');
	printDataQ('u', testQueue2, 'e');
	printDataQ('u', testQueue2, 'f');
	printDataQ('u', testQueue2, 'g');
	printDataQ('u', testQueue2, 'h');
	printDataQ('u', testQueue2, 'i');
	printDataQ('u', testQueue2, 'j');
	printDataQ('u', testQueue2, 'k');
	listQueueContents(testQueue2);
	printDataQ('f', testQueue2, 'k');
	printDataQ('e', testQueue2, 'k');
	printDataQ('o', testQueue2, 'k');
	printDataQ('u', testQueue2, 'k');
	printDataQ('e', testQueue2, 'i');
	listQueueContents(testQueue2);
	printDataQ('u', testQueue2, 'l');
	listQueueContents(testQueue2);

	getchar();
}

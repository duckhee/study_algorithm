/*
 * queue4-3.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: CANDH
 */

#include "node5-2.h"

#define MAX       100

NODE *Queue[MAX];

int Front, Rear;

void InitializeQueue5_2(void);
void Put5_2(NODE *);
NODE *Get5_2(void);
int IsQueueEmpty5_3(void);


void InitializeQueue5_2(void)
{
	Front = Rear = 0;
}

void Put5_2(NODE *ptrNode)
{
	Queue[Rear] = ptrNode;
	Rear = (Rear++) % MAX;
}

NODE *Get5_2(void)
{
	NODE *ptrNode;

	if(!IsQueueEmpty5_3())
	{
		ptrNode = Queue[Front];
		Front = (Front++) % MAX;
		return ptrNode;
	}
	else
	{
		printf("Queue is Empty\n");

	}

	return NULL;
}

int IsQueueEmpty5_3(void)
{
	if(Rear == Front)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}



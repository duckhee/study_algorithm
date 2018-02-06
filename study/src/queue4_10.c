/*
 * queue4_10.c
 *
 *  Created on: 2018. 2. 6.
 *      Author: CANDH
 */




#include "node4-3.h"

#define MAX     100

NODE *Queue4_10[MAX];

int Front, Rear;

void InitializeQueue4_10(void);
void Put4_10(NODE *);
NODE *Get4_10(void);
int IsQueueEmpty4_10(void);


void InitializeQueue4_10(void)
{
	printf("InitializeQueue\n");
	Front = Rear = 0;
}

void Put4_10(NODE *ptrNode)
{
	printf("put\n");
	Queue4_10[Rear] = ptrNode;
	Rear = (Rear++)%MAX;
}

NODE *Get4_10(void)
{
	printf("get\n");
	NODE *ptrNode;

	if(!IsQueueEmpty4_10())
	{
		ptrNode = Queue4_10[Front];
		Front = (Front++)%MAX;

		return ptrNode;
	}
	else
	{
		printf("Queue is Empty\n");

		return NULL;
	}
}

int IsQueueEmpty4_10(void)
{
	printf("IsQueueEmpty\n");
	if(Rear == Front)
	{
		printf("ture\n");
		return TRUE;
	}
	else
	{
		printf("false\n");
		return FALSE;
	}
}


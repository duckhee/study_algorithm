/*
 * queue3-14.c
 *
 *  Created on: 2018. 1. 30.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
	int Data;
	struct _NODE *Next;

} NODE;

NODE *Front, *Rear;
NODE *ptrNode;

void InitializelinkQueue(void);
void LinkPut(int);
int LinkGet(void);
void DisplayLinkQueue(void);

void InitializelinkQueue(void)
{
	Front = (NODE *)malloc(sizeof(NODE));
	Rear = (NODE *)malloc(sizeof(NODE));
	Front->Next = Rear;
	Rear->Next = Front;

}

void LinkPut(int num)
{
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;

	if(Front->Next == Rear)
	{
		Front->Next = ptrNode;
		ptrNode->Next = Rear;
		Rear->Next = ptrNode;
	}
	else
	{
		Rear->Next->Next = ptrNode;
		ptrNode->Next = Rear;
		Rear->Next = ptrNode;
	}

}


int LinkGet(void)
{
	int ret;
	NODE *deleteNode;
	printf("\n");

	if(Front->Next == Rear)
	{
		printf("Queue Empty\n");
	}
	else
	{
		deleteNode = Front->Next;
		Front->Next = deleteNode->Next;
		ret = deleteNode->Data;
		printf("Get() : %d", ret);

		free(deleteNode);
	}

	return ret;
}

void DisplayLinkQueue(void)
{
	NODE *ptrTemp;

	if(Front->Next != Rear)
	{
		for(ptrTemp = Front->Next;ptrTemp->Next != Rear; ptrTemp = ptrTemp->Next)
		{
			printf("%d-> ", ptrTemp->Data);

		}
		printf("%d\n", ptrTemp->Data);

	}
	else if(Front->Next == Rear)
	{
		printf("Queue Empty\n");
	}

}

void main()
{
	int ret;
	InitializelinkQueue();
	printf("call LinkPut function \n");
	LinkPut(1);
	LinkPut(3);
	LinkPut(10);
	LinkPut(20);
	LinkPut(12);

	printf("after call five LinkPut function leter\n");
	DisplayLinkQueue();

	ret = LinkGet();
	ret = LinkGet();
	ret = LinkGet();

	printf("\nafter three LinkGet function leter\n");
	DisplayLinkQueue();

	ret = LinkGet();
	ret = LinkGet();
	printf("\nafter two LinkGet function leter\n");
	DisplayLinkQueue();
}

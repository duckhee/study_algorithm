/*
 * stack4-4.c
 *
 *  Created on: 2018. 1. 30.
 *      Author: CANDH
 */


#include "node4-3.h"

#define MAX        100

NODE *Stack[MAX];
int Top;

void InitializeStack4_4(void);
void Push4_4(NODE *);
NODE *Pop4_4(void);
int IsStackEmpty4_4(void);

void InitializeStack4_4(void)
{
	printf("InitializeStack4_4\n");
	Top = 0;
}

void Push4_4(NODE *ptrNode)
{
	printf("Push4_4\n");
	Stack[Top] = ptrNode;
	Top = (Top++) % MAX;
}


NODE *Pop4_4(void)
{
	printf("Pop4_4\n");
	NODE *ptrNode;

	if(!IsStackEmpty4_4())
	{
		ptrNode = Stack[--Top];

		return ptrNode;
	}
	else
	{
		printf("Stack is Empty\n");
	}

	return NULL;
}

int IsStackEmpty4_4(void)
{
	printf("IsStackEmpty4_4\n");
	if(Top == 0)
	{
		printf("true\n");
		return TRUE;

	}
	else
	{
		printf("false\n");
		return FALSE;
	}
}




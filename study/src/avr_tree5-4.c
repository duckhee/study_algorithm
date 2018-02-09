/*
 * avr_tree5-4.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include "node5-2.h"

#define TRUE      1
#define FALSE     0

NODE *HeadNode;
NODE *ParentNode;
NODE *GrandNode;
NODE *ChildNode;
NODE *BigNode;

void InitializeTree5_4(void);
void InsertNode5_4(int);
int IsBalance5_4(void);
void RR_Rotate5_4(void);
void Level_Traverse5_4(NODE *);
void Visit5_4(NODE *);

extern void InitializeQueue5_2(void);
extern void Put5_2(NODE *);
extern NODE *Get5_2(void);
extern int IsQueueEmpty5_3(void);


void InitializeTree5_4(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	HeadNode->Left = HeadNode;
	HeadNode->Right = HeadNode;
	BigNode = HeadNode;
}

void InsertNode5_4(int Data)
{
	NODE *tmpNode;
	NODE *ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = Data;
	ptrNode->Balance = 0;
	ptrNode->Left = HeadNode;

	ptrNode->Right = HeadNode;

	if(HeadNode->Right == HeadNode)
	{//first node
		HeadNode->Right = ptrNode;
		HeadNode->Left = ptrNode;
	}
	else
	{
		GrandNode = HeadNode;
		ParentNode = HeadNode;
		ChildNode = HeadNode->Right;
		tmpNode = HeadNode->Right;

		while(tmpNode != HeadNode)
		{
			ChildNode = tmpNode;

			if(ChildNode->Data > ptrNode->Data)
			{
				BigNode = GrandNode;
				GrandNode = ParentNode;
				ParentNode = ChildNode;
				tmpNode = tmpNode->Left;
			}
			else
			{
				BigNode = GrandNode;
				GrandNode = ParentNode;
				ParentNode = ChildNode;
				tmpNode = tmpNode->Right;
			}
		}

		ChildNode = ptrNode;

		//new node insert
		if(ParentNode->Data > ChildNode->Data)
		{
			ParentNode->Left = ChildNode;
			ParentNode->Balance++;

			if(GrandNode != HeadNode)
			{
				GrandNode->Balance++;
			}
		}
		else
		{
			ParentNode->Right = ChildNode;
			ParentNode->Balance--;

			if(GrandNode != HeadNode)
			{
				GrandNode->Balance--;
			}
		}

		if(IsBalance5_4() == FALSE)
		{
			RR_Rotate5_4();
		}

	}
}

int IsBalance5_4(void)
{
	int ret = TRUE;
	NODE *ptrNode;
	ptrNode = HeadNode->Right;

	InitializeQueue5_2();
	Put5_2(ptrNode);

	while(!IsQueueEmpty5_3())
	{
		ptrNode = Get5_2();

		if(ptrNode->Balance > 1 || ptrNode->Balance < -1)
		{
			ret = FALSE;
			break;
		}
		if(ptrNode->Left != HeadNode)
		{
			Put5_2(ptrNode->Left);
		}
		if(ptrNode->Right != HeadNode)
		{
			Put5_2(ptrNode->Right);
		}

	}

	return ret;
}
//rr rotation
void RR_Rotate5_4(void)
{
	ParentNode = GrandNode->Right;
	ChildNode = ParentNode->Right;

	if(GrandNode->Balance == -2)
	{
		BigNode->Right = ParentNode;
		ParentNode->Left = GrandNode;
		GrandNode->Left = HeadNode;
		GrandNode->Right = HeadNode;
	}

	BigNode->Balance++;
	ParentNode->Balance = 0;
	GrandNode->Balance = 0;
	ChildNode->Balance = 0;
}

//use queue travel tree
void Level_Traverse5_4(NODE *ptrNode)
{
	InitializeQueue5_2();
	Put5_2(ptrNode);

	while(!IsQueueEmpty5_3())
	{
		ptrNode = Get5_2();
		printf(" -> ");
		Visit5_4(ptrNode);

		if(ptrNode->Left != HeadNode)
		{
			Put5_2(ptrNode->Left);
		}
		if(ptrNode->Right != HeadNode)
		{
			Put5_2(ptrNode->Right);
		}
	}
}

void Visit5_4(NODE *ptrNode)
{
	printf("%2d", ptrNode->Data);
}

void main(void)
{
	InitializeTree5_4();
	printf("녿 10과 20 삽입\n");

	InsertNode5_4(10);
	InsertNode5_4(20);
	Level_Traverse5_4(HeadNode->Right);
	printf("\n=============================================\n");
	printf("노드 30 삽입\n");
	InsertNode5_4(30);

	Level_Traverse5_4(HeadNode->Right);
}

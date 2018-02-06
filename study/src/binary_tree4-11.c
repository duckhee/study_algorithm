/*
 * binary_tree4-11.c
 *
 *  Created on: 2018. 2. 6.
 *      Author: CANDH
 */




#include "node4-3.h"

extern void InitializeQueue4_10(void);
extern void Put4_10(NODE *);
extern NODE *Get4_10(void);
extern int IsQueueEmpty4_10(void);

void InitializeTree4_11(void);
void MakeTree4_11(void);
void Level_Traverse4_11(NODE *);
void Visit4_11(NODE *);

NODE *Parent, *LeftChild, *RightChild;
NODE *HeadNode, *EndNode;

void InitializeTree4_11(void)
{
	printf("initializetree\n");
	HeadNode = (NODE *)malloc(sizeof(NODE));
	EndNode = (NODE *)malloc(sizeof(NODE));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;

}

void MakeTree4_11(void)
{
	printf("maketree\n");
	Parent = (NODE *)malloc(sizeof(NODE));
	Parent->Data = 'A';

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'B';

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

	Parent = Parent->Left;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'D';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'E';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
	Parent = HeadNode->Right->Right;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'F';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
}

void Level_Traverse4_11(NODE *ptrNode)
{
	printf("level_traverse\n");
	Put4_10(ptrNode);
	while(!IsQueueEmpty4_10())
	{
		ptrNode = Get4_10();
		Visit4_11(ptrNode);

		if(ptrNode->Left != EndNode)
		{
			Put4_10(ptrNode->Left);
		}

		if(ptrNode->Right != EndNode)
		{
			Put4_10(ptrNode->Right);
		}
	}
}

void Visit4_11(NODE *ptrNode)
{
	printf("visit\n");
	printf("%2c -> ", ptrNode->Data);
}

void main()
{
	InitializeQueue4_10();
	InitializeTree4_11();

	MakeTree4_11();

	printf("큐를 사용한 단계 순회 : ");

	Level_Traverse4_11(HeadNode->Left);

}

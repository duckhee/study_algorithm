/*
 * binary_tree4-5.c
 *
 *  Created on: 2018. 1. 30.
 *      Author: CANDH
 */



#include "node4-3.h"


extern void InitializeStack4_4(void);
extern void Push4_4(NODE *);
extern NODE *Pop4_4(void);
extern int IsStackEmpty4_4(void);

void InitializeTree4_5(void);
void MakeTree4_5(void);
void Traverse4_5(NODE *);
void Visit4_5(NODE *);

NODE *Parent, *LeftChild, *RightChild;
NODE *HeadNode, *EndNode;

void InitializeTree4_5(void)
{
	printf("InitializeTree4_5\n");
	HeadNode = (NODE *)malloc(sizeof(NODE));
	EndNode = (NODE *)malloc(sizeof(NODE));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;

}

void MakeTree4_5(void)
{
	printf("MakeTree4_5\n");
	Parent = (NODE *)malloc(sizeof(NODE));
	Parent->Data = 'A';

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'B';

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

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

void Traverse4_5(NODE *ptrNode)
{
	printf("Traverse4_5\n");
	Push4_4(ptrNode);

	while(!IsStackEmpty4_4())
	{
		ptrNode = Pop4_4();
		Visit4_5(ptrNode);

		if(ptrNode->Right != EndNode)
		{
			Push4_4(ptrNode->Right);
		}
		if(ptrNode->Left != EndNode)
		{
			Push4_4(ptrNode->Left);
		}

	}

}

void Visit4_5(NODE *ptrNode)
{
	printf("Visit4_5\n");
	printf("%2c -> ", ptrNode->Data);
}

void main()
{
	InitializeStack4_4();
	InitializeTree4_5();
	MakeTree4_5();
	Traverse4_5(HeadNode->Left);
}

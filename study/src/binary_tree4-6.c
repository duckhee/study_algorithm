/*
 * binary_tree4-6.c
 *
 *  Created on: 2018. 1. 31.
 *      Author: CANDH
 */




#include "node4-3.h"

extern void InitializeStack4_4(void);
extern void Push4_4(NODE *);
extern NODE *Pop4_4(void);
extern int IsStackEmpty4_4(void);

void InitializeTree4_6(void);
void MakeTree4_6(void);
void Recursive_Traverse4_6(NODE *);
void Stack_Traverse4_6(NODE *);
void Visit4_6(NODE *);

NODE *Parent, *LeftChild, *RightChild;
NODE *HeadNode, *EndNode;

void InitializeTree4_6(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	EndNode = (NODE *)malloc(sizeof(NODE));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}

void MakeTree4_6(void)
{
	Parent = (NODE *)malloc(sizeof(NODE));
	Parent->Data = 'A';

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'B';

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'C';

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

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
	Parent = Parent->Right->Right;

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

void Recursive_Traverse4_6(NODE *ptrNode)
{
	if(ptrNode != EndNode)
	{
		Recursive_Traverse4_6(ptrNode->Left);
		Visit4_6(ptrNode);
		Recursive_Traverse4_6(ptrNode->Right);
	}
}

void Stack_Traverse4_6(NODE *ptrNode)
{
	int Finish = 0;
	do
	{
		while(ptrNode != EndNode)
		{
			Push4_4(ptrNode);
			ptrNode = ptrNode->Left;
		}

		if(!IsStackEmpty4_4())
		{
			ptrNode = Pop4_4();
			Visit4_6(ptrNode);
			ptrNode = ptrNode->Right;
		}
		else
		{
			Finish = 1;
		}
	}while(!Finish);
}

void Visit4_6(NODE *ptrNode)
{
	printf("%2c -> ", ptrNode->Data);
}

void main()
{
	InitializeStack4_4();
	InitializeTree4_6();
	MakeTree4_6();

	printf("재귀 호출을 사용한 중위 순회 : ");
	Recursive_Traverse4_6(HeadNode->Left);
	printf("\n스텍을 이용한 주위 순회 : ");
	Stack_Traverse4_6(HeadNode->Left);

}

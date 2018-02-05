/*
 * binart_tree4-7.c
 *
 *  Created on: 2018. 2. 5.
 *      Author: CANDH
 */




#include "node4-3.h"

extern void InitializeStack4_4(void);
extern void Push4_4(NODE *);
extern NODE *Pop4_4(void);
extern int IsStackEmpty4_4(void);

void InitializeTree4_7(void);
void MakeTree4_7(void);
void Recursive_Traverse4_7(NODE *);
void Stack_Traverse4_7(NODE *);
void Visit4_7(NODE *);

NODE *Parent, *LeftChild, *RightChild, *HeadNode, *EndNode;

void InitializeTree4_7(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	EndNode = (NODE *)malloc(sizeof(NODE));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Right = EndNode;
	EndNode->Left = EndNode;
}

void MakeTree4_7(void)
{
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

	Parent = Parent->Right->Right;

	LeftChild = (NODE *)malloc(sizeof(NODE));
	LeftChild->Data = 'F';
	LeftChild->Left = EndNode;
	RightChild->Right = EndNode;

	RightChild = (NODE *)malloc(sizeof(NODE));
	RightChild->Data = 'G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

}

void Recursive_Traverse4_7(NODE *ptrNode)
{
	if(ptrNode != EndNode)
	{
		Recursive_Traverse4_7(ptrNode->Left);
		Recursive_Traverse4_7(ptrNode->Right);
		Visit4_7(ptrNode);
	}
}

void Stack_Traverse4_7(NODE *ptrNode)
{
	int Finish = 0;
	NODE *ptrVisited = EndNode;
	NODE *ptrPushed = EndNode;

	do
	{
		while(ptrNode != EndNode && ptrNode != ptrVisited)
		{
			if(ptrNode->Right != EndNode)
			{
				Push4_4(ptrNode->Right);
			}

			if(ptrNode->Left != EndNode)
			{
				Push4_4(ptrNode->Left);
			}

			ptrPushed = ptrNode->Left;
			ptrNode = ptrNode->Left;
		}

		if(!IsStackEmpty4_4())
		{
			ptrNode = Pop4_4();

			if(ptrNode->Left != EndNode && ptrNode->Right == EndNode && ptrNode->Left != ptrVisited)
			{
				Push4_4(ptrNode);
				ptrNode = ptrNode->Left;
			}

			if(ptrNode->Right == EndNode || ptrNode->Right == ptrVisited)
			{
				Visit4_7(ptrNode);
				ptrVisited = ptrNode;
			}
		}
		else
		{
			Finish = 1;

		}
	}while(!Finish);
}

void Visit4_7(NODE *ptrNode)
{
	printf("%2c -> ", ptrNode->Data);

}

void main()
{
	InitializeStack4_4();
	InitializeTree4_7();
	MakeTree4_7();
	printf("재귀 호출을 사용한 후위 순회 : ");

	Recursive_Traverse4_7(HeadNode->Left);

	printf("\n 스택을 사용한 후위 순회 : ");

	Stack_Traverse4_7(HeadNode->Left);

}


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

	Top = 0;
}

void Push4_4(NODE *ptrNode)
{


	Stack[Top] = ptrNode;

	Top = (++Top)%MAX; //binary_tree 4-5
	//Top = (Top++)%MAX;

}


NODE *Pop4_4(void)
{

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

	if(Top == 0)
	{

		return TRUE;

	}
	else
	{

		return FALSE;
	}
}




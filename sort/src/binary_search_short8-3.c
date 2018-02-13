/*
 * binary_search_short8-3.c
 *
 *  Created on: 2018. 2. 13.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX     100
#define TRUE    1
#define FALSE   0

typedef struct _NODE {
	int key;
	struct _NODE *Left;
	struct _NODE *Right;
} NODE;

NODE *ptrNode;
NODE *head;
NODE *end;

void MakeRandomNumber8_3(void);
void QuickSort8_3(int [], int, int);
void DisplayBuffer8_3(void);
int IsNumberExit8_3(int, int);
void BSTInitialize8_3(void);
void BSTInsert8_3(int);
void BSTDisplay8_3(NODE *);
void BSTDelete8_3(int);

int Buf[MAX];
int CompareCount;

void MakeRandomNumber8_3(void)
{
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while(i < MAX)
	{
		Num = rand() % 200;

		if(!IsNumberExit8_3(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void QuickSort8_3(int data[], int left, int right)
{
	int num, i, j, temp;

	if(right > left)
	{
		num = data[right];
		i = left - 1;
		j = right;

		for(; ;)
		{
			while(data[++i] < num);
			while(data[--j] > num);
			if(i >= j)
			{
				break;
			}

			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}

		temp = data[i];
		data[i] = data[right];
		data[right] = temp;

		QuickSort8_3(data, left, i -1);
		QuickSort8_3(data, i+1, right);
	}
}

void DisplayBuffer8_3(void)
{
	int i;

	for(i = 0; i < MAX; i++)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%4d", Buf[i]);
	}
	printf("\n");
}

int IsNumberExit8_3(int number, int index)
{
	int i;

	for(i = 0; i < index; i++)
	{
		if(Buf[i] == number || number == 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void BSTInitialize8_3(void)
{
	end = (NODE *)malloc(sizeof *end);
	end->Left = end;
	end->Right = end;
	end->key = -1;

	head = (NODE *)malloc(sizeof *head);
	head->Right = end;
	head->key = 0;

}

void BSTInsert8_3(int num)
{
	NODE *p, *x;
	p = head;
	x = head->Right;

	while(x != end)
	{
		p = x;
		x = (num < x->key) ? x->Left : x->Right;
	}

	x = (NODE *)malloc(sizeof *x);
	x->key = num;
	x->Left = end;
	x->Right = end;

	if(num < p->key)
	{
		p->Left = x;
	}else{
		p->Right = x;
	}
}

void BSTDisplay8_3(NODE *ptr)
{
	if(ptr != end)
	{
		BSTDisplay8_3(ptr->Left);
		printf("%5d", ptr->key);
		BSTDisplay8_3(ptr->Right);
	}
}
void BSTDelete8_3(int num)
{
	NODE *g, *p, *x;
	NODE *temp;
	end->key = num;
	p = head;
	x = head->Right;
	while(num != x->key)
	{
		p = x;

		if(num < x->key)
		{
			x = x->Left;
		}else
		{
			x = x->Right;
		}
	}

	temp = x;

	if(temp->Right == end)
	{
		x = x->Left;
	}else if(temp->Right->Left == end)
	{
		x = x->Right;
		x->Left = temp->Left;
	}
	else
	{
		g = x->Right;

		while(g->Left->Left != end){
			g = g->Left;
		}
		x = g->Left;
		g->Left = x->Right;
		x->Left = temp->Left;
		x->Right = temp->Right;
	}
	free(temp);

	if(num < p->key)
	{
		p->Left = x;

	}else
	{
		p->Right = x;
	}
}

void main()
{
	int i, ret;
	CompareCount = 0;

	MakeRandomNumber8_3();
	QuickSort8_3(Buf, 0, MAX - 1);
	printf("정렬된 데이터 \n");

	DisplayBuffer8_3();
	BSTInitialize8_3();

	for(i = 0; i < MAX; i++)
	{
		BSTInsert8_3(Buf[i]);
	}

	printf("\n root node : %d\n", head->Right->key);
	BSTDisplay8_3(head->Right);
	printf("\n\n");
	printf("%d 삭제 \n", Buf[5]);

	BSTDelete8_3(Buf[5]);
	BSTDisplay8_3(head->Right);
}

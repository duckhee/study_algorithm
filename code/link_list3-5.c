/*
 * link_list3-5.c
 *
 *  Created on: 2018. 1. 30.
 *      Author: CANDH
 */



#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
	char Data;
	struct _NODE *Next;

} NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);
void DeleteNode(NODE *);

void Initialize(void)
{
	NODE *ptr;
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));

	temp1 = (NODE *)malloc(sizeof(NODE));
	temp1->Data = 'A';
	head->Next = temp1;
	temp1->Next = end;
	end->Next = end;
	ptr = temp1;

	temp2 = (NODE *)malloc(sizeof(NODE));
	temp2->Data = 'B';
	ptr->Next = temp2;
	temp2->Next = end;
	ptr = temp2;

	temp3 = (NODE *)malloc(sizeof(NODE));
	temp3->Data = 'D';
	ptr->Next = temp3;
	temp3->Next = end;
	ptr = temp3;

	temp4 = (NODE *)malloc(sizeof(NODE));
	temp4->Data = 'E';
	ptr->Next = temp4;
	temp4->Next = end;
	ptr = temp4;
}

void InsertNode(NODE *ptr)
{
	NODE *indexptr;

	for(indexptr = head->Next; indexptr != end; indexptr = indexptr->Next)
	{
		if(indexptr->Data < ptr->Data && indexptr->Next->Data > ptr->Data)
		{
			break;
		}

	}

	ptr->Next = indexptr->Next;
	indexptr->Next = ptr;
}

void DeleteNode(NODE *ptr)
{
	NODE *indexptr;
	NODE *deleteptr;

	for(indexptr = head; indexptr != end; indexptr = indexptr->Next)
	{
		if(indexptr->Next->Data == ptr->Data)
		{
			deleteptr = indexptr->Next;
			break;
		}

	}

	indexptr->Next = indexptr->Next->Next;
	free(deleteptr);
}

void main()
{
	NODE *ptr;
	int i = 0;
	Initialize();

	printf("before insert C node \n");
	ptr = head->Next;

	for(i = 0; i < 4; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	temp = (NODE *)malloc(sizeof(NODE));
	temp->Data = 'C';

	InsertNode(temp);
	printf("\n after insert node c\n");
	ptr = head->Next;

	for(i = 0; i < 5; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	DeleteNode(temp);

	printf("\n after delete node c\n");
	ptr = head->Next;

	for(i = 0; i < 4; i++)
	{
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}
}

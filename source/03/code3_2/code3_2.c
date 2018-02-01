#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	char Data;
	struct _NODE *Next;
} NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);

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

	for (indexptr = head; indexptr != end; indexptr = indexptr->Next) {
		if (indexptr->Next->Data > ptr->Data)
			break;
	}

	ptr->Next = indexptr->Next;
	indexptr->Next = ptr;
}

void main()
{
	NODE *ptr;
	int i = 0;
	Initialize();

	// 링크드 리스트의 노드에 저장한 데이터 출력
	ptr = head->Next;

	for (i = 0; i < 4; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}

	// 새로운 노드의 생성
	printf("\n");
	temp = (NODE *)malloc(sizeof(NODE));
	temp->Data = 'C';

	// 새로 생성한 노드의 삽입
	InsertNode(temp);

	// 링크드 리스트의 노드에 저장한 데이터의 출력
	ptr = head->Next;

	for (i = 0; i < 5; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}
}
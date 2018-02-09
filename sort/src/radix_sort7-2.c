/*
 * radix_sort.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: CANDH
 */


#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX      100
#define TRUE     1
#define FALSE    0

typedef struct _NODE
{
	int Data;
	struct _NUDE *Next;

} NODE;

NODE *Front[10];
NODE *Rear[10];
NODE *ptrNode;
int Buf[MAX];

void MakeRandomNumber7_2(void);
void RadixSort7_2(void);
void DisplayBuffer7_2(void);
int IsNumberExit7_2(int, int);
void InitializeQueue7_2(void);
void Put7_2(int, int);
int Get7_2(int);


void MakeRandomNumber7_2(void)
{
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while(i < MAX)
	{
		Num = rand() % 100;

		if(!IsNumberExit7_2(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void RadixSort7_2(void)
{
	int i, num, digit, j;
	j = 0;

	for(i = 0; i < MAX; i++)
	{
		num = Buf[i];
		digit = num % MAX;
		Put7_2(digit, num);
	}

	printf("\n1의 자릿수로 정렬된 숫자 리스트\n");

	for(i = 0; i < MAX; i++)
	{
		printf("\n%d의 자리 : ", i);

		while(1)
		{
			num = Get7_2(i);

			if(num != -1)
			{
				printf("%3d", num);
				Buf[j++] = num;
			}
			else
			{
				break;
			}
		}
	}

	printf("\n\n1차 정렬 후 Buf 안 데이터들 \n");
	DisplayBuffer7_2();

	//10의 자릿수로 정렬
	j = 0;

	for(i = 0; i < MAX; i++)
	{
		num = Buf[i];
		digit = num / MAX;
		Put7_2(digit, num);

	}

	printf("\n10의 자릿 수로 정렬된 숫자 리스트 \n");

	for(i = 0; i < MAX; i++)
	{
		printf("\n%d의 자리 : ",  i);
		while(1)
		{
			num = Get7_2(i);

			if(num != -1)
			{
				printf("%3d", num);
				Buf[j++] = num;
			}
			else
			{
				break;
			}
		}
	}

	printf("\n\n2차 정렬 후 Buf 안 데이터들\n");
	DisplayBuffer7_2();

}

void DisplayBuffer7_2(void)
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


int IsNumberExit7_2(int number, int index)
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

void InitializeQueue7_2(void)
{
	int i;

	for(i = 0; i < MAX; i++)
	{
		Front[i] = (NODE *)malloc(sizeof(NODE));
		Rear[i] = (NODE *)malloc(sizeof(NODE));
		Front[i]->Next = Rear[i];
		Rear[i]->Next = Rear[i];

	}
}

void Put7_2(int index, int num)
{
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;

	if(Front[index]->Next == Rear[index])
	{
		Front[index]->Next = ptrNode;
		ptrNode->Next = Rear[index];
		Rear[index]->Next = ptrNode;
	}
	else
	{
		//Rear[index]->Next->Next = ptrNode;
		ptrNode->Next = Rear[index];
		Rear[index]->Next = ptrNode;
	}
}

int Get7_2(int index)
{
	int ret;
	NODE *deleteNode;

	if(Front[index]->Next == Rear[index])
	{
		return -1;
	}
	else
	{
		deleteNode = Front[index]->Next;
		Front[index]->Next = deleteNode->Next;
		ret = deleteNode->Data;

		free(deleteNode);
	}
	return ret;
}

void main()
{
	InitializeQueue7_2();
	printf("정렬한 데이터 초기화\n");

	MakeRandomNumber7_2();
	DisplayBuffer7_2();
	RadixSort7_2();

	printf("\n\n");
	printf("\n");
}

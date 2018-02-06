/*
 * select_sort6_1.c
 *
 *  Created on: 2018. 2. 6.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>

#define MAX      100
#define TRUE     1
#define FALSE    0

void MakeRandomNumber6_1(void);
void SelectionSort6_1(void);
void DisplayBuffer6_1(void);
int IsNumberExit6_1(int, int);
int Buf[MAX];


void MakeRandomNumber6_1(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while(i < MAX)
	{
		Num = rand() % MAX;
		if(!IsNumberExit6_1(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void SelectionSort6_1(void)
{
	int i, j, min, dummy;

	for(i = 0; i < MAX; i++)
	{
		min = i;

		for(j = i + 1; j < MAX; j++)
		{
			if(Buf[j] < Buf[min])
			{
				min = j;
			}
		}
		//여기서 정렬을 실행을 하는 것 더미에 담아서 변경을 해준다.
		dummy = Buf[min];
		Buf[min] = Buf[i];
		Buf[i] = dummy;
	}
}

void DisplayBuffer6_1(void)
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

int IsNumberExit6_1(int number, int index)
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

void main()
{
	printf("정렬한 데이터 초기화 \n");

	MakeRandomNumber6_1();
	DisplayBuffer6_1();
	printf("정렬 후 데이터\n");
	SelectionSort6_1();
	DisplayBuffer6_1();
	printf("\n");
}

/*
 * bubble_sort6-3.c
 *
 *  Created on: 2018. 2. 6.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX     100
#define TRUE    1
#define FALSE   0

void MakeRandomNumber6_3(void);
void BubbleSort6_3(void);
void Displaybuffer6_3(void);
int IsNumberExit6_3(int, int);
int Buf[MAX];

void MakeRandomNumber6_3(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while(i < MAX)
	{
		Num = rand() % MAX;

		if(!IsNumberExit6_3(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void BubbleSort6_3(void)
{
	int i, j, dummy;

	for(i = MAX -1; i >= 0; i--)
	{
		for(j = 1; j <= i; j++)
		{
			if(Buf[j-1] > Buf[j])
			{
				dummy = Buf[j-1];
				Buf[j-1] = Buf[j];
				Buf[j] = dummy;
			}
		}
	}
}

void Displaybuffer6_3(void)
{
	int i;

	for(i = 0; i < MAX;i++)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%4d", Buf[i]);
	}
	printf("\n");
}

int IsNumberExit6_3(int number, int index)
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
	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber6_3();
	Displaybuffer6_3();
	printf("정렬 후 데이터\n");

	BubbleSort6_3();
	Displaybuffer6_3();
	printf("\n");
}

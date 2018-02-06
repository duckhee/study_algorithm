/*
 * insert_sort6_2.c
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

void MakeRandomNumber6_2(void);
void InsertionSort6_2(void);
void DisplayBuffer6_2(void);
int IsNumberExit6_2(int, int);
int Buf[MAX];

void MakeRandomNumber6_2(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while(i < MAX)
	{
		Num = rand() % MAX;

		if(!IsNumberExit6_2(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void InsertionSort6_2(void)
{
	int i, j, dummy;
	for(i = 0; i < MAX; i++)
	{
		dummy = Buf[i];
		j = i;

		while(Buf[j-1] > dummy && j >0)
		{
			Buf[j] = Buf[j-1];
			j--;
		}

		Buf[j] = dummy;
	}
}

void DisplayBuffer6_2(void)
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

int IsNumberExit6_2(int number, int index)
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

	MakeRandomNumber6_2();
	DisplayBuffer6_2();
	printf("정렬 후 데이터\n");

	InsertionSort6_2();
	DisplayBuffer6_2();
	printf("\n");
}

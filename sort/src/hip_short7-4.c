/*
 * hip_short7-4.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE           1
#define FALSE          0
#define MAX_INT        65536
#define MAX            100

void MakeRandomNumber7_4(void);
void HeapSort7_4(int);
void DisplayBuffer7_4(void);
int IsNumberExit7_4(int, int);
void upheadp7_4(int);
void downheadp7_4(int);
void InsertData7_4(int);
int RemoveData7_4(void);

int Buf[MAX];
int Data[MAX];
int temp[MAX];
int NUM;

void MakeRandomNumber7_4(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Data[0] = 100;

	while(i < MAX)
	{
		Num = rand() % MAX;

		if(!IsNumberExit7_4(Num, i))
		{
			Data[i] = Num;
			i++;
		}
	}
}

void HeapSort7_4(int N)
{
	int i;

	for(i = 0; i < MAX; i++)
	{
		InsertData7_4(Data[i]);
	}
	Data[0] = 1;
	for(i = MAX -1; i >= 0; i--)
	{
		Data[i] = RemoveData7_4();
	}
}

void DisplayBuffer7_4(void)
{
	int i;

	for(i = 0; i < MAX; i++)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%4d", Data[i]);

	}
	printf("\n");
}

int IsNumberExit7_4(int number, int index)
{
	int i;

	for(i = 0; i < index; i++)
	{
		if(Data[i] == number || number == 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

void upheadp7_4(int k)
{
	int v;
	v = Buf[k];
	Buf[0] = MAX_INT;

	while(Buf[k/2] <= v)
	{
		Buf[k] = Buf[k/2];
		k = k/2;
	}
	Buf[k] = v;
}


void downheadp7_4(int k)
{
	int i, v;
	v = Buf[k];

	while(k <= NUM/2)
	{
		i = 2*k;

		if(i < NUM && Buf[i] < Buf[i+1])
		{
			i++;
		}
		if(v >= Buf[i])
		{
			break;
		}

		Buf[k] = Buf[i];
		k = i;
	}
	Buf[k] = v;
}

void InsertData7_4(int v)
{
	Buf[++NUM] = v;
	upheadp7_4(NUM);
}

int RemoveData7_4(void)
{
	int v = Buf[1];
	Buf[1] = Buf[NUM--];
	downheadp7_4(1);

	return v;
}

void main()
{
	NUM = MAX;

	printf("정렬할 데이터 초기화\n");

	MakeRandomNumber7_4();
	DisplayBuffer7_4();
	printf("정렬 후 데이터\n");

	HeapSort7_4(NUM);
	DisplayBuffer7_4();
	printf("\n");

}

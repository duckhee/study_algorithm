/*
 * cell_sort6-4.c
 *
 *  Created on: 2018. 2. 6.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX        100
#define TRUE       1
#define FALSE      0

void MakeRandomNubmer6_4(void);
void ShellSort6_4(void);
void DisplayBuffer6_4(void);
int IsNumberExit6_4(int, int);

int Buf[MAX];

void MakeRandomNubmer6_4(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));

	Buf[0] = 100;

	while(i < MAX)
	{
		Num = rand() % MAX;
		if(!IsNumberExit6_4(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}


void ShellSort6_4(void)
{
	int i, j, h, v;
	for(h = 0; h < MAX; h = 3*h + 1);
	for(; h > 0; h/=3)
	{
		for(i = h; i < MAX; i++)
		{
			v = Buf[i];
			j = i;

			while(j >= h && Buf[j-h] > v)
			{
				Buf[j] = Buf[j-h];
				j -= h;
			}
			Buf[j] = v;
		}
	}
}

void DisplayBuffer6_4(void)
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

int IsNumberExit6_4(int number, int index)
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

	MakeRandomNubmer6_4();
	DisplayBuffer6_4();
	printf("정렬 후 데이터 \n");

	ShellSort6_4();
	DisplayBuffer6_4();
	printf("\n");

}

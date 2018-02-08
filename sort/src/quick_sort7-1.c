/*
 * quick_sort7-1.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX         100
#define TRUE        1
#define FALSE       0

void MakeRandomNumber7_1(void);
void QuickSort7_1(int data[], int, int);
void DisplayBuffer7_1(void);
int isNumberExit7_1(int, int);
int Buf[MAX];

void MakeRandomNumber7_1(void)
{

	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while(i < MAX)
	{
		Num = rand() % MAX;

		if(!isNumberExit7_1(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void QuickSort7_1(int data[], int left, int right)
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

		QuickSort7_1(data, left, i-1);
		QuickSort7_1(data, i+1, right);
	}
}

void DisplayBuffer7_1(void)
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

int isNumberExit7_1(int number, int index)
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

	MakeRandomNumber7_1();
	DisplayBuffer7_1();
	printf("정렬 후 데이터\n");

	QuickSort7_1(Buf, 0, MAX-1);

	DisplayBuffer7_1();
	printf("\n");
}

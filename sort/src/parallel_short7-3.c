/*
 * parallel_short7-3.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX      100
#define TRUE     1
#define FALSE    0

void MakeRandomNumber7_3(void);
void MergeSort7_3(int [], int, int);
void DisplayBuffer7_3(void);
int IsNumberExit7_3(int, int);
int Buf[MAX];
int temp[MAX];

void MakeRandomNumber7_3(void)
{
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while(i < MAX)
	{
		Num = rand() % MAX;

		if(!IsNumberExit7_3(Num, i))
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void MergeSort7_3(int data[], int left, int right)
{
	int i, j, k, middle;
	if(right > left)
	{
		middle = (left + right) / 2;

		MergeSort7_3(data, left, middle);
		MergeSort7_3(data, middle+1, right);

		for(i = middle+1; i > left; i--)
		{
			temp[i-1] = data[i -1];
		}
		for(j = middle; j < right; j++)
		{
			temp[right+middle-j] = data[j+1];
		}
		for(k = left; k <= right; k++)
		{
			data[k] = (temp[i] < temp[j]) ? temp[i++] :temp[j--];
		}
	}
}

void DisplayBuffer7_3(void)
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


int IsNumberExit7_3(int number, int index)
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

	MakeRandomNumber7_3();
	DisplayBuffer7_3();
	printf("정렬 후 데이터\n");

	MergeSort7_3(Buf, 0, MAX-1);
	DisplayBuffer7_3();
	printf("\n");
}

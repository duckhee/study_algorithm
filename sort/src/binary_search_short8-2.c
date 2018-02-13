/*
 * binary_search_short8-1.c
 *
 *  Created on: 2018. 2. 13.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX       100
#define TRUE      1
#define FALSE     0

void MakeRandomNumber8_2(void);
void QuickSort8_2(int [], int, int);
void DisplayBuffer8_2(void);
int IsNumberExit8_2(int, int);
int BinarySearch8_2(int);
int Buf[MAX];
int CompareCount;

void MakeRandomNumber8_2(void)
{
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while(i < MAX)
	{
		Num = rand() % 200;
		if(!IsNumberExit8_2(Num, i));
		{
			Buf[i] = Num;
			i++;
		}
	}
}

void QuickSort8_2(int data[], int left, int right)
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
		}

		temp = data[i];
		data[i] = data[right];
		data[right] = temp;

		QuickSort8_2(data, left, i-1);
		QuickSort8_2(data, i+1, right);
	}
}

void DisplayBuffer8_2(void)
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

int IsNumberExit8_2(int number, int index)
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

int BinarySearch8_2(int num)
{
	int left, right;
	int min;
	left = 0;
	right = MAX;

	while(right >= left)
	{
		CompareCount++;
		min = (left+right)/2;

		if(num < Buf[min])
		{
			right = min - 1;
		}else{
			left = min + 1;
		}
		if(num == Buf[min])
		{
			return min;
		}
	}
	return -1;
}

void main()
{
	int ret;
	CompareCount = 0;
	MakeRandomNumber8_2();
	QuickSort8_2(Buf, 0, MAX-1);
	printf("���ĵ� ������ \n");

	DisplayBuffer8_2();
	ret = BinarySearch8_2(23);

	if(ret == -1)
	{
		printf("\n23�̶�� �����Ͱ� ����.\n");

	}else
	{
		printf("\n23�̶�� �����Ͱ� %d��°�� �����Ѵ�.\n", ret);

	}
	printf("�� �� Ƚ���� %dȸ��.\n", CompareCount);
}
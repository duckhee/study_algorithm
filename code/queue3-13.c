/*
 * queue3-13.c
 *
 *  Created on: 2018. 1. 30.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>

#define MAX       100

int Queue[MAX];
int Front, Rear;

void InitializeQueue(void);
void Put(int);
int Get(void);
void DisplayQueue(void);

void InitializeQueue(void)
{
	Front = Rear = 0;

}

void Put(int num)
{
	Queue[Rear++] = num;

	if(Rear>= MAX)
	{
		Rear = 0;
	}

}

int Get(void)
{
	int ret;
	ret = Queue[Front++];

	if(Front >= MAX)
	{
		Front = 0;
	}

	return ret;
}

void DisplayQueue(void)
{
	int i;
	printf("Front -> ");

	for(i = Front; i < Rear; i++)
	{
		printf("%2d-> ", Queue[i]);
	}

	printf("Rear");
}

void main()
{
	int ret;
	InitializeQueue();
	Put(1);
	Put(3);
	Put(10);
	Put(20);
	Put(12);

	printf("after call five put function leter\n");
	DisplayQueue();

	ret = Get();
	ret = Get();
	ret = Get();

	printf("\nafter call three get function leter\n");
	DisplayQueue();

	printf("\nafter call two get function leter\n");

	ret = Get();
	ret = Get();
	DisplayQueue();
}

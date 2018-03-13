/*
 * hash_shotr9-3.c
 *
 *  Created on: 2018. 3. 13.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX   100
#define TRUE  1
#define FALSE 0

typedef struct _NODE
{
	int Key;
	int Counter;
} NODE;

void Initialize(void);
void MakeRandomNumber(void);
void DisplayBuffer(void);
void DisplayHitBuffer(void);
void DisplayHitCounter(void);

int Buf[MAX];
NODE Hit[50];

void Initialize(void)
{
	int i;

	for(i = 0; i < MAX; i++)
	{
		Buf[i] = -1;
	}

	for(i = 0; i < 20; i++)
	{
		Hit[i].Key = -1;
		Hit[i].Counter = 0;
	}
}

void MakeRandomNumber(void)
{
	int i, Num, index;
	i = 0;
	srand((unsigned)time(NULL));

	while(i < 50)
	{
		Num = rand() % 100;
		Buf[Num] = Num;

		index = Num % 50;

		Hit[index].Key = Num;
		Hit[index].Counter++;
		i++;
	}
}


void DisplayBuffer(void)
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

void DisplayHitBuffer(void)
{
	int i;

	printf("================> Hit Key Data <========================\n");

	for(i = 0; i < 50; i++)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%4d", Hit[i].Key);
	}
	printf("\n\n");
}

void DisplayHitCounter(void)
{
	int i;
	printf("=======>Hit Counter<==========\n");

	for(i = 0; i < 50; i++)
	{
		if((i % 10) == 0)
		{
			printf("\n");
		}
		printf("%4d", Hit[i].Counter);
	}
	printf("\n");
}

void main()
{
	Initialize();

	MakeRandomNumber();
	printf("key mapping栏肺 积己等 单捞磐 \n");

	DisplayBuffer();
	printf("\n");

	DisplayHitBuffer();
	DisplayHitCounter();
}

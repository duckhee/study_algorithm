/*
 * pointer_array2-13.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>

void PrintPointer(int (*)[2]);

void PrintPointer(int (*tptr)[2])
{
	int i;
	printf("함수 호출 후 \n");

	for(i = 0; i < 5; i++)
	{
		printf("tptr : 0x%p, **tptr : %d\n", tptr, **tptr);
		tptr++;
	}
}

void main()
{
	int i, j;
	int data[][2] = {{10, 20}, {30, 40}, {50, 60}, {70, 80}, {90,100}};
	int (*ptr)[2];
	ptr = data;
	printf("함수 호출 전\n");

	for(i = 0; i < 5; i++)
	{
		printf("ptr : 0x%p, **ptr : %d\n", ptr, **ptr);
		ptr++;
	}
	ptr = data;
	PrintPointer(ptr);
}

/*
 * pointer2-8.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>

void main()
{
	int data = 10;
	int *ptr;
	*ptr = data;

	printf("ptr : 0x%p, *ptr : %d\n", ptr, *ptr);

}

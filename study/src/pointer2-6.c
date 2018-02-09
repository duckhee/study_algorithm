/*
 * pointer2-6.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>

void main(void)
{
	int data = 10;
	int *ptr;

	printf("data address : 0x%p, data value : %d\n", &data, data);
	ptr = &data;

	printf("ptr address : 0x%p, ptr value : %p \n", &ptr, ptr);

	printf("ptr pointer : %d, data value : %d\n", *ptr, data);

	printf("ptr address : 0x%p, ptr value : 0x%p, ptr value : %d\n", &ptr, ptr, *ptr);
}

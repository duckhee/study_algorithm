/*
 * pointer2-5.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>

void main()
{
	int data = 10;
	int *ptr;

	printf("data address :  0x%p, data value : %d \n", &data, data);
	ptr = &data;

	printf("ptr address : 0x%p, ptr value : 0x%p \n", &ptr, ptr);
}

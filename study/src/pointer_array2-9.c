/*
 * pointer_array2-9.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>

void main()
{
	int data[5] = {10, 20, 30, 40, 50};
	int *ptr;
	ptr = data;
	printf("ptr : 0x%p, *ptr : %d\n", ptr, *ptr);

	ptr = &data[0];
	printf("ptr : 0x%p, *ptr : %d\n", ptr, *ptr);

}

/*
 * exam4.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>

void main()
{
	int i, value_new, value_1, value_2;

	printf("피보나치 수열을 구해보자\n");

	i = 0;
	value_1 = 1;
	value_2 = 0;

	while(i < 24)
	{
		value_new = value_1 + value_2;

		if(!(i%12))
		{
			printf("\n");
		}
		printf("%6d", value_new);

		value_2 = value_1;
		value_1 = value_new;
		i++;
	}
}

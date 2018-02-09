/*
 * exam_3-3.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 */




#include <stdio.h>

void main()
{
	int data1, data2;
	int i, num, max;
	printf("약수를 구할 두 정숫값을 입력하세요\n");

	printf("입력 1 : ");
	scanf("%d", &data1);
	printf("%d ", data1);

	printf("입력 2 : ");
	scanf("%d", &data2);
	printf("%d", data2);
	printf("\n");
	if(data1 > data2)
	{
		num = data2;
	}
	else
	{
		num = data1;
	}

	for(i = 1; i <= num; i++)
	{
		if(((data1%i) == 0) && ((data2%i) == 0))
		{
			max = i;
		}
	}
	printf("%d와 %d의 최대 공약수는 %d이다.\n", data1, data2, max);
}

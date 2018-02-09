/*
 * call_by_refernce_pointer2-16.c
 *
 *  Created on: 2018. 2. 9.
 *      Author: CANDH
 *  call by referenc란, 자료형을 pointer로 저장하는 것을 의미한다.?
 */




#include <stdio.h>

void Square(int, int *);

void Square(int lv, int *ret)
{
	if(lv == 2)
	{
		*ret = *ret * *ret;
	}
	else if(lv ==3)
	{
		*ret = *ret * *ret * *ret;
	}
}

void main()
{
	int number, level;
	printf("C 프로그래밍에서의 포인터 사용 예 - 두번째 \n");

	level = 2;
	number = 3;
	Square(level, &number);
	printf("Level : %d Return Value : %d\n", level, number);

	printf("\n");

	level = 3;
	number = 4;
	Square(level, &number);

	printf("Level : %d Return Value : %d\n", level, number);
}

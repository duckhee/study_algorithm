/*
 * exam_1.c
 *
 *  Created on: 2018. 1. 30.
 *      Author: CANDH
 */




#include<stdio.h>

void main()
{

	char key;
	int data;


	printf("10진수->16진수 변환 프로그램\n");
	printf("10진수를 16진수로 바꾸려면, [A] 키를 누르고, \n");
	printf("16진수를 10진수로 바꾸려면, [B] 키를 누르시오 \n");
	printf("a나 b를 누르시오 : ");


	scanf("%c", &key);
	printf("변환할 숫자를 입력하시오 : ");

	if(key == 'a' || 'A')
	{
		scanf("%d", &data);
		printf("10진수 값 : %d --> 16진수 값 : %x\n", data, data);
	}
	else if(key == 'b' || 'B')
	{
		scanf("%x", &data);
		printf("16진수 값  : %x --> 10진수 값 : %d", data, data);

	}
	else
	{
		printf("[A],[B] 둘 중에 하나만 눌러야 합니다.");
	}

}

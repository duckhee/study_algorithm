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


	printf("10����->16���� ��ȯ ���α׷�\n");
	printf("10������ 16������ �ٲٷ���, [A] Ű�� ������, \n");
	printf("16������ 10������ �ٲٷ���, [B] Ű�� �����ÿ� \n");
	printf("a�� b�� �����ÿ� : ");


	scanf("%c", &key);
	printf("��ȯ�� ���ڸ� �Է��Ͻÿ� : ");

	if(key == 'a' || 'A')
	{
		scanf("%d", &data);
		printf("10���� �� : %d --> 16���� �� : %x\n", data, data);
	}
	else if(key == 'b' || 'B')
	{
		scanf("%x", &data);
		printf("16���� ��  : %x --> 10���� �� : %d", data, data);

	}
	else
	{
		printf("[A],[B] �� �߿� �ϳ��� ������ �մϴ�.");
	}

}

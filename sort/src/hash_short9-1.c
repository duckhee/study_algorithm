/*
 * hash_short9-1.c
 *
 *  Created on: 2018. 3. 13.
 *      Author: CANDH
 */




#include <stdio.h>

typedef struct _NODE{
	int number;
	char Name;

} NODE ;

NODE Students[10];

void main()
{
	int i;

	for(i = 0; i < 10; i++)
	{
		Students[i].number = 1000 + i;
		Students[i].Name = 'A'+i;
	}

	printf("�ټ� ��° �л��� �й��� �̸� ��� \n");
	printf("�й� : [%d]\n", Students[4].number);
	printf("�̸� : [%c]\n", Students[4].Name);
}

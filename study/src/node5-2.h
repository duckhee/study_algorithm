/*
 * node5-2.h
 *
 *  Created on: 2018. 2. 8.
 *      Author: CANDH
 */

#ifndef NODE5_2_H_
#define NODE5_2_H_


#include <stdio.h>

#define TRUE       1
#define FALSE      0

typedef struct _NODE
{
	char Data;
	int Balance;
	struct _NODE *Left;
	struct _NODE *Right;
} NODE;

NODE *HeadNode, *EndNode;



#endif /* NODE5_2_H_ */

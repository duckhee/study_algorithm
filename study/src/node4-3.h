/*
 * node.h
 *
 *  Created on: 2018. 1. 30.
 *      Author: CANDH
 */

#ifndef NODE4_3_H_
#define NODE4_3_H_

#include <stdio.h>
#include <stdlib.h>

#define TRUE     1
#define FALSE    0

typedef struct _NODE
{
	char Data;
	struct _NODE *Left;
	struct _NODE *Right;

} NODE;

NODE *HeadNode, *EndNode;



#endif /* NODE4_3_H_ */

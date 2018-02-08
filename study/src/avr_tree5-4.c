/*
 * avr_tree5-4.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: CANDH
 */




#include <stdio.h>
#include <stdlib.h>
#include "node5-2.h"

#define TRUE      1
#define FALSE     0

NODE *HeadNode;
NODE *ParentNode;
NODE *GrandNode;
NODE *ChildNode;
NODE *BigNode;

void InitializeTree5_4(void);
void InsertNode5_4(int);
int IsBalance5_4(void);
void RR_Rotate5_4(void);
void Level_Traverse5_4(NODE *);
void Visit5_4(NODE *);

extern void InitializeQueue5_2(void);
extern void Put5_2(NODE *);
extern NODE *Get5_2(void);
extern int IsQueueEmpty5_3(void);


void InitializeTree5_4(void);
void InsertNode5_4(int);
int IsBalance5_4(void);
void RR_Rotate5_4(void);
void Level_Traverse5_4(NODE *);
void Visit5_4(NODE *);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

typedef struct SpaceNode
{
	struct SpaceNode* llink;//指向前驱空间 
	int tag;//标志，0空闲，1占用 
	int size;
	struct SpaceNode* rlink;//指向后继空间 
}SpaceNode;//内存块类型 

typedef struct HeadNode
{
	int size;
	SpaceNode* first;//指向内存块 
}FreeList[4];//内存字头结点类型，也代表整个空闲内存块 

//全局变量
SpaceNode *start,*end;//内存的起点和终点 


int InitSpace_b(FreeList available);

SpaceNode* AllocBuddy(FreeList available, int n);//n为申请分配量 

int PrintLayout_b(FreeList available); 

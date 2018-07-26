#include <stdio.h>
#include "../../01intro/Status.h"
#include "../../01intro/Scanf.c"

#define FootLocate(p) p+(p)->size-1//指向p所指节点的底部 

typedef struct SpaceNode
{
	union
	{
		struct SpaceNode* llink;//左指针，指向前驱 
		struct SpaceNode* uplink;//底部指针，指向本节点头部 
	}Ptr;
	int tag;//标志，0空闲，1占用 
	int size;
	struct SpaceNode* rlink;
}SpaceNode;

//全局变量 
SpaceNode* start;//整个space的起始地址



int InitSpace(SpaceNode memory[1002]);

SpaceNode* AllocBoundTag(SpaceNode* *pstart, int n);//分配算法，首次拟合法，传入所有空闲块的起始地址和请求分配n个字，返回分配的空闲块 

int Reclaim(SpaceNode* *pstart, SpaceNode* *p);//回收算法

int PrintLayout(SpaceNode* start, SpaceNode* pstart);//输出当前内存块的起止地址 

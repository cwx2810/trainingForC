#include "BuddySystem.h"

int InitSpace_b(FreeList available)
{
	for(int i=0; i<=3; i++)
	{
		available[i].size = (int)pow(2, i);//计算2的i次方 
		available[i].first = 0;
	}
	
	SpaceNode* r = (SpaceNode*)malloc((int)pow(2,3)*sizeof(SpaceNode));
	if(!r)
		return 0;
	r->llink = r->rlink = r;
	r->tag = 0;
	r->size = 3;
	
	available[3].first = r;//第三块表指向分配的空间r 
	
	start = r;
	end = r + available[3].size - 1;
	
	return 1;
}

SpaceNode* AllocBuddy(FreeList available, int n)
{
	int i;
	SpaceNode* pstart;
	for(i=0; i<=3 && (available[i].size<n || !available[i].first); i++)//找到大于申请空间的空闲块，如果小于申请空间或者该表未分配SpaceNode，则继续遍历 
		;
	if(i>3)
		return 0;
	else
	{
		pstart = available[i].first;
		SpaceNode* pre = pstart->llink;
		SpaceNode* next = pstart->rlink;
		
		//找到分配空闲空间的第一个节点 
		if(pstart==next)
			available[i].first = 0;
		else
		{
			pre->rlink = next;
			next->llink = pre;
			available[i].first = next;
		}
		
		int j;
		for(j=1; i-j>=0 && available[i-j].size>=n; j++)
		{
			SpaceNode* p = pstart + (int)pow(2, i-j);
			p->rlink = p;
			p->llink = p;
			p->tag = 0;
			p->size = i-j;
			available[i-j].first = p;
		}
		
		pstart->tag = 1;
		j--;
		pstart->size = i-j;
	}
	return pstart;
}

int PrintLayout_b(FreeList available)
{
	int mark;
	int i;
	for(i=0,mark=0; i<=3; i++)//判断内存是否被占满 
	{
		if(available[i].first)
		{
			mark = 1;
			break;
		}
	}
	
	if(!mark)
		printf("内存已满");
	else
	{
		printf("空闲块起止范围：");
		for(i=0; i<=3; i++)
		{
			SpaceNode* r = available[i].first;
			if(r)
			{
				printf("|%d--%d", r-start+1, r+(int)pow(2, r->size)-start);
				//printf("%d", r->rlink);
				//printf("%d", available[i].first);
				while(r->rlink!=available[i].first)
				{
					r = r->rlink;
					printf("|%d--%d", r-start+1, r+(int)pow(2, r->size)-start);
				}
			}
		}
	}
	printf("\n");
	return 1;
}

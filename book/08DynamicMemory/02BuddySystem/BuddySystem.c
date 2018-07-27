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
	for(i=0; i<=3 && (available[i].size<n || !available[i].first); i++)//找到大于申请空间的可分配表，如果小于申请空间或者该表未分配SpaceNode，则继续遍历 
		;
	if(i>3)
		return 0;
	else							//进行分配 
	{
		pstart = available[i].first;//指向可分配子表的第一个spaceNode 
		SpaceNode* pre = pstart->llink;//设置前驱和后继 
		SpaceNode* next = pstart->rlink;
		
		//下面这段ifelse好像没有用到，可能其他函数中会用到 
		if(pstart==next)//如果可分配子表的第一个节点没有后继，则下一次就不能分配了，重新设置第一个节点为置空 
			available[i].first = 0;
		else			//如果有后继，则去掉链表中已经分配的空间，重新设置第一个节点为其原来的后继 
		{
			pre->rlink = next;
			next->llink = pre;
			available[i].first = next;
		}
		
		int j;
		for(j=1; i-j>=0 && available[i-j].size>=n; j++)//首次，将找到的子表的空间再次进行划分，分给没有分配过空间的子表，比如一开始有8的完整空间，分了1，还剩7分给0、1、2号子表1、2、4的空间，符合其size 
		{												//后面要申请的空间都刚好，不会再用到这个划分算法 
			SpaceNode* p = pstart + (int)pow(2, i-j);
			p->rlink = p;
			p->llink = p;
			p->tag = 0;
			p->size = i-j;
			available[i-j].first = p;
		}
		
		pstart->tag = 1;//空间已占用 
		j--;
		pstart->size = i-j;//已经占用的空间的大小 
	}
	return pstart;
}

int PrintLayout_b(FreeList available)
{
	int mark=0;
	for(int i=0; i<=3; i++)//判断内存是否被占满 
	{
		if(available[i].first)
		{
			mark = 1;
			break;
		}
	}
	
	if(mark==0)
		printf("内存已满");
	else
	{
		printf("空闲块起止范围：");
		for(int i=0; i<=3; i++)//输出每个子表的空闲块起止范围 
		{
			SpaceNode* r = available[i].first;
			if(r)
			{
				printf("|%d--%d", r-start+1, r+(int)pow(2, r->size)-start);//只用到了这里 
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

#include "BoundaryTagMethod.h"

int InitSpace(SpaceNode memory[1002])
{
	SpaceNode* pstart = &memory[0];//初始化空间的起始地址 
	
	memory[0].Ptr.llink = pstart;
	memory[0].tag = 0;
	memory[0].size = 1000;
	memory[0].rlink = pstart;
	
	memory[999].Ptr.uplink = pstart;
	memory[999].tag = 0;
	
	start = pstart;
	return 1;
}

SpaceNode* AllocBoundTag(SpaceNode **pstart, int n)
{
	SpaceNode* p;//保存分配的空闲块 
	//遍历空闲块，如果有比n大的，跳出循环，也就是要请求n个字，就要找到比n大的空闲块 
	for(p=*pstart; p && p->size<n && p->rlink!=*pstart; p=p->rlink)
		;
	if(!p || p->size<n)//寻找失败 
		return 0;
	else
	{
		SpaceNode* foot;
		foot = FootLocate(p);//foot指向空闲块的底部 
		*pstart = p->rlink;//pstart指向p的后继空闲块 
		if(p->size-n < 10)//找到的空间大小和所需的空间大小的误差不超过10个字 
		{
			if(*pstart==p)//如果p的后继指向p，说明只有一个空闲块，置空没用的指针 
				*pstart = 0;
			else
			{
				(*pstart)->Ptr.llink = p->Ptr.llink;//把分配过空间的空闲块从链表中去掉
				p->Ptr.llink->rlink = *pstart; 
			}
		}
		else			//误差大于10个字则分成两块 
		{
			foot->tag = 1;
			
			p->size -= n;//调整p的前部为空间误差大小，即把得到的空闲块分成两个空闲块，前面是大误差，后面是刚好n个字 
			foot = FootLocate(p);
			foot->tag = 0;
			foot->Ptr.uplink = p;
			
			p = foot+1;//p指向后面那块刚好n个字的块的头部 
			p->tag = 1;
			p->size = n; 
		}
		return p;
	}
}

int Reclaim(SpaceNode **pstart, SpaceNode **p)
{
	//未完待续 
	return 1;
}

int PrintLayout(SpaceNode* start, SpaceNode* pstart)
{
	SpaceNode* r;//移动游标尾指针
	r = pstart;
	printf("空闲块起止范围：|");
	printf("%4d--%4d | ", r-pstart+1, r+r->size-pstart);
	//printf("%d", r->rlink);
	//printf("%d", pstart);
	while(r->rlink!=pstart)
	{
		r = r->rlink;
		printf("%4d--%4d | ", r-pstart+1, r+r->size-pstart);
	} 
	printf("\n");
}

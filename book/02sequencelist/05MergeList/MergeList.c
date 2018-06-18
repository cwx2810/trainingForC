#include "MergeList.h"

int MergeList_L(LNode **La, LNode **Lb, LNode **Lc)
{
	(*Lc) = (LNode*)malloc(sizeof(LNode));
	if(!(*Lc))
		return 0;
	(*Lc)->next = NULL;//建立Lc头结点待插入 
	
	LNode* pa = (*La)->next;
	LNode* pb = (*Lb)->next;
	LNode* pc = (*Lc);
	
	while(pa!=NULL && pb!=NULL)//循环扫描La和Lb，插入小的结点 
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
		else
		{
			pc->next= pb;
			pc = pc->next;
			pb = pb->next;
		}
	}
	if(pa!=NULL)//剩下La 
		pc->next = pa;
	if(pb!=NULL)//剩下Lb 
		pc->next = pb;
		
	free(*La);//避免悬空指针 
	(*La) = NULL;
	free(*Lb);
	(*Lb) = NULL;
	
	return 1;
	
}


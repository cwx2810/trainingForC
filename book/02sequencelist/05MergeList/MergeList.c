#include "MergeList.h"

int MergeList_L(LNode **La, LNode **Lb, LNode **Lc)
{
	(*Lc) = (LNode*)malloc(sizeof(LNode));
	if(!(*Lc))
		return 0;
	(*Lc)->next = NULL;//����Lcͷ�������� 
	
	LNode* pa = (*La)->next;
	LNode* pb = (*Lb)->next;
	LNode* pc = (*Lc);
	
	while(pa!=NULL && pb!=NULL)//ѭ��ɨ��La��Lb������С�Ľ�� 
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
	if(pa!=NULL)//ʣ��La 
		pc->next = pa;
	if(pb!=NULL)//ʣ��Lb 
		pc->next = pb;
		
	free(*La);//��������ָ�� 
	(*La) = NULL;
	free(*Lb);
	(*Lb) = NULL;
	
	return 1;
	
}


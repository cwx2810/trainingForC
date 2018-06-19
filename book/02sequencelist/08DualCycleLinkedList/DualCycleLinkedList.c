#include "DualCycleLinkedList.h"

int InitList_DL(DNode **L)
{
	*L = (DNode*)malloc(sizeof(DNode));
	if(!(*L))
		return 0;
	(*L)->next = (*L)->prior = (*L);//循环起来，避免野指针 
	return 1; 
}

int ClearList_DL(DNode* L)
{
	DNode* p = L->next;
	DNode* tmp;
	while(p!=L)//这里体现不同了，p不等于头指针说明p存在 
	{
		tmp = p->next;//临时保存p的下个节点 
		free(p);
		p = tmp;//p重新代表p的下个节点 
	}
	
	L->next= L->prior= L;//避免野指针 
	return 1;
}

int DestroyList_DL(DNode **L)
{
	ClearList_DL(*L);
	free(*L);
	*L = NULL;//避免野指针 
}

int ListEmpty_DL(DNode *L)
{
	if(L && L->next==L && L->prior==L)
		return 1;
	else
		return 0;
}

int ListLength_DL(DNode *L)
{
	if(!L)
		return 0;
	int count = 0;
	DNode* p = L;		//p指向头结点 
	while(p->next != L)	//p没到头 
	{
		count++;
		p = p->next;
	}
	return count;
}

int GetElem_DL(DNode* L, int i, int *e)
{
	if(!L || i<1)
		return 0;
		
	int count = 1;
	DNode* p = L->next;//p指向第一个节点
	while(p!=L && count<i)//p没到头且没遍历到第i个元素 
	{
		count++;
		p = p->next;
	} 
	if(p!=L)
	{
		*e = p->data;
		return 1;
	}
	return 0;
}

int LocateElem_DL(DNode* L, int e, int(Compare)(int ,int))
{
	if(!L)
		return 0;
	int count = 1;
	DNode* p = L->next;
	while(p!=L && !Compare(e, p->data))
	{
		count++;
		p = p->next;
	}
	if(p!=L)
		return count;
	return 0;
}

int PriorElem_DL(DNode* L, int cur_e, int *pre_e)
{
	if(!L)
		return 0;
	DNode* p = L->next;
	while(p!=L && p->data!=cur_e)
		p = p->next;
	if(p!=L && p->prior!=L)//p不为第一个节点才能有前驱 
	{
		*pre_e = p->prior->data;
		return 1;
	} 
	return 0;
}

int NextElem_DL(DNode* L, int cur_e, int *next_e)
{
	if(!L)
		return 0;
	DNode* p = L->next;
	while(p!=L && p->data!=cur_e)
		p = p->next;
	if(p!=L && p->next!=L)//p不为最后一个节点才能有后继 
	{
		*next_e = p->next->data;
		return 1;
	}
	return 0;
}

DNode* GetElemPtr_DL(DNode* L, int i)
{
	if(!L || i<1)
		return 0;
	int count = 1;
	DNode* p = L->next;
	while(p!=L && count<i)
	{
		count++;
		p = p->next;
	}
	if(p!=L)
		return p;
	return NULL;
}

int ListInsert_DL(DNode* L, int i, int e)//这个insert不能仿写，因为双循环链表的判空和单链表不一样 
{
	if(!L || i<1)//L不存在或者i过小 
		return 0;
	int count = 1;
	DNode* p = L->next;//p跟随count一起指向要插入的位子，s要插在p前面 
	while(p!=L && count<i)
	{
		count++;
		p = p->next;
	}
	if(p==L&&count<i)//i过大，链表到头了还是没数完
		return 0;
	
	DNode* s = (DNode*)malloc(sizeof(DNode));
	if(!s)
		return 0;
	s->data = e;
	
	s->next = p;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;
	
	return 1;
}


int ListDelete_DL(DNode* L, int i, int *e)
{
	if(!L || i<1)
		return 0;
	DNode* p = L->next;
	int count = 1;
	while(p!=L && count<i)
	{
		count++;
		p = p->next;
	}
	if(p!=L)
	{
		*e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		p = NULL;
		return 1;
	}
	return 0;
}

int ListTraverse_DL(DNode* L, void(Visit)(int))
{
	if(!L)
		return 0;
	DNode* p = L->next;
	while(p!=L)
	{
		Visit(p->data);
		p = p->next;
	}
	return 1;
}


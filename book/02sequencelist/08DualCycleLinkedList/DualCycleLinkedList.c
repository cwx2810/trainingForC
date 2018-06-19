#include "DualCycleLinkedList.h"

int InitList_DL(DNode **L)
{
	*L = (DNode*)malloc(sizeof(DNode));
	if(!(*L))
		return 0;
	(*L)->next = (*L)->prior = (*L);//ѭ������������Ұָ�� 
	return 1; 
}

int ClearList_DL(DNode* L)
{
	DNode* p = L->next;
	DNode* tmp;
	while(p!=L)//�������ֲ�ͬ�ˣ�p������ͷָ��˵��p���� 
	{
		tmp = p->next;//��ʱ����p���¸��ڵ� 
		free(p);
		p = tmp;//p���´���p���¸��ڵ� 
	}
	
	L->next= L->prior= L;//����Ұָ�� 
	return 1;
}

int DestroyList_DL(DNode **L)
{
	ClearList_DL(*L);
	free(*L);
	*L = NULL;//����Ұָ�� 
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
	DNode* p = L;		//pָ��ͷ��� 
	while(p->next != L)	//pû��ͷ 
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
	DNode* p = L->next;//pָ���һ���ڵ�
	while(p!=L && count<i)//pû��ͷ��û��������i��Ԫ�� 
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
	if(p!=L && p->prior!=L)//p��Ϊ��һ���ڵ������ǰ�� 
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
	if(p!=L && p->next!=L)//p��Ϊ���һ���ڵ�����к�� 
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

int ListInsert_DL(DNode* L, int i, int e)//���insert���ܷ�д����Ϊ˫ѭ��������пպ͵�����һ�� 
{
	if(!L || i<1)//L�����ڻ���i��С 
		return 0;
	int count = 1;
	DNode* p = L->next;//p����countһ��ָ��Ҫ�����λ�ӣ�sҪ����pǰ�� 
	while(p!=L && count<i)
	{
		count++;
		p = p->next;
	}
	if(p==L&&count<i)//i��������ͷ�˻���û����
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


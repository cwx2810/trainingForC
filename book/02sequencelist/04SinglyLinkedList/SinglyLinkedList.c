#include "SinglyLinkedList.h"

int InitList_L(LNode **L)//*L����������ָ��С�ṹ��ָ�룬�����ھʹ���ȡ��С�ṹ���� 
{
	(*L) = (LNode*)malloc(sizeof(LNode));//��С�ṹ�������ռ� 
	if(!(*L))
		return 0;
	(*L)->next = NULL;//ʱ���μǽڵ��next�ÿգ�����Ұָ�� 
	return 1;
}

int ClearList_L(LNode* L)//L����С�ṹ���ں������ǻ��һ�����ܸı��С�ṹ(��ΪLС�ṹ��ʵ��ָ�룬�����ں�����Ҳ��ʾ���) 
{						//�Ա�˳����У�L�ǻ�ò��ܸı������˳���ṹ����������ֻ��һ��С�� 	
	if(!L)//��������жϣ���Ȼ���ͷ�����Ĳ����ڣ�����ͻ����ò������ڵ�ָ�� 
		return 0;
		
	LNode* p;	
	while(L->next)
	{
		p = L->next->next;
		free(L->next);
		L->next = p;
	}
	
	L->next = NULL;//֮ǰfree�˳���ͷ����Ľڵ㣬���ڰ�ͷ����next�ÿգ�����Ұָ�룬����ѽ 
	return 1;
}

int DestroyList_L(LNode **L)
{
	LNode* p = *L;
	while(p)
	{
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
	return 1;
}

int ListEmpty_L(LNode* L)
{
	if(L!=NULL && L->next==NULL)
		return 1;
	else
		return 0;
}

int ListLength_L(LNode* L)
{
	if(!L)
		return 0;
	LNode* p = L->next;
	int i = 0;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem_L(LNode* L, int i, int *e)
{
	LNode* p = L->next;
	int j = 1;
	while(p!=NULL && j<i)//��ͷ�������� 
	{
		p = p->next;
		j++;
	}
	while(p==NULL || j>i)//i�����ڣ�����p==NULL������i����������j>i�������ж�iΪ0����� 
		return 0;
	*e = p->data;
	return 1;
}

int LocateElem_L(LNode* L, int e, int(Compare)(int, int))
{
	if(!L)
		return 0;
	LNode* p = L->next;
	int i = 1;
	while(p!=NULL && !Compare(e, p->data))
	{
		p = p->next;
		i++;
	}
	if(p!=NULL)
		return i;
	else
		return 0;
}

int PriorElem_L(LNode* L, int cur_e, int *pre_e)
{
	if(!L)
		return 0;
	LNode* p = L->next;
	if(p->data!=cur_e)//��һ���ڵ���ǰ�� 
	{
		while(p->next!=NULL)//һֱ�����ڵ�ĺ�̣�����Ȳ�����cur_e�������˾�˵���ڵ���ǰ�� 
		{
			if(p->next->data==cur_e)
			{
				*pre_e = p->data;
				return 1;
			}
			p = p->next;
		}
	}
	return 0;
}

int NextElem_L(LNode* L, int cur_e, int *next_e)
{
	if(!L)
		return 0;
	LNode* p = L->next;
	while(p->next!=NULL)
	{
		if(p->data==cur_e)
		{
			*next_e = p->next->data;
			return 1;
		}
		p = p->next;
	}
	return 0;
}

int ListInsert_L(LNode* L, int i, int e)
{
	LNode* p = L;
	int j = 1;
	while(p!=NULL && j<i)
	{
		p = p->next;
		j++;
	}
	if(p==NULL || j>i)//ǰ�涼�Ǽ��L��i�ĺϷ��ԣ���Ϊ������ֱ�ӵó����ȣ�Ҫ���� 
		return 0;
		
	LNode* s = (LNode*)malloc(sizeof(LNode));//��e�����洢С�ṹ 
	if(!s)
		return 0;
	s->data = e;
	s->next = p->next;
	p->next= s;
	return 1;
}

int ListDelete_L(LNode* L, int i, int *e)
{
	if(!L)
		return 0;
	LNode* pre = L;  //�������Ҫ��pre����Ϊ����ɾ��ƴ��Ҫ�õ�ǰ��ڵ��ָ�� 
	int j = 1;
	while(pre->next!=NULL && j<i)
	{
		pre = pre->next;
		j++;
	}
	if(pre->next==NULL || j>i)//����֮ǰ�����жϺϷ��� 
		return 0;
		
	LNode* p = pre->next;
	*e = p->data;
	pre->next = pre->next->next;
	free(p);
	return 1;
}

int ListTraverse_L(LNode* L, void(Visit)(int))
{
	if(!L)
		return 0;
	LNode* p = L->next;
	while(p)
	{
		Visit(p->data);
		p = p->next;
	}
	return 1;
}

int CreateList_HL(FILE *fp, LNode **L, int n)
{
	(*L) = (LNode*)malloc(sizeof(LNode));
	if(!(*L))
		return 0;
	(*L)->next = NULL;//�����ǳ�ʼ��ͷ���ռ�
	
	int tmp;
	for(int i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d", &tmp)==1)
		{
			LNode* p = (LNode*)malloc(sizeof(LNode));//����������ݽ���С�ṹ 
			if(!p)
				return 0;
			p->data = tmp;
			p->next = (*L)->next;//ͷ��
			(*L)->next = p; 
		}
		else
			return 0;
	} 
	return 1;
}

int CreateList_TL(FILE *fp, LNode **L, int n)
{
	(*L) = (LNode*)malloc(sizeof(LNode));
	if(!(*L))
		return 0;
	(*L)->next = NULL;
	
	int tmp;
	LNode* r = *L;//βָ��
	for(int i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d", &tmp)==1)
		{
			LNode* p = (LNode*)malloc(sizeof(LNode));//����������ݽ���С�ṹ 
			if(!p)
				return 0;
			p->data = tmp;
			r->next = p;
			r = r->next;
		}
		else
			return 0;
	} 
	r->next = NULL;
	return 1;
}



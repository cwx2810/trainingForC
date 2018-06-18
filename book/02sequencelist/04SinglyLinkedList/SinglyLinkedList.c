#include "SinglyLinkedList.h"

int InitList_L(LNode **L)//*L在这是声明指向小结构的指针，在体内就代表取到小结构本体 
{
	(*L) = (LNode*)malloc(sizeof(LNode));//给小结构本身分配空间 
	if(!(*L))
		return 0;
	(*L)->next = NULL;//时刻牢记节点的next置空，避免野指针 
	return 1;
}

int ClearList_L(LNode* L)//L声明小结构，在函数内是获得一个不能改变的小结构(因为L小结构其实是指针，所以在函数内也表示获得) 
{						//对比顺序表中，L是获得不能改变的整个顺序表结构，而链表中只是一个小链 	
	if(!L)//这个必须判断，不然如果头结点真的不存在，后面就会设置并不存在的指针 
		return 0;
		
	LNode* p;	
	while(L->next)
	{
		p = L->next->next;
		free(L->next);
		L->next = p;
	}
	
	L->next = NULL;//之前free了除了头结点后的节点，现在把头结点的next置空，避免野指针，精髓呀 
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
	while(p!=NULL && j<i)//从头遍历链表 
	{
		p = p->next;
		j++;
	}
	while(p==NULL || j>i)//i不存在，其中p==NULL代替了i过大的情况，j>i代替了判断i为0的情况 
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
	if(p->data!=cur_e)//第一个节点无前驱 
	{
		while(p->next!=NULL)//一直遍历节点的后继，看其等不等于cur_e，等于了就说明节点是前驱 
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
	if(p==NULL || j>i)//前面都是检查L和i的合法性，因为链表不能直接得出长度，要遍历 
		return 0;
		
	LNode* s = (LNode*)malloc(sizeof(LNode));//给e建立存储小结构 
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
	LNode* pre = L;  //这里必须要设pre，因为链表删除拼接要拿到前后节点的指针 
	int j = 1;
	while(pre->next!=NULL && j<i)
	{
		pre = pre->next;
		j++;
	}
	if(pre->next==NULL || j>i)//这里之前都是判断合法性 
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
	(*L)->next = NULL;//以上是初始化头结点空间
	
	int tmp;
	for(int i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d", &tmp)==1)
		{
			LNode* p = (LNode*)malloc(sizeof(LNode));//给插入的数据建立小结构 
			if(!p)
				return 0;
			p->data = tmp;
			p->next = (*L)->next;//头插
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
	LNode* r = *L;//尾指针
	for(int i=1; i<=n; i++)
	{
		if(Scanf(fp, "%d", &tmp)==1)
		{
			LNode* p = (LNode*)malloc(sizeof(LNode));//给插入的数据建立小结构 
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



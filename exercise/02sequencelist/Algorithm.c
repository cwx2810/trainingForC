#include "Sequencelist.h"

//比较顺序表后缀大小 
int CmpSqList(SqList A, SqList B)
{
	int i=0;
	while(i<A.length && i< B.length)//扫描A、B，相等就继续扫描，不等就可以出大小了 
	{
		if(A.elem[i] > B.elem[i])
			return 1;
		else if(A.elem[i] < B.elem[i])
			return -1;
		else
			i++;
	}
	
	if(i<A.length)//A还有剩余，A大 
		return 1;
	else if(i<B.length)//B还有剩余，B大 
		return -1;
	else 				//扫描完了，相等 
		return 0;
}

//顺序表就地逆置 
int ReverseSqList(SqList L)
{
	if(L.length==0)
		return 0;
	int i=(L.length)/2;
	for(int j=1; j<=i; j++)//就地逆置 
	{
		int tmp = L.elem[j-1];//下标比序号小1 
		L.elem[j-1] = L.elem[L.length-j];
		L.elem[L.length-j] = tmp;
	}
	return 1;
}

//单链表就地逆置 
int ReverseLinkList(LinkList L)
{
	LinkList p, pre;
	
	if(!L || !L->next)//链表不存在或只有头结点（链表为空） 
		return 0;
		
	p = L->next;
	L->next = NULL;
	
	while(p)			//头插法，从头结点后的第一个节点开始，依次头插到头结点后，就翻转了 
	{
		//移动操作 
		pre = p;
		p = p->next;
		//插入操作 
		pre->next = L->next;
		L->next = pre;
	}
}




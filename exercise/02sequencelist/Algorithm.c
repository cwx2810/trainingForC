#include "Sequencelist.h"

//�Ƚ�˳����׺��С 
int CmpSqList(SqList A, SqList B)
{
	int i=0;
	while(i<A.length && i< B.length)//ɨ��A��B����Ⱦͼ���ɨ�裬���ȾͿ��Գ���С�� 
	{
		if(A.elem[i] > B.elem[i])
			return 1;
		else if(A.elem[i] < B.elem[i])
			return -1;
		else
			i++;
	}
	
	if(i<A.length)//A����ʣ�࣬A�� 
		return 1;
	else if(i<B.length)//B����ʣ�࣬B�� 
		return -1;
	else 				//ɨ�����ˣ���� 
		return 0;
}

//˳���͵����� 
int ReverseSqList(SqList L)
{
	if(L.length==0)
		return 0;
	int i=(L.length)/2;
	for(int j=1; j<=i; j++)//�͵����� 
	{
		int tmp = L.elem[j-1];//�±�����С1 
		L.elem[j-1] = L.elem[L.length-j];
		L.elem[L.length-j] = tmp;
	}
	return 1;
}

//������͵����� 
int ReverseLinkList(LinkList L)
{
	LinkList p, pre;
	
	if(!L || !L->next)//�������ڻ�ֻ��ͷ��㣨����Ϊ�գ� 
		return 0;
		
	p = L->next;
	L->next = NULL;
	
	while(p)			//ͷ�巨����ͷ����ĵ�һ���ڵ㿪ʼ������ͷ�嵽ͷ���󣬾ͷ�ת�� 
	{
		//�ƶ����� 
		pre = p;
		p = p->next;
		//������� 
		pre->next = L->next;
		L->next = pre;
	}
}




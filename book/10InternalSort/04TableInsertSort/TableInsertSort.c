#include "TableInsertSort.h"

int TableInsertSort(SLSortList* L)
{
	for(int i=1; i<=L->length; i++)//��ָ��������� 
	{
		int k,j;
		for(k=0, j=L->record[k].next; j&&Left(L->record[j].rc.key, L->record[i].rc.key); k=j, j=L->record[k].next)
			;
		L->record[i].next = j;
		L->record[k].next = i;
	}
	Arrange(L);//�Լ�¼�������� 
	return 1;
}

int Arrange(SLSortList* L)
{
	int p = L->record[0].next;//pָ���ͷ 
	for(int i=1; i<=L->length; i++)
	{
		while(p<i)
			p = L->record[p].next;
		int q = L->record[p].next;//qָ����δ�����ı�β 
		if(p!=i)
		{
			SLNode tmp = L->record[p];//������¼��ʹ��i����¼��λ 
			L->record[p] = L->record[i];
			L->record[i] = tmp;
			
			L->record[i].next = p;//ָ�����ߵļ�¼��ʹ���Ժ������whileѭ���һ� 
		}
		p = q;//pָ����δ�����ı�β��Ϊ�ҵ�i+1����¼��׼�� 
	}
	return 1;
}

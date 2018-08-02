#include "TableInsertSort.h"

int TableInsertSort(SLSortList* L)
{
	for(int i=1; i<=L->length; i++)//对指针进行排序 
	{
		int k,j;
		for(k=0, j=L->record[k].next; j&&Left(L->record[j].rc.key, L->record[i].rc.key); k=j, j=L->record[k].next)
			;
		L->record[i].next = j;
		L->record[k].next = i;
	}
	Arrange(L);//对记录进行排序 
	return 1;
}

int Arrange(SLSortList* L)
{
	int p = L->record[0].next;//p指向表头 
	for(int i=1; i<=L->length; i++)
	{
		while(p<i)
			p = L->record[p].next;
		int q = L->record[p].next;//q指向尚未调整的表尾 
		if(p!=i)
		{
			SLNode tmp = L->record[p];//交换记录，使第i个记录到位 
			L->record[p] = L->record[i];
			L->record[i] = tmp;
			
			L->record[i].next = p;//指向被移走的记录，使得以后可以由while循环找回 
		}
		p = q;//p指向尚未调整的表尾，为找第i+1个记录做准备 
	}
	return 1;
}

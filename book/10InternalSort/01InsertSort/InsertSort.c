#include "InsertSort.h"

int InsertSort(SqSortList* L)
{
	for(int i=2; i<=L->length; i++)
	{
		if(Left(L->record[i].key, L->record[i-1].key))//LiС����Ҫ���������ӱ� 
		{
			L->record[0] = L->record[i];//����Ϊ�ڱ� 
			L->record[i] = L->record[i-1];
			int j;
			for(j=i-1; Left(L->record[0].key, L->record[j].key); --j)
				L->record[j+1] = L->record[j];//��¼����
			L->record[j+1] = L->record[0];//���뵽��ȷλ�� 
		}
	}
	return 1;
}

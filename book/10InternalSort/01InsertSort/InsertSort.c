#include "InsertSort.h"

int InsertSort(SqSortList* L)
{
	for(int i=2; i<=L->length; i++)
	{
		if(Left(L->record[i].key, L->record[i-1].key))//Li����ǰһλ��С�������ϴ�С�������У���Ҫ�������ǰ��������ӱ� 
		{
			L->record[0] = L->record[i];//����Ϊ�ڱ� 
			
			int j;
			L->record[i] = L->record[i-1];//�Ƚ����һλ���ƣ������ڱ�����Ϊ����� 
			for(j=i-1; Left(L->record[0].key, L->record[j].key); --j)
				L->record[j+1] = L->record[j];//ֻҪ������Ԫ�رȱ�����Ԫ��С���ͻ�û�ҵ�����������
			L->record[j+1] = L->record[0];//���뵽��ȷλ�� 
		}
	}
	return 1;
}

#include "SelectSort.h"

int SelectSort(SqSortList* L)
{
	for(int i=1; i<L->length; i++)
	{
		int j = SelectMinKey(*L, i);
		if(i!=j)//ѡ����С�ģ��͵�ǰ�������Ľ��� 
		{
			RecordType tmp = L->record[i];
			L->record[i] = L->record[j];
			L->record[j] = tmp;
		}
	}
	return 1;
}

int SelectMinKey(SqSortList L, int i)
{
	int min = i;
	L.record[0] = L.record[i];//��¼i 
	for(int k=i; k<=L.length; k++)
	{
		if(L.record[k].key < L.record[0].key)//���i�����Ԫ���б�iС�ģ�����Ϊ��Сֵ 
		{
			min = k;
			L.record[0] = L.record[k];
		}
	}
	return min;
}

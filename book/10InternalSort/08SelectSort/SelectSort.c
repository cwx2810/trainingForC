#include "SelectSort.h"

int SelectSort(SqSortList* L)
{
	for(int i=1; i<L->length; i++)
	{
		int j = SelectMinKey(*L, i);
		if(i!=j)//选出最小的，和当前遍历到的交换 
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
	L.record[0] = L.record[i];//记录i 
	for(int k=i; k<=L.length; k++)
	{
		if(L.record[k].key < L.record[0].key)//如果i后面的元素有比i小的，令其为最小值 
		{
			min = k;
			L.record[0] = L.record[k];
		}
	}
	return min;
}

#include "HeapSort.h"

int HeapAdjust(SqSortList* L, int s, int m)
{
	RecordType rc = L->record[s];
	for(int j=2*s; j<=m; j++)//沿key较大的孩子节点向下筛选 
	{
		if(j<m && Left(L->record[j].key, L->record[j+1].key))//j是较大的key的下标 
			j++;
		if(!Left(rc.key, L->record[j].key))//如果s比j大，则j应该插入到s上，也就是让小的向下走 
			break;
		L->record[s] = L->record[j];
		s = j;
	}
	L->record[s] = rc;
	return 1;
}

int HeapSort(SqSortList* L)
{
	for(int i=L->length/2; i>0; i--)//建造大顶堆 
		HeapAdjust(L, i, L->length);
	for(int i=L->length; i>1; i--)
	{
		RecordType tmp = L->record[1];//把未经排序的元素放到堆顶，重新调整堆 
		L->record[1] = L->record[i];
		L->record[i] = tmp;
		HeapAdjust(L, 1, i-1);
	}
	return 1;
}

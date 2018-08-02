#include "QuickSort.h"

int Partition(SqSortList* L, int low, int high)
{
	int pivotkey = L->record[low].key;
	L->record[0] = L->record[low];//用哨兵保存住位置，最后放根轴 
	
	while(low<high)
	{
		while(low<high && L->record[high].key>=pivotkey)
			high--;
		L->record[low] = L->record[high];//将比轴小的记录交换到低端
		while(low<high && L->record[low].key<=pivotkey)
			low++;
		L->record[high] = L->record[low];//将比轴大的记录交换到高端 
	} 
	L->record[low] = L->record[0];//根轴到位
	return low;//返回根轴所在位置 
}

int QuickSort(SqSortList* L)
{
	QSort(L, 1, L->length);
}

int QSort(SqSortList* L, int low, int high)
{
	if(low<high)
	{
		int pivot = Partition(L, low, high);
		QSort(L, 1, pivot-1);
		QSort(L, pivot+1, high);
		return 1;
	}
	return 0;
}

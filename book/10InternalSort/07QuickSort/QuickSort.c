#include "QuickSort.h"

int Partition(SqSortList* L, int low, int high)
{
	int pivotkey = L->record[low].key;
	L->record[0] = L->record[low];//���ڱ�����סλ�ã����Ÿ��� 
	
	while(low<high)
	{
		while(low<high && L->record[high].key>=pivotkey)
			high--;
		L->record[low] = L->record[high];//������С�ļ�¼�������Ͷ�
		while(low<high && L->record[low].key<=pivotkey)
			low++;
		L->record[high] = L->record[low];//�������ļ�¼�������߶� 
	} 
	L->record[low] = L->record[0];//���ᵽλ
	return low;//���ظ�������λ�� 
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

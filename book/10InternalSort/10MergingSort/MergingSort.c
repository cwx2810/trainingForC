#include "MergingSort.h"

int Merge(RecordType SR[], RecordType TR[], int start, int mid, int end)
{
	int midstart=mid+1;
	int i;
	for(i=start; start<=mid&&midstart<=end; ++i)//同时遍历前半部分和后半部分 
	{
		if(LeftEqual(SR[start].key, SR[midstart].key))//由小到大的插入TR 
			TR[i] = SR[start++];
		else
			TR[i] = SR[midstart++];
	}
	
	//将剩余部分复制到TR 
	while(start<=mid)
		TR[i++] = SR[start++];
	while(midstart<=end)
		TR[i++] = SR[midstart++];
		
	return 1;
}

int MSort(RecordType SR[], RecordType TR[], int start, int end)
{
	if(start==end)//如果只有一个元素，直接复制过去就行了 
		TR[start] = SR[start];
	else			//如果有多个元素，递归的将其归并为R的前后两部分，再利用上面的函数做最后一次归并 
	{
		int mid = (start+end)/2;
		RecordType R[21];
		MSort(SR, R, start, mid);
		MSort(SR, R, mid+1, end);
		Merge(R, TR, start, mid, end);
	}
	return 1;
}

int MergeSort(SqSortList* L)
{
	MSort(L->record, L->record, 1, L->length);
}

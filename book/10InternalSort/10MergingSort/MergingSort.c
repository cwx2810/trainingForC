#include "MergingSort.h"

int Merge(RecordType SR[], RecordType TR[], int start, int mid, int end)
{
	int midstart=mid+1;
	int i;
	for(i=start; start<=mid&&midstart<=end; ++i)//ͬʱ����ǰ�벿�ֺͺ�벿�� 
	{
		if(LeftEqual(SR[start].key, SR[midstart].key))//��С����Ĳ���TR 
			TR[i] = SR[start++];
		else
			TR[i] = SR[midstart++];
	}
	
	//��ʣ�ಿ�ָ��Ƶ�TR 
	while(start<=mid)
		TR[i++] = SR[start++];
	while(midstart<=end)
		TR[i++] = SR[midstart++];
		
	return 1;
}

int MSort(RecordType SR[], RecordType TR[], int start, int end)
{
	if(start==end)//���ֻ��һ��Ԫ�أ�ֱ�Ӹ��ƹ�ȥ������ 
		TR[start] = SR[start];
	else			//����ж��Ԫ�أ��ݹ�Ľ���鲢ΪR��ǰ�������֣�����������ĺ��������һ�ι鲢 
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

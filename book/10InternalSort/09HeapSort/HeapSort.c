#include "HeapSort.h"

int HeapAdjust(SqSortList* L, int s, int m)
{
	RecordType rc = L->record[s];
	for(int j=2*s; j<=m; j++)//��key�ϴ�ĺ��ӽڵ�����ɸѡ 
	{
		if(j<m && Left(L->record[j].key, L->record[j+1].key))//j�ǽϴ��key���±� 
			j++;
		if(!Left(rc.key, L->record[j].key))//���s��j����jӦ�ò��뵽s�ϣ�Ҳ������С�������� 
			break;
		L->record[s] = L->record[j];
		s = j;
	}
	L->record[s] = rc;
	return 1;
}

int HeapSort(SqSortList* L)
{
	for(int i=L->length/2; i>0; i--)//����󶥶� 
		HeapAdjust(L, i, L->length);
	for(int i=L->length; i>1; i--)
	{
		RecordType tmp = L->record[1];//��δ�������Ԫ�طŵ��Ѷ������µ����� 
		L->record[1] = L->record[i];
		L->record[i] = tmp;
		HeapAdjust(L, 1, i-1);
	}
	return 1;
}

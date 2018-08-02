#include "BinaryInsertSort.h"

int BinaryInsertSort(SqSortList* L)
{
	for(int i=2; i<=L->length; i++)
	{
		L->record[0] = L->record[i];//�ݴ�
		int low = 1;
		int high = i-1;
		while(low<=high)//���ֲ��Ҳ���λ�� 
		{
			int mid = (low+high)/2;
			if(Left(L->record[0].key, L->record[mid].key))//������ڵͰ��� 
				high = mid-1;
			else
				low = mid+1;
		} 
		
		for(int j=i-1; j>=high+1; --j)//��¼���ƣ��ճ�����λ�� 
			L->record[j+1] = L->record[j];
		L->record[high+1] = L->record[0];//���� 
	}
	return 1;
}

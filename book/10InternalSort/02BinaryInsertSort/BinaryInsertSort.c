#include "BinaryInsertSort.h"

int BinaryInsertSort(SqSortList* L)
{
	for(int i=2; i<=L->length; i++)
	{
		L->record[0] = L->record[i];//暂存
		int low = 1;
		int high = i-1;
		while(low<=high)//二分查找插入位置 
		{
			int mid = (low+high)/2;
			if(Left(L->record[0].key, L->record[mid].key))//插入点在低半区 
				high = mid-1;
			else
				low = mid+1;
		} 
		
		for(int j=i-1; j>=high+1; --j)//记录后移，空出插入位置 
			L->record[j+1] = L->record[j];
		L->record[high+1] = L->record[0];//插入 
	}
	return 1;
}

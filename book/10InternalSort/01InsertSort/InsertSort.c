#include "InsertSort.h"

int InsertSort(SqSortList* L)
{
	for(int i=2; i<=L->length; i++)
	{
		if(Left(L->record[i].key, L->record[i-1].key))//Li比他前一位还小，不符合从小到大排列，需要将其插入前面的有序子表 
		{
			L->record[0] = L->record[i];//复制为哨兵 
			
			int j;
			L->record[i] = L->record[i-1];//先将最后一位后移，复制哨兵就是为了这个 
			for(j=i-1; Left(L->record[0].key, L->record[j].key); --j)
				L->record[j+1] = L->record[j];//只要待插入元素比遍历的元素小，就还没找到，继续后移
			L->record[j+1] = L->record[0];//插入到正确位置 
		}
	}
	return 1;
}

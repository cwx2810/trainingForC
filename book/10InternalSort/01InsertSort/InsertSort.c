#include "InsertSort.h"

int InsertSort(SqSortList* L)
{
	for(int i=2; i<=L->length; i++)
	{
		if(Left(L->record[i].key, L->record[i-1].key))//Li小，需要插入有序子表 
		{
			L->record[0] = L->record[i];//复制为哨兵 
			L->record[i] = L->record[i-1];
			int j;
			for(j=i-1; Left(L->record[0].key, L->record[j].key); --j)
				L->record[j+1] = L->record[j];//记录后移
			L->record[j+1] = L->record[0];//插入到正确位置 
		}
	}
	return 1;
}

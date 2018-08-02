#include "shellSort.h"

int ShellInsert(SqSortList* L, int dk)
{
	for(int i=dk+1; i<=L->length; i++)//dk为前后记录位置的增量 
	{
		if(Left(L->record[i].key, L->record[i-dk].key))//第i个比前面的有序子表小，则可以插入 
		{
			L->record[0] = L->record[i];//暂存在0号位置
			
			int j;
			for(j=i-dk; j>0&&Left(L->record[0].key, L->record[j].key); j-=dk)
				L->record[j+dk] = L->record[j];//记录后移，同时寻找插入位置
			L->record[j+dk] = L->record[0];//插入 
		}
	}
	return 1;
}

int ShellSort(SqSortList* L, int dlta[], int t)
{
	for(int k=0; k<t; k++)
		ShellInsert(L, dlta[k]);
}

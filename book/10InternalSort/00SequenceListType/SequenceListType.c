#include "SequenceListType.h"

int CreateSortList(FILE* fp, SqSortList* L)
{
	Scanf(fp, "%d", &((*L).length));//读取顺序表元素个数 
	if((*L).length > 20)
		return 0;
	for(int i=1; i<=(*L).length; i++)//读取顺序表元素 
		Scanf(fp, "%d", &((*L).record[i].key));
	return 1;
}

int TraverseList(SqSortList L, void(Visit)(int))
{
	for(int i=1; i<=L.length; i++)
		Visit(L.record[i].key);
	printf("\n");
	return 1;
}


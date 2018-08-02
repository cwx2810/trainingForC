#include "StaticLinkedListType.h"

int CreateSortList(FILE* fp, SLSortList* L)
{
	Scanf(fp, "%d", &((*L).length));//读取元素个数 
	if((*L).length > 20)
		return 0;
	
	L->record[0].rc.key = INT_MAX;
	L->record[0].next = 0;
	
	for(int i=1; i<=(*L).length; i++)//读取元素 
	{
		Scanf(fp, "%d", &((*L).record[i].rc.key));
		L->record[i].next = -1;
	}
		
	return 1;
}

int TraverseList(SLSortList L, void(Visit)(int))
{
	for(int i=1; i<=L.length; i++)
		Visit(L.record[i].rc.key);
	printf("\n");
	return 1;
}


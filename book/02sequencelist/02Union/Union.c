#include "Union.h"

void Union(SqList *La, SqList Lb)
{
	int e;
	for(int i=1; i<=ListLength_Sq(Lb); i++)
	{
		GetElem_Sq(Lb, i, &e);
		if(!LocateElem_Sq(*La, e, Equal))
			ListInsert_Sq(La, ListLength_Sq(*La) + 1, e);
	}
}

int Equal(int e1, int e2)
{
	return e1==e2 ? 1 : 0;
}

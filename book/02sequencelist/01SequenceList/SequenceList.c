#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

int InitList_Sq(SqList *L)
{
	(*L).elem = (int*)malloc(100*sizeof(int));
	if(!(*L).elem)
		return 0;
	(*L).length = 0;
	(*L).listsize = 100;
	return 1;
}

int ClearList_Sq(SqList *L)
{
	(*L).length = 0;
	return 1;
}

int DestroyList_Sq(SqList *L)
{
	free((*L).elem);
	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
	return 1;
}

int ListEmpty_Sq(SqList L)
{
	return L.length == 0 ? 1 : 0;
}

int ListLength_Sq(SqList L)
{
	return L.length;
}

int GetElem_Sq(SqList L, int i, int *e)
{
	if(i<1 || i>L.length)
		return 0;
	*e = L.elem[i-1];
	return 1;
}

int LocateElem_Sq(SqList L, int e, int(Compare)(int ,int))
{
	int i = 1;
	while (i<=L.length && !Compare(e, L.elem[i-1]))
		++i;
	if(i<=L.length)
		return i;
	return 0;
}

int PriorElem_Sq(SqList L, int cur_e, int *pre_e)
{
	int i = 2;
	while(i<=L.length && cur_e!=L.elem[i-1])
		++i;
	if(i<=L.length)
		*pre_e = L.elem[i-2];
		return 1;
	return 0;
}

int NextElem_Sq(SqList L, int cur_e, int *next_e)
{
	int i = 1;
	while(i<L.length && cur_e!=L.elem[i-1])
		++i;
	if(i<L.length)
		*next_e = L.elem[i];
		return 1;
	return 0;	
}

int ListInsert_Sq(SqList *L, int i, int e)
{
	int *newbase;
	if(i<1 || i>(*L).length+1)
		return 0;
	if((*L).length>=(*L).listsize)
	{
		newbase = (int*)realloc((*L).elem, ((*L).listsize+10)*sizeof(int));
		if (!newbase)
			return 0;
		(*L).elem = newbase;
		(*L).listsize+=10;
	}	
	for(int j=(*L).length; j>=i; --j)
		(*L).elem[j]=(*L).elem[j-1];
	(*L).elem[i-1] = e;
	(*L).length++;
	return 1;
}

int ListDelete_Sq(SqList *L, int i, int *e)
{
	if(i<1 || i>(*L).length)
		return 0;
	*e = (*L).elem[i-1];
	for(int j=i+1; j<=(*L).length; ++j)
		(*L).elem[j-2] = (*L).elem[j-1];
	(*L).length--;
	return 1;
}

int ListTraverse_Sq(SqList L, void(Visit)(int))
{
	for(int i=1; i<=L.length; i++)
		Visit(L.elem[i-1]);
	return 1;
}

#endif

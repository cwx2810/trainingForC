#include "MergeSqList.h"

void MergeSqList(SqList La, SqList Lb, SqList *Lc)
{
	int i=1;
	int j=1;
	int k=1;//分别代表三个顺序表中第几个元素 
	int a,b;
	InitList_Sq(Lc);
	while(i<=ListLength_Sq(La) && j<=ListLength_Sq(Lb))//顺序表a和b均未扫描完 
	{
		GetElem_Sq(La, i, &a);
		GetElem_Sq(Lb, j, &b);
		if(a<=b)
		{
			ListInsert_Sq(Lc, k, a);
			i++;
		}
		else
		{
			ListInsert_Sq(Lc, k, b);
			j++;
		}
		k++;
	}
	while(i<=ListLength_Sq(La))//还剩a未扫描完 
	{
		GetElem_Sq(La, i, &a);
		ListInsert_Sq(Lc, k, a);
		i++;
		k++;
	}
	while(j<=ListLength_Sq(Lb))//还剩b未扫描完 
	{
		GetElem_Sq(Lb, j, &b);
		ListInsert_Sq(Lc, k, b);
		j++;
		k++;
	}
}

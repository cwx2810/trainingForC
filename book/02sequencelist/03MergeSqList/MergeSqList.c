#include "MergeSqList.h"

void MergeSqList(SqList La, SqList Lb, SqList *Lc)
{
	int i=1;
	int j=1;
	int k=1;//�ֱ��������˳����еڼ���Ԫ�� 
	int a,b;
	InitList_Sq(Lc);
	while(i<=ListLength_Sq(La) && j<=ListLength_Sq(Lb))//˳���a��b��δɨ���� 
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
	while(i<=ListLength_Sq(La))//��ʣaδɨ���� 
	{
		GetElem_Sq(La, i, &a);
		ListInsert_Sq(Lc, k, a);
		i++;
		k++;
	}
	while(j<=ListLength_Sq(Lb))//��ʣbδɨ���� 
	{
		GetElem_Sq(Lb, j, &b);
		ListInsert_Sq(Lc, k, b);
		j++;
		k++;
	}
}

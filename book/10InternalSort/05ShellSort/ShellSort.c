#include "shellSort.h"

int ShellInsert(SqSortList* L, int dk)
{
	for(int i=dk+1; i<=L->length; i++)//dkΪǰ���¼λ�õ����� 
	{
		if(Left(L->record[i].key, L->record[i-dk].key))//��i����ǰ��������ӱ�С������Բ��� 
		{
			L->record[0] = L->record[i];//�ݴ���0��λ��
			
			int j;
			for(j=i-dk; j>0&&Left(L->record[0].key, L->record[j].key); j-=dk)
				L->record[j+dk] = L->record[j];//��¼���ƣ�ͬʱѰ�Ҳ���λ��
			L->record[j+dk] = L->record[0];//���� 
		}
	}
	return 1;
}

int ShellSort(SqSortList* L, int dlta[], int t)
{
	for(int k=0; k<t; k++)
		ShellInsert(L, dlta[k]);
}

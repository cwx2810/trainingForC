#include "AddressSort.h"

int AddressSort(SqSortList* L)
{
	int adr[21];
	for(int i=1; i<=L->length; i++)
		adr[i] = i;
		
	for(int i=L->length; i>=2; i--)
	{
		int tag = FALSE;
		for(int j=1; j<=i-1; j++)
		{
			if(Left(L->record[adr[j+1]].key, L->record[adr[j]].key))//����һ����ַԪ�ر�ǰһ����ַԪ��С���򽻻���ַ 
			{
				int tmp = adr[j+1];
				adr[j+1] = adr[j];
				adr[j] = tmp;
				
				tag = TRUE;
			}
		}
		if(!tag)
			break;
	}
	
	ReArrange(L, adr);
	return 1;
}

int ReArrange(SqSortList* L, int adr[])//û���� 
{
	for(int i=1; i<=L->length; i++)
	{
		if(adr[i]!=i)//�����ַ���������� 
		{
			int j=i;//��¼�µ�i��λ�õ�Ԫ�� 
			L->record[0] = L->record[i];
			
			while(adr[j]!=i)
			{
				int k = adr[j];
				L->record[j] = L->record[k];
				adr[j] = j;
				j = k;
			}
			
			L->record[j] = L->record[0];
			adr[j] = j;
		}
	}
	return 1;
}


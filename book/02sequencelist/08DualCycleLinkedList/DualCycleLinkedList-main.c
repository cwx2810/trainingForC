#include <stdio.h>
#include "DualCycleLinkedList.c"

void PrintElem(int e);
int CmpCreater(int e, int data);

int main(int argc, char **argv)
{
	DNode* L;
	int i;
	int e;
	
	printf("InitList����...\n");
	{
		printf("��ʼ������\n");
		InitList_DL(&L);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListEmpty����...\n");
	{
		ListEmpty_DL(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListInsert����...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("�������%d��λ�Ӳ���%d\n",i,2*i);
			ListInsert_DL(L,i,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("�Լ����...\n");
	{
		
		printf("�������7��λ�Ӳ���%d\n",100);
		ListInsert_DL(L,7,100);
		ListTraverse_DL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListTraverse����...\n");
	{
		ListTraverse_DL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListLength����...\n");
	{
		printf("L�ĳ���Ϊ%d",ListLength_DL(L));
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListDelete����...\n");
	{
		ListDelete_DL(L,6,&e);
		printf("ɾ��L�е�6��Ԫ��%d",e);
		printf("��L��Ԫ�ػ�ʣ:");
		ListTraverse_DL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetElem����...\n");
	{
		GetElem_DL(L,4,&e);
		printf("L�е�4��Ԫ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("LocateElem����...\n");
	{
		printf("L�е�һ������7��Ԫ�ص�λ��Ϊ%d",LocateElem_DL(L,7,CmpCreater));
		printf("\n\n");
	}
	PressEnter;
	
	printf("PriorElem����...\n");
	{
		PriorElem_DL(L,6,&e);
		printf("Ԫ��6��ǰ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("NextElem����...\n");
	{
		NextElem_DL(L,6,&e);
		printf("Ԫ��6�ĺ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearList����...\n");
	{
		ClearList_DL(L);
		ListEmpty_DL(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyEmpty����...\n");
	{
		DestroyList_DL(&L);
		L ? printf("L����") : printf("L������");
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(int e)
{
	printf("%d ",e);
}

int CmpCreater(int e,int data)
{
	return data>e?1:0;
}


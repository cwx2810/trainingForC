#include <stdio.h>
#include "StaticLinkedList.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	int L;
	int i;
	int e;
	
	printf("InitSpace����...\n");
	{
		printf("��ʼ����̬�ڴ�ռ�\n");
		InitSpace();
		printf("\n\n");
	}
	PressEnter;
	
	printf("Malloc��InitList����...\n");
	{
		printf("��ʼ����̬������Malloc����ռ�\n");
		InitList_SL(&L);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListEmpty����...\n");
	{
		ListEmpty_SL(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListInsert����...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("�������%d��λ�Ӳ���%d\n",i,2*i);
			ListInsert_SL(L,i,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListTraverse����...\n");
	{
		ListTraverse_SL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListLength����...\n");
	{
		printf("L�ĳ���Ϊ%d",ListLength_SL(L));
		printf("\n\n");
	}
	PressEnter;
	
	printf("Free��ListDelete����...\n");
	{
		ListDelete_SL(L,6,&e);
		printf("ɾ��L�е�6��Ԫ��%d����Free�ͷſռ�",e);
		printf("��L��Ԫ�ػ�ʣ:");
		ListTraverse_SL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetElem����...\n");
	{
		GetElem_SL(L,4,&e);
		printf("L�е�4��Ԫ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("LocateElem����...\n");
	{
		printf("8��L�е�λ��Ϊ%d",LocateElem_SL(L,8));
		printf("\n\n");
	}
	PressEnter;
	
	printf("PriorElem����...\n");
	{
		PriorElem_SL(L,6,&e);
		printf("Ԫ��6��ǰ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("NextElem����...\n");
	{
		NextElem_SL(L,6,&e);
		printf("Ԫ��6�ĺ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearList����...\n");
	{
		ClearList_SL(L);
		ListEmpty_SL(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyEmpty����...\n");
	{
		DestroyList_SL(&L);
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



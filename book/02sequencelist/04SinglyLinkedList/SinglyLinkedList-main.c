/*���Ա�����ļ�*/

#include <stdio.h>
#include "SinglyLinkedList.c"

void PrintElem(int e);
int CmpCreater(int e, int data);

int main(int argc, char **argv)
{
	LNode* L;
	int i;
	int e;
	
	printf("InitList����...\n");
	{
		printf("��ʼ������\n");
		InitList_L(&L);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListEmpty����...\n");
	{
		ListEmpty_L(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListInsert����...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("�������%d��λ�Ӳ���%d\n",i,2*i);
			ListInsert_L(L,i,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListTraverse����...\n");
	{
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListLength����...\n");
	{
		printf("L�ĳ���Ϊ%d",ListLength_L(L));
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListDelete����...\n");
	{
		ListDelete_L(L,6,&e);
		printf("ɾ��L�е�6��Ԫ��%d",e);
		printf("��L��Ԫ�ػ�ʣ:");
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetElem����...\n");
	{
		GetElem_L(L,4,&e);
		printf("L�е�4��Ԫ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("LocateElem����...\n");
	{
		printf("L�е�һ������7��Ԫ�ص�λ��Ϊ%d",LocateElem_L(L,7,CmpCreater));
		printf("\n\n");
	}
	PressEnter;
	
	printf("PriorElem����...\n");
	{
		PriorElem_L(L,6,&e);
		printf("Ԫ��6��ǰ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("NextElem����...\n");
	{
		NextElem_L(L,6,&e);
		printf("Ԫ��6�ĺ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearList����...\n");
	{
		ClearList_L(L);
		ListEmpty_L(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyEmpty����...\n");
	{
		DestroyList_L(&L);
		L ? printf("L����") : printf("L������");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ͷ�巨����...\n");
	{
		FILE *fp;
		LNode* L;
		printf("L = ");
		fp = fopen("TestData_HL.txt", "r");
		CreateList_HL(fp, &L, 5);
		fclose(fp);
		ListTraverse_L(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("β�巨����...\n");
	{
		FILE *fp;
		LNode* L;
		printf("L = ");
		fp = fopen("TestData_TL.txt", "r");
		CreateList_TL(fp, &L, 5);
		fclose(fp);
		ListTraverse_L(L, PrintElem);
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

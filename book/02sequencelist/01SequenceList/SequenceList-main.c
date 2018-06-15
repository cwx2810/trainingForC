/*���Ա�����ļ�*/

#include <stdio.h>
#include "SequenceList.c"

void PrintElem(LElemType_Sq e);
Status CmpCreater(LElemType_Sq e, LElemType_Sq data);

int main(int argc, char **argv)
{
	SqList L;
	int i;
	LElemType_Sq e;
	
	printf("InitList����...\n");
	{
		printf("��ʼ��˳���\n");
		InitList_Sq(&L);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListEmpty����...\n");
	{
		ListEmpty_Sq(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListInsert����...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("��˳����%d��λ�Ӳ���%d\n",i,2*i);
			ListInsert_Sq(&L,i,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListTraverse����...\n");
	{
		ListTraverse_Sq(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListLength����...\n");
	{
		printf("L�ĳ���Ϊ%d",ListLength_Sq(L));
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListDelete����...\n");
	{
		ListDelete_Sq(&L,6,&e);
		printf("ɾ��L�е�6��Ԫ��%d",e);
		printf("��L��Ԫ�ػ�ʣ:");
		ListTraverse_Sq(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetElem����...\n");
	{
		GetElem_Sq(L,4,&e);
		printf("L�е�4��Ԫ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("LocateElem����...\n");
	{
		printf("L�е�һ������7��Ԫ�ص�λ��Ϊ%d",LocateElem_Sq(L,7,CmpCreater));
		printf("\n\n");
	}
	PressEnter;
	
	printf("PriorElem����...\n");
	{
		PriorElem_Sq(L,6,&e);
		printf("Ԫ��6��ǰ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("NextElem����...\n");
	{
		NextElem_Sq(L,6,&e);
		printf("Ԫ��6�ĺ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearList����...\n");
	{
		ClearList_Sq(&L);
		ListEmpty_Sq(L) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyEmpty����...\n");
	{
		DestroyList_Sq(&L);
		L.elem ? printf("L����") : printf("L������");
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ",e);
}

Status CmpCreater(LElemType_Sq e,LElemType_Sq data)
{
	return data>e?TRUE:FALSE;
}

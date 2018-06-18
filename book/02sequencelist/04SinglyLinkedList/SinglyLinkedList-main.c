/*线性表测试文件*/

#include <stdio.h>
#include "SinglyLinkedList.c"

void PrintElem(int e);
int CmpCreater(int e, int data);

int main(int argc, char **argv)
{
	LNode* L;
	int i;
	int e;
	
	printf("InitList测试...\n");
	{
		printf("初始化链表\n");
		InitList_L(&L);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListEmpty测试...\n");
	{
		ListEmpty_L(L) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListInsert测试...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("在链表第%d个位子插入%d\n",i,2*i);
			ListInsert_L(L,i,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListTraverse测试...\n");
	{
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListLength测试...\n");
	{
		printf("L的长度为%d",ListLength_L(L));
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListDelete测试...\n");
	{
		ListDelete_L(L,6,&e);
		printf("删除L中第6个元素%d",e);
		printf("，L中元素还剩:");
		ListTraverse_L(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetElem测试...\n");
	{
		GetElem_L(L,4,&e);
		printf("L中第4个元素为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("LocateElem测试...\n");
	{
		printf("L中第一个大于7的元素的位子为%d",LocateElem_L(L,7,CmpCreater));
		printf("\n\n");
	}
	PressEnter;
	
	printf("PriorElem测试...\n");
	{
		PriorElem_L(L,6,&e);
		printf("元素6的前驱为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("NextElem测试...\n");
	{
		NextElem_L(L,6,&e);
		printf("元素6的后继为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearList测试...\n");
	{
		ClearList_L(L);
		ListEmpty_L(L) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyEmpty测试...\n");
	{
		DestroyList_L(&L);
		L ? printf("L存在") : printf("L不存在");
		printf("\n\n");
	}
	PressEnter;
	
	printf("头插法测试...\n");
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
	
	printf("尾插法测试...\n");
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

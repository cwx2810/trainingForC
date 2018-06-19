#include <stdio.h>
#include "StaticLinkedList.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	int L;
	int i;
	int e;
	
	printf("InitSpace测试...\n");
	{
		printf("初始化动态内存空间\n");
		InitSpace();
		printf("\n\n");
	}
	PressEnter;
	
	printf("Malloc、InitList测试...\n");
	{
		printf("初始化静态链表，用Malloc申请空间\n");
		InitList_SL(&L);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListEmpty测试...\n");
	{
		ListEmpty_SL(L) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListInsert测试...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("在链表第%d个位子插入%d\n",i,2*i);
			ListInsert_SL(L,i,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListTraverse测试...\n");
	{
		ListTraverse_SL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListLength测试...\n");
	{
		printf("L的长度为%d",ListLength_SL(L));
		printf("\n\n");
	}
	PressEnter;
	
	printf("Free、ListDelete测试...\n");
	{
		ListDelete_SL(L,6,&e);
		printf("删除L中第6个元素%d，用Free释放空间",e);
		printf("，L中元素还剩:");
		ListTraverse_SL(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetElem测试...\n");
	{
		GetElem_SL(L,4,&e);
		printf("L中第4个元素为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("LocateElem测试...\n");
	{
		printf("8在L中的位子为%d",LocateElem_SL(L,8));
		printf("\n\n");
	}
	PressEnter;
	
	printf("PriorElem测试...\n");
	{
		PriorElem_SL(L,6,&e);
		printf("元素6的前驱为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("NextElem测试...\n");
	{
		NextElem_SL(L,6,&e);
		printf("元素6的后继为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearList测试...\n");
	{
		ClearList_SL(L);
		ListEmpty_SL(L) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyEmpty测试...\n");
	{
		DestroyList_SL(&L);
		L ? printf("L存在") : printf("L不存在");
		printf("\n\n");
	}
	PressEnter;
	


	
	return 0;
}

void PrintElem(int e)
{
	printf("%d ",e);
}



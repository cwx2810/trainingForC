/*线性表测试文件*/

#include <stdio.h>
#include "SequenceList.c"

void PrintElem(LElemType_Sq e);
Status CmpCreater(LElemType_Sq e, LElemType_Sq data);

int main(int argc, char **argv)
{
	SqList L;
	int i;
	LElemType_Sq e;
	
	printf("InitList测试...\n");
	{
		printf("初始化顺序表\n");
		InitList_Sq(&L);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListEmpty测试...\n");
	{
		ListEmpty_Sq(L) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListInsert测试...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("在顺序表第%d个位子插入%d\n",i,2*i);
			ListInsert_Sq(&L,i,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListTraverse测试...\n");
	{
		ListTraverse_Sq(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListLength测试...\n");
	{
		printf("L的长度为%d",ListLength_Sq(L));
		printf("\n\n");
	}
	PressEnter;
	
	printf("ListDelete测试...\n");
	{
		ListDelete_Sq(&L,6,&e);
		printf("删除L中第6个元素%d",e);
		printf("，L中元素还剩:");
		ListTraverse_Sq(L,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetElem测试...\n");
	{
		GetElem_Sq(L,4,&e);
		printf("L中第4个元素为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("LocateElem测试...\n");
	{
		printf("L中第一个大于7的元素的位子为%d",LocateElem_Sq(L,7,CmpCreater));
		printf("\n\n");
	}
	PressEnter;
	
	printf("PriorElem测试...\n");
	{
		PriorElem_Sq(L,6,&e);
		printf("元素6的前驱为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("NextElem测试...\n");
	{
		NextElem_Sq(L,6,&e);
		printf("元素6的后继为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearList测试...\n");
	{
		ClearList_Sq(&L);
		ListEmpty_Sq(L) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyEmpty测试...\n");
	{
		DestroyList_Sq(&L);
		L.elem ? printf("L存在") : printf("L不存在");
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

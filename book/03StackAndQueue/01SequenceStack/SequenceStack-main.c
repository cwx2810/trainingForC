#include "SequenceStack.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	SqStack S;
	int e;
	
	printf("InitStack测试...\n");
	{
		printf("初始化顺序栈\n");
		InitStack_Sq(&S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StackEmpty测试...\n");
	{
		StackEmpty_Sq(S) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("压栈测试...\n");
	{
		for(int i=1;i<=6;i++)
		{
			printf("在顺序栈第%d个位子压入%d\n",i,2*i);
			Push_Sq(&S,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("StackTraverse测试...\n");
	{
		StackTraverse_Sq(S,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StackLength测试...\n");
	{
		printf("S的长度为%d",StackLength_Sq(S));
		printf("\n\n");
	}
	PressEnter;
	
	printf("弹出测试...\n");
	{
		Pop_Sq(&S,&e);
		printf("弹出S中栈顶元素%d",e);
		printf("，S中元素还剩:");
		StackTraverse_Sq(S,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetTop测试...\n");
	{
		GetTop_Sq(S,&e);
		printf("S中栈顶元素为%d",e);
		printf("\n\n");
	}
	PressEnter;


	
	printf("ClearStack测试...\n");
	{
		ClearStack_Sq(&S);
		StackEmpty_Sq(S) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyStack测试...\n");
	{
		DestroyStack_Sq(&S);
		S.base && S.top ? printf("S存在") : printf("S不存在");
		printf("\n\n");
	}
	PressEnter;
	
	
	return 0;
}

void PrintElem(int e)
{
	printf("%d ", e);
}

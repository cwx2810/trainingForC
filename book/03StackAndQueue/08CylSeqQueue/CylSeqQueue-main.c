#include "CylSeqQueue.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	SqQueue Q;
	int i;
	int e;
	
	printf("InitQueue测试...\n");
	{
		printf("初始化队列\n");
		InitQueue_Sq(&Q);
		printf("\n\n");
	}
	PressEnter;
	
	printf("QueueEmpty测试...\n");
	{
		QueueEmpty_Sq(Q) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("EnQueue测试...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("在队列第%d个位子插入%d\n",i,2*i);
			EnQueue_Sq(&Q, 2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("QueueTraverse测试...\n");
	{
		QueueTraverse_Sq(Q,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("QueueLength测试...\n");
	{
		printf("Q的长度为%d",QueueLength_Sq(Q));
		printf("\n\n");
	}
	PressEnter;
	
	printf("DeQueue测试...\n");
	{
		DeQueue_Sq(&Q, &e);
		printf("删除Q中队头元素%d",e);
		printf("，Q中元素还剩:");
		QueueTraverse_Sq(Q,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetHead测试...\n");
	{
		GetHead_Sq(Q, &e);
		printf("Q中队头元素为%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearQueue测试...\n");
	{
		ClearQueue_Sq(&Q);
		QueueEmpty_Sq(Q) ? printf("为空\n") : printf("不为空\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyQueue测试...\n");
	{
		DestroyQueue_Sq(&Q);
		Q.front!=NULL && Q.rear!=NULL ? printf("Q存在") : printf("Q不存在");
		printf("\n\n");
	}
	PressEnter;
	return 0;
}

void PrintElem(int e)
{
	printf("%d ", e);
}

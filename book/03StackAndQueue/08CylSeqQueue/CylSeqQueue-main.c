#include "CylSeqQueue.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	SqQueue Q;
	int i;
	int e;
	
	printf("InitQueue����...\n");
	{
		printf("��ʼ������\n");
		InitQueue_Sq(&Q);
		printf("\n\n");
	}
	PressEnter;
	
	printf("QueueEmpty����...\n");
	{
		QueueEmpty_Sq(Q) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("EnQueue����...\n");
	{
		for(i=1;i<=6;i++)
		{
			printf("�ڶ��е�%d��λ�Ӳ���%d\n",i,2*i);
			EnQueue_Sq(&Q, 2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("QueueTraverse����...\n");
	{
		QueueTraverse_Sq(Q,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("QueueLength����...\n");
	{
		printf("Q�ĳ���Ϊ%d",QueueLength_Sq(Q));
		printf("\n\n");
	}
	PressEnter;
	
	printf("DeQueue����...\n");
	{
		DeQueue_Sq(&Q, &e);
		printf("ɾ��Q�ж�ͷԪ��%d",e);
		printf("��Q��Ԫ�ػ�ʣ:");
		QueueTraverse_Sq(Q,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetHead����...\n");
	{
		GetHead_Sq(Q, &e);
		printf("Q�ж�ͷԪ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;
	
	printf("ClearQueue����...\n");
	{
		ClearQueue_Sq(&Q);
		QueueEmpty_Sq(Q) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyQueue����...\n");
	{
		DestroyQueue_Sq(&Q);
		Q.front!=NULL && Q.rear!=NULL ? printf("Q����") : printf("Q������");
		printf("\n\n");
	}
	PressEnter;
	return 0;
}

void PrintElem(int e)
{
	printf("%d ", e);
}

#include "SequenceStack.c"

void PrintElem(int e);

int main(int argc, char **argv)
{
	SqStack S;
	int e;
	
	printf("InitStack����...\n");
	{
		printf("��ʼ��˳��ջ\n");
		InitStack_Sq(&S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StackEmpty����...\n");
	{
		StackEmpty_Sq(S) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("ѹջ����...\n");
	{
		for(int i=1;i<=6;i++)
		{
			printf("��˳��ջ��%d��λ��ѹ��%d\n",i,2*i);
			Push_Sq(&S,2*i);
		}
		printf("\n\n");
	}
	PressEnter;
	
	printf("StackTraverse����...\n");
	{
		StackTraverse_Sq(S,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("StackLength����...\n");
	{
		printf("S�ĳ���Ϊ%d",StackLength_Sq(S));
		printf("\n\n");
	}
	PressEnter;
	
	printf("��������...\n");
	{
		Pop_Sq(&S,&e);
		printf("����S��ջ��Ԫ��%d",e);
		printf("��S��Ԫ�ػ�ʣ:");
		StackTraverse_Sq(S,PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("GetTop����...\n");
	{
		GetTop_Sq(S,&e);
		printf("S��ջ��Ԫ��Ϊ%d",e);
		printf("\n\n");
	}
	PressEnter;


	
	printf("ClearStack����...\n");
	{
		ClearStack_Sq(&S);
		StackEmpty_Sq(S) ? printf("Ϊ��\n") : printf("��Ϊ��\n");
		printf("\n\n");
	}
	PressEnter;
	
	printf("DestroyStack����...\n");
	{
		DestroyStack_Sq(&S);
		S.base && S.top ? printf("S����") : printf("S������");
		printf("\n\n");
	}
	PressEnter;
	
	
	return 0;
}

void PrintElem(int e)
{
	printf("%d ", e);
}

#include "SequenceArray.c"

int main(int argc, char **argv)
{
	Array A;
	
	printf("InitArray���ԣ��Զ�ά����Ϊ��...\n");
	{
		printf("��ʼ��һ��2��3�еĶ�ά����A\n");
		InitArray(&A, 2, 2, 3);
		printf("\n");
	}
	PressEnter;
	
	printf("AssignArray����...\n");
	{
		int e = 1;
		for(int i=0; i<A.bounds[0]; i++)
		{
			for(int j=0; j<A.bounds[1]; j++)
			{
				printf("��ֵ��A[%d][%d] = %d\n", i, j, e);
				AssignArray(&A, e, i, j);
				e++;
			}
		}
		printf("\n");
	}
	PressEnter;
	
	printf("AssignPrint����...\n");
	{
		printf("A = ");
		ArrayPrint(A);
		printf("\n");
	}
	PressEnter;
	
	printf("LocateArray,ValueArray����...\n");
	{
		int e;
		printf("��ȡ�±�Ϊ(1,1)��Ԫ�ص�ֵ\n");
		ValueArray(A, &e, 1, 1);
		printf("A[1][1] = %d\n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("DestroyArray����...\n");
	{
		DestroyArray(&A);
		A.dim ? printf("����\n") : printf("������\n");
		printf("\n");
	}
	PressEnter;
	
	return 0;
}
